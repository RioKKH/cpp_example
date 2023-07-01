#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <typeinfo>
#include <getopt.h>


const int NUMOFNUMBER = 10;
const int NUMOFALPHABET = 26;

enum class SIGN : int
{
	ENCRYPTION = 1,
	DECRYPTION = -1,
};

enum class OFFSETALPHABET : int
{
	ENCRYPTION = 0,
	DECRYPTION = NUMOFALPHABET,
};

enum class OFFSETNUMBER : int
{
	ENCRYPTION = 0,
	DECRYPTION = NUMOFNUMBER,
};


class Params
{
private:
	Params()  = default;
	~Params() = default;
	bool m_encryption = true;
	int m_offset_a = 1;
	int m_offset_A = 1;
	// int m_offset_n = 1;
	int m_seed     = 1789;
	std::string m_fin  = "input.txt";
	std::string m_fout = "output.txt";

public:
	// delete copy constructor
	Params(const Params& obj) = delete;
	Params& operator=(const Params& obj) = delete;
	// delete move constructor
	Params(Params&& obj) = delete;
	Params& operator=(Params&& obj) = delete;

	static Params& getInstance();

	void loadParamsFromCommandLine(int argc, char** argv);
	void show() const;
	void printUsageAndExit() const;

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

	const char* optstring = "heda:A:n:s:i:o:";
	const struct option longopts[] = {
		{"help",                     0, 0, 'h'},
		{"encryption",               0, 0, 'e'},
		{"decryption",               0, 0, 'd'},
		{"offset_a", required_argument, 0, 'a'},
		{"offset_A", required_argument, 0, 'A'},
		// {"offset_n", required_argument, 0, 'n'},
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
			case 'a':
				this->m_offset_a = std::atoi(optarg);
				break;
			case 'A':
				this->m_offset_A = std::atoi(optarg);
				break;
			/*
			case 'n':
				this->m_offset_n = std::atoi(optarg);
				break;
			*/
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
	std::cout << "offset_a:   " << this->m_offset_a   << std::endl;
	std::cout << "offset_A:   " << this->m_offset_A   << std::endl;
	// std::cout << "offset_n:   " << this->m_offset_n   << std::endl;
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

int Params::getOffseta(void) const
{
	return this->m_offset_a;
}

int Params::getOffsetA(void) const
{
	return this->m_offset_A;
}

/*
int Params::getOffsetn(void) const
{
	return this->m_offset_n;
}
*/

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



class CodeTalker
{
private:
	int m_sign = 1; // 1 --> Encryption, -1 --> Dectyption
	int m_OFFA = 0; // 0 --> Encryption, 26 --> Decryption
	int m_OFFN = 0; // 0 --> Encryption, 10 --> Decryption
	int m_SEED = 1;
	int m_ofsa = 1;
	int m_ofsA = 1;
	// int m_ofsn = 1;

	std::string m_fin  = "input.txt";
	std::string m_fout = "output.txt";


public:
	CodeTalker(Params& prms);
	~CodeTalker();
	
	std::string replaceAlphabet(std::string input, std::uniform_int_distribution<>& prng);
	void run(std::ifstream& ifs, std::ofstream& ofs);
	void show(void) const;
};

CodeTalker::CodeTalker(Params& prms)
{
	m_ofsa = prms.getOffseta();
	m_ofsA = prms.getOffsetA();
	// m_ofsn = prms.getOffsetn();
	m_SEED = prms.getSeed();
	m_fin  = prms.getInputFile();
	m_fout = prms.getOutputFile();

	if (prms.getEncryption())
	{
		m_sign = static_cast<int>(SIGN::ENCRYPTION);
		m_OFFA = static_cast<int>(OFFSETALPHABET::ENCRYPTION);
		m_OFFN = static_cast<int>(OFFSETNUMBER::ENCRYPTION);
	}
	else
	{
		m_sign = static_cast<int>(SIGN::DECRYPTION);
		m_OFFA = static_cast<int>(OFFSETALPHABET::DECRYPTION);
		m_OFFN = static_cast<int>(OFFSETNUMBER::DECRYPTION);
	}
}

CodeTalker::~CodeTalker()
{
}

void CodeTalker::run(std::ifstream& ifs, std::ofstream& ofs)
{
	std::string inputLine;

	std::mt19937 mt(this->m_SEED);
	std::uniform_int_distribution<> prng(0, 9);

	while (std::getline(ifs, inputLine))
	{
		std::string outputLine = "";
		int a, b, c = 0;

		for (std::size_t i = 0; i < inputLine.length(); i++) 
		{
			if (inputLine[i] >= 'a' && inputLine[i] <= 'z')
			{
				// aをbに、bをcに...、zをaに
				outputLine += static_cast<char>((inputLine[i] - 'a' + m_sign * m_ofsa + m_OFFA) % NUMOFALPHABET + 'a');
			}
			else if (inputLine[i] >= 'A' && inputLine[i] <= 'Z')
			{
				// AをBに、BをCに...、ZをAに
				outputLine += static_cast<char>((inputLine[i] - 'A' + m_sign * m_ofsA + m_OFFA) % NUMOFALPHABET + 'A');
			}
			else if (inputLine[i] >= '0' && inputLine[i] <= '9')
			{
				if (m_sign == static_cast<int>(SIGN::ENCRYPTION))
				{
					a = static_cast<int>(inputLine[i] - '0');
					b = prng(mt);
					c = (a + b) % NUMOFNUMBER;
					outputLine += static_cast<char>(c + '0');
				}
				else
				{
					c = static_cast<int>(inputLine[i] - '0');
					b = prng(mt);
					if (0 <= c - b) { a = c - b; }
					else { a = c + NUMOFNUMBER - b; }
					outputLine += static_cast<char>(a + '0');
				}
			}
			else
			{
				// アルファベットと数値以外の文字はそのまま出力
				outputLine += inputLine[i];
			}
		}
		ofs << outputLine << std::endl;
	}
}

void CodeTalker::show(void) const
{
	std::cout << m_ofsa << "," << m_ofsA << "," << std::endl;
	// std::cout << m_ofsa << "," << m_ofsA << "," << m_ofsn << std::endl;
}



int main(int argc, char** argv)
{ 
	try
	{
		Params& prms = Params::getInstance();
		prms.loadParamsFromCommandLine(argc, argv);

		std::ifstream inputFile(prms.getInputFile());
		if (!inputFile.is_open())
		{ 
			std::cerr << "Cannot open the input file." << std::endl;
			exit(EXIT_FAILURE);
		}

		std::ofstream outputFile(prms.getOutputFile());
		if (!outputFile.is_open())
		{
			std::cerr << "Cannot open the output file." << std::endl;
			exit(EXIT_FAILURE);
		}

		CodeTalker ct = CodeTalker(prms);
		ct.run(inputFile, outputFile);

		inputFile.close();
		outputFile.close();
	}
	catch (std::exception& e)
	{
		std::cerr << typeid(e).name() << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}

