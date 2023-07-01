#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <typeinfo>
#include <cctype>
#include <getopt.h>


const int NUMOFNUMBER = 10;
const int NUMOFALPHABET = 26;

/**
 * @enum SIGN
 * 暗号化するのが復号化するのか
 */
enum class SIGN : int
{
	ENCRYPTION = 1,
	DECRYPTION = -1,
};

/**
 * @enum ALPHABETOFFSET
 */
enum class ALPHABETOFFSET : int
{
	ENCRYPTION = 0,
	DECRYPTION = NUMOFALPHABET,
};

/**
 * @enum NUMBEROFFSET
 */
enum class NUMBEROFFSET : int
{
	ENCRYPTION = 0,
	DECRYPTION = NUMOFNUMBER,
};

/**
 * @enum CONVERSIONMETHOD
 */
enum class CONVERSIONMETHOD : int
{
	SHIFT = 0, //- 難読化手法->シフト
	ALLX = 1,  //- 難読化手法->黒塗り
};


/**
 * パラメータ処理を司るクラス
 * シングルトンとして実装する
 */
class Params
{
private:
	Params()  = default;
	~Params() = default;
	bool m_encryption = true;
	CONVERSIONMETHOD m_method = CONVERSIONMETHOD::SHIFT;
	int m_offset_a = 1;
	int m_offset_A = 1;
	int m_seed     = 1789;
	std::string m_fin  = "input.txt";
	std::string m_fout = "output.txt";

public:
	//- シングルトンとするためコピーコンストラクタは削除する
	Params(const Params& obj) = delete;
	Params& operator=(const Params& obj) = delete;

	//- シングルトンとするため、ムーブコンストラクタは削除する
	Params(Params&& obj) = delete;
	Params& operator=(Params&& obj) = delete;

	static Params& getInstance();

	//- @brief コマンドラインからパラメータを読み込むメソッド
	void loadParamsFromCommandLine(int argc, char** argv);
	void show() const;
	void printUsageAndExit() const;

	CONVERSIONMETHOD getMethod() const;
	int getOffseta() const;
	int getOffsetA() const;
	// int getOffsetn() const;
	int getSeed() const;
	bool getEncryption() const;

	std::string getInputFile() const;
	std::string getOutputFile() const;
};

Params& Params::getInstance()
{
	static Params instance;
	return instance;
}

void Params::loadParamsFromCommandLine(int argc, char **argv)
{
	char c;
	int longindex = 0;

	const char* optstring = "hedm:a:A:n:s:i:o:";
	const struct option longopts[] = {
		{"help",                     0, 0, 'h'},
		{"encryption",               0, 0, 'e'},
		{"decryption",               0, 0, 'd'},
		{"method",   required_argument, 0, 'm'},
		{"offset_a", required_argument, 0, 'a'},
		{"offset_A", required_argument, 0, 'A'},
		{"seed",     required_argument, 0, 's'},
		{"input",    required_argument, 0, 'i'},
		{"output",   required_argument, 0, 'o'},
	};

	while ((c = getopt_long(argc, argv, optstring, longopts, &longindex)) != -1)
	{
		switch (c)
		{
			case 'h':
				printUsageAndExit();
				break;
			case 'e':
				this->m_encryption = true;
				break;
			case 'd':
				this->m_encryption = false;
				break;
			case 'm':
				if (std::atoi(optarg) == 0)
				{
					this->m_method = CONVERSIONMETHOD::SHIFT;
				}
				else if (std::atoi(optarg) == 1)
				{
					this->m_method = CONVERSIONMETHOD::ALLX;
				}
				break;
			case 'a':
				this->m_offset_a = std::atoi(optarg);
				break;
			case 'A':
				this->m_offset_A = std::atoi(optarg);
				break;
			case 's':
				this->m_seed = std::atoi(optarg);
				break;
			case 'i':
				this->m_fin = static_cast<std::string>(optarg);
				break;
			case 'o':
				this->m_fout = static_cast<std::string>(optarg);
				break;
			case '*':
				printUsageAndExit();
				break;
		}
	}
}

