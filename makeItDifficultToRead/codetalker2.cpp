#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>

class Params
{
private:
	Params()  = default;
	~Params() = default;
	bool encryption = true;
	int offset_a = 1;
	int offset_A = 1;
	int offset_n = 1;
	std::string fin  = "input.txt";
	std::string fout = "output.txt";

public:
	Params(const Params& obj) = delete;
	Params& operator=(const Params& obj) = delete;
	Params(Params&& obj) = delete;
	Params& operator=(Params&& obj) = delete;

	static Params& getInstance();

	void loadParamsFromCommandLine(int argc, char** argv);
	void show() const;
	void printUsageAndExit() const;

	int getOffseta() const;
	int getOffsetA() const;
	int getOffsetn() const;
	bool getEncryption() const;

	std::string getInputFile() const;
	std::string getOutputFile() const;
};

class CodeTalker
{
private:
	int m_ofsa = 1;
	int m_ofsA = 1;
	int m_ofsn = 1;

	std::string m_fin  = "input.txt";
	std::string m_fout = "output.txt";

	std::ifstream m_inputFile;
	std::ofstream m_outputFile;

public:
	// CodeTalker(Params& prms);
	CodeTalker();
	CodeTalker(const int& ofsa, const int& ofsA, const int& ofsn);
	~CodeTalker();
                        
	/*
	// delete copy constructor
	CodeTalker(const CodeTalker& other) = delete;
	// delete copy operator also
	CodeTalker& operator=(const CodeTalker& other) = delete;

	// delete move constructor
	CodeTalker(CodeTalker&& other) = delete;
	// delete move operator also
	CodeTalker&& operator=(CodeTalker&& other) = delete;
	*/

	int openFiles();
	void closeFiles();

	std::string encrypt(std::string input);
	std::string decrypt(std::string input);

	void show(void) const;
};


CodeTalker::CodeTalker(const int& ofsa, const int& ofsA, const int& ofsn)
// CodeTalker::CodeTalker(Params& prms)
{
	m_ofsa = ofsa;
	m_ofsA = ofsA;
	m_ofsn = ofsn;
	// m_ofsa = prms.getOffseta();
	// m_ofsA = prms.getOffsetA();
	// m_ofsn = prms.getOffsetn();
	// m_fin  = prms.getInputFile();
	// m_fout = prms.getOutputFile();
}

CodeTalker::CodeTalker() : CodeTalker(1, 1, 1)
{
}

CodeTalker::~CodeTalker()
{
}

std::string CodeTalker::encrypt(std::string input)
{
	std::string output = "";
	return output;
}

std::string CodeTalker::decrypt(std::string input)
{
	std::string output = "";
	return output;
}

int CodeTalker::openFiles(void)
{
	m_inputFile.open(m_fin);
	if (!m_inputFile.is_open())
	{
		std::cerr << "Cannot open the input file." << std::endl;
		return 1;
	}
	m_outputFile.open(m_fout);
	if (!m_outputFile.is_open())
	{
		std::cerr << "Cannot open the output file." << std::endl;
		return 1;
	}
	return 0;
}

void CodeTalker::closeFiles(void)
{
	m_inputFile.close();
	m_outputFile.close();
}

void CodeTalker::show(void) const
{
	std::cout << m_ofsa << "," << m_ofsA << "," << m_ofsn << std::endl;
}


Params& Params::getInstance()
{
	static Params instance;
	return instance;
}

void Params::loadParamsFromCommandLine(int argc, char **argv)
{
	char c;
	int longindex = 0;

	const char* optstring = "heda:A:n:i:o:";
	const struct option longopts[] = {
		{"help",                     0, 0, 'h'},
		{"encryption",               0, 0, 'e'},
		{"decryption",               0, 0, 'd'},
		{"offset_a", required_argument, 0, 'a'},
		{"offset_A", required_argument, 0, 'A'},
		{"offset_n", required_argument, 0, 'n'},
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
				this->encryption = true;
				break;
			case 'd':
				this->encryption = false;
				break;
			case 'a':
				this->offset_a = std::atoi(optarg);
				break;
			case 'A':
				this->offset_A = std::atoi(optarg);
				break;
			case 'n':
				this->offset_n = std::atoi(optarg);
				break;
			case 'i':
				this->fin = static_cast<std::string>(optarg);
				break;
			case 'o':
				this->fout = static_cast<std::string>(optarg);
				break;
			case '*':
				printUsageAndExit();
				break;
		}
	}
}

void Params::show() const
{
	std::cout << "encryption: " << this->encryption << std::endl;
	std::cout << "offset_a:   " << this->offset_a   << std::endl;
	std::cout << "offset_A:   " << this->offset_A   << std::endl;
	std::cout << "offset_n:   " << this->offset_n   << std::endl;
	std::cout << "fin:        " << this->fin        << std::endl;
	std::cout << "fout:       " << this->fout       << std::endl;
}

void Params::printUsageAndExit() const
{
	std::cerr << "Usage of CodeTalker:" << std::endl;
	std::cerr << "[-h | --help]" << std::endl;
	std::cerr << "[-e | --encryption]" << std::endl;
	std::cerr << "[-d | --decryption]" << std::endl;
	std::cerr << "[-a | --offset_a] <num_of_offset_for_a-z>" << std::endl;
	std::cerr << "[-A | --offset_A] <num_of_offset_for_A-Z>" << std::endl;
	std::cerr << "[-n | --offset_n] <num_of_offset_for_0-9>" << std::endl;
	std::cerr << "[-i | --input]    <input_flie_name>" << std::endl;
	std::cerr << "[-o | --output]   <output_file_name>" << std::endl;
}

bool Params::getEncryption(void) const
{
	return this->encryption;
}

int Params::getOffseta(void) const
{
	return this->offset_a;
}

int Params::getOffsetA(void) const
{
	return this->offset_A;
}

int Params::getOffsetn(void) const
{
	return this->offset_n;
}

std::string Params::getInputFile(void) const
{
	return this->fin;
}

std::string Params::getOutputFile(void) const
{
	return this->fout;
}

std::string replaceAlphabet(std::string input)
{
	std::string output = "";
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			// aをbに、bをcに...、zをaに
			output += static_cast<char>((input[i] - 'a' + 1) % 26 + 'a');
		}
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
			// AをBに、BをCに...、ZをAに
			output += static_cast<char>((input[i] - 'A' + 1) % 26 + 'A');
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			// 0を1に、1を2に...、9を0に
			output += static_cast<char>((input[i] - '0' + 1) % 10 + '0');
		}
		else
		{
			// アルファベットと数値以外の文字はそのまま出力
			output += input[i];
		}
	}
	return output;
}

int main(int argc, char** argv)
{ 
	Params& prms = Params::getInstance();
	prms.loadParamsFromCommandLine(argc, argv);

	// CodeTalker ct = CodeTalker();
	CodeTalker ct1 = CodeTalker(prms.getOffseta(), prms.getOffsetA(), prms.getOffsetn());
	// CodeTalker ct1 = CodeTalker(prms);
	ct1.show();

	return 0;
}