void Params::show() const {
	std::cout << "encryption: " << this->m_encryption << std::endl;
	std::cout << "method:     " << static_cast<int>(this->m_method) << std::endl;
	std::cout << "offset_a:   " << this->m_offset_a   << std::endl;
	std::cout << "offset_A:   " << this->m_offset_A   << std::endl;
	std::cout << "fin:        " << this->m_fin        << std::endl;
	std::cout << "fout:       " << this->m_fout       << std::endl;
}

void Params::printUsageAndExit() const
{
	std::cerr << "Usage of CodeTalker:"                      << std::endl;
	std::cerr << "[-h | --help]"                             << std::endl;
	std::cerr << "[-e | --encryption]"                       << std::endl;
	std::cerr << "[-d | --decryption]"                       << std::endl;
	std::cerr << "[-a | --offset_a] <num_of_offset_for_a-z>" << std::endl;
	std::cerr << "[-A | --offset_A] <num_of_offset_for_A-Z>" << std::endl;
	std::cerr << "[-n | --offset_n] <num_of_offset_for_0-9>" << std::endl;
	std::cerr << "[-s | --seed]     <num_as_seed>"           << std::endl;
	std::cerr << "[-i | --input]    <input_flie_name>"       << std::endl;
	std::cerr << "[-o | --output]   <output_file_name>"      << std::endl;
	exit(EXIT_FAILURE);
}

bool Params::getEncryption(void) const
{
	return this->m_encryption;
}

CONVERSIONMETHOD Params::getMethod(void) const
{
	return this->m_method;
}

int Params::getOffseta(void) const
{
	return this->m_offset_a;
}

int Params::getOffsetA(void) const
{
	return this->m_offset_A;
}

int Params::getSeed(void) const
{
	return this->m_seed;
}

std::string Params::getInputFile(void) const
{
	return this->m_fin;
}

std::string Params::getOutputFile(void) const
{
	return this->m_fout;
}


/**
 * @class CodeTalker
 * @brief ファイルを難読化するためのクラス
 */
class CodeTalker
{
private:
	std::string input_filename; /** 入力ファイル名 */
	std::string output_filename; /** 出力ファイル名 */

	std::ifstream infile;
	std::ofstream outfile;

	CONVERSIONMETHOD m_method = CONVERSIONMETHOD::SHIFT;

	int m_sign = 1; // Encryption --> 1, Decryption --> -1
	int m_OFFA = 0; // Encryption --> 0, Decryption --> 26
	int m_OFFN = 0; // Encryption --> 0, Decryption --> 10
	int m_SEED = 1;
	int m_ofsa = 1;
	int m_ofsA = 1;

public:
	explicit CodeTalker();
	explicit CodeTalker(Params& prms);
	// explicit FileConverter(std::string fin, std::string fout, Params& prms);
	~CodeTalker();

	/**
	 * 暗号化・復号化処理の本体
	 */
	void convert();

	/**
	 * 行ごとに暗号化・復号化をするメソッド
	 * @param [in] line 処理する行
	 */
	std::string shiftAlphabet(std::string& line,
			                  std::uniform_int_distribution<int>& prng,
							  std::mt19937& mt);
	std::string replaceAlphabetWithX(std::string& line,
			                         std::uniform_int_distribution<int>& prng,
									 std::mt19937& mt);
};

CodeTalker::CodeTalker()
{
	input_filename = "input.txt";
	output_filename = "output.txt";
}

CodeTalker::CodeTalker(Params& prms)
{
	input_filename = prms.getInputFile();
	output_filename = prms.getOutputFile();

	m_method = prms.getMethod();
	m_ofsa = prms.getOffseta();
	m_ofsA = prms.getOffsetA();
	m_SEED = prms.getSeed();

	if (prms.getEncryption())
	{
		m_sign = static_cast<int>(SIGN::ENCRYPTION);
		m_OFFA = static_cast<int>(ALPHABETOFFSET::ENCRYPTION);
		m_OFFN = static_cast<int>(NUMBEROFFSET::ENCRYPTION);
	}
	else
	{
		m_sign = static_cast<int>(SIGN::DECRYPTION);
		m_OFFA = static_cast<int>(ALPHABETOFFSET::DECRYPTION);
		m_OFFN = static_cast<int>(NUMBEROFFSET::DECRYPTION);
	}
}

CodeTalker::~CodeTalker()
{
	if (infile.is_open())
	{
		infile.close();
	}

	if (outfile.is_open())
	{
		outfile.close();
	}
}


void CodeTalker::convert()
{
	infile.open(input_filename);
	if (!infile.is_open())
	{
		std::cerr << "Cannot open the input file." << std::endl;
		exit(EXIT_FAILURE);
	}

	outfile.open(output_filename);
	if (!outfile.is_open())
	{
		std::cerr << "Cannot open the output file." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	std::string converted_line = "";

	//- 数値を難読化するための疑似乱数生成器としてメルセンヌ・ツイスターを用いる
	std::mt19937 mt(this->m_SEED);
	//- 0 ~ 9の整数で構成される一様分布を生成する疑似乱数列とする
	std::uniform_int_distribution<> prng(0, 9);

	while (getline(infile, line))
	{
		if (m_method == CONVERSIONMETHOD::SHIFT)
		{
			converted_line = shiftAlphabet(line, prng, mt);
		}
		else if (m_method == CONVERSIONMETHOD::ALLX)
		{
			converted_line = replaceAlphabetWithX(line, prng, mt);
		}
		outfile << converted_line << std::endl;
	}

	infile.close();
	outfile.close();
}


std::string CodeTalker::shiftAlphabet(std::string& inputLine,
		                                 std::uniform_int_distribution<int>& prng,
										 std::mt19937& mt)
{

	std::string outputLine = "";
	int a, b, c = 0;
	for (char const& C : inputLine)
	{
		if (C >= 'a' && C <= 'z')
		{
			outputLine
				+= (C - 'a' + m_sign * m_ofsa + m_OFFA) % NUMOFALPHABET + 'a';
		}
		else if (C >= 'A' && C <= 'Z')
		{
			outputLine
				+= (C - 'A' + m_sign * m_ofsA + m_OFFA) % NUMOFALPHABET + 'A';
		}
		else if (C >= '0' && C <= '9')
		{
			if (m_sign == static_cast<int>(SIGN::ENCRYPTION))
			{
				a = static_cast<int>(C - '0');
				b = prng(mt);
				c = (a + b) % NUMOFNUMBER;
				outputLine += static_cast<char>(c + '0');
			}
			else
			{
				c = static_cast<int>(C - '0');
				b = prng(mt);
				if (0 <= c - b) { a = c - b; }
				else { a = c + NUMOFNUMBER - b; }
				outputLine += static_cast<char>(a + '0');
			}
		}
		else
		{
			outputLine += C;
		}
	}
	return outputLine;
} 


std::string CodeTalker::replaceAlphabetWithX(
		std::string& inputLine,
		std::uniform_int_distribution<>& prng,
		std::mt19937& mt)
{
	std::string outputLine = "";
	bool isFirstChar = true;
	int a, b, c  = 0;

	for (char const& C : inputLine)
	{
		if (isalpha(C))
		{
			if (isFirstChar)
			{
				outputLine += C;
			}
			else
			{
				outputLine += (isupper(C)) ? 'X' : 'x';
			}
			isFirstChar = false;
		}
		else if (C >= '0' && C <= '9')
		{
			if (m_sign == static_cast<int>(SIGN::ENCRYPTION))
			{
				a = static_cast<int>(C - '0');
				b = prng(mt);
				c = (a + b) % NUMOFNUMBER;
				outputLine += static_cast<char>(c + '0');
			}
			else
			{
				c = static_cast<int>(C - '0');
				b = prng(mt);
				if (0 <= c - b) { a = c - b; }
				else { a = c + NUMOFNUMBER - b; }
				outputLine += static_cast<char>(a + '0');
			}
		}
		else
		{
			outputLine += C;
			isFirstChar = true;
		}
	}
	return outputLine;
} 


int main(int argc, char** argv)
{
	try
	{
		Params& prms = Params::getInstance();
		prms.loadParamsFromCommandLine(argc, argv);
		// prms.show();

		CodeTalker converter(prms);
		converter.convert();

		std::cout << "Conversion complete." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << typeid(e).name() << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
