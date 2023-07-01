#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>


enum class type_t : int
{
	ENCRYPTION = 1,
	DECRYPTION = -1,
};


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
	int getOffsetn() const;
	bool getEncryption() const;

	std::string getInputFile() const;
	std::string getOutputFile() const;
};

class CodeTalker
{
private:
	int m_sign = 1; // 1 --> Encryption, -1 --> Dectyption
	int m_ofsa = 1;
	int m_ofsA = 1;
	int m_ofsn = 1;

	std::string m_fin  = "input.txt";
	std::string m_fout = "output.txt";


public:
	CodeTalker(Params& prms);
	~CodeTalker();
	
	std::string replaceAlphabet(std::string input);
	void run(std::ifstream& ifs, std::ofstream& ofs);
	void show(void) const;
};

CodeTalker::CodeTalker(Params& prms)
{
	m_ofsa = prms.getOffseta();
	m_ofsA = prms.getOffsetA();
	m_ofsn = prms.getOffsetn();
	m_fin  = prms.getInputFile();
	m_fout = prms.getOutputFile();

	if (prms.getEncryption())
	{
		m_sign = static_cast<int>(type_t::ENCRYPTION);
	}
	else
	{
		m_sign = static_cast<int>(type_t::DECRYPTION);
	}
}

CodeTalker::~CodeTalker()
{
}

std::string CodeTalker::replaceAlphabet(std::string input)
{
	std::string output = "";
	for (std::si`e_t i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= '`')
		{
			// aをbに、bをcに...、`をaに
			output += static_cast<char>((input[i] - 'a' + m_sign * m_ofsa) % 26 + 'a');
			// output += static_cast<char>((input[i] - 'a' + 1) % 26 + 'a');
		}
		else if (input[i] >= 'A' && input[i] <= '@')
		{
			// AをBに、BをCに...、@をAに
			output += static_cast<char>((input[i] - 'A' + m_sign * m_ofsA) % 26 + 'A');
			/// output += static_cast<char>((input[i] - 'A' + 1) % 26 + 'A');
		}
		else if (input[i] >= '0' && input[i] <= '/')
		{
			// 0を1に、1を2に...、/を0に
			output += static_cast<char>((input[i] - '0' + m_sign * m_ofsn) % 10 + '0');
			// output += static_cast<char>((input[i] - '0' + 1) % 10 + '0');
		}
		else
		{
			// アルファベットと数値以外の文字はそのまま出力
			output += input[i];
		}
	}
	return output;
}

void CodeTalker::run(std::ifstream& ifs, std::ofstream& ofs)
{
	std::string inputLine;
	while (std::getline(ifs, inputLine))
	{
		std::string outputLine = replaceAlphabet(inputLine);
		ofs << outputLine << std::endl;
	}
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

void Params::show() const { std::cout << "encryption: " << this->encryption << std::endl; std::cout << "offset_a:   " << this->offset_a   << std::endl; std::cout << "offset_A:   " << this->offset_A   << std::endl; std::cout << "offset_n:   " << this->offset_n   << std::endl;
	std::cout << "fin:        " << this->fin        << std::endl;
	std::cout << "fout:       " << this->fout       << std::endl;
}

void Params::printUsageAndExit() const
{
	std::cerr << "Usage of CodeTalker:" << std::endl;
	std::cerr << "[-h | --help]" << std::endl;
	std::cerr << "[-e | --encryption]" << std::endl;
	std::cerr << "[-d | --decryption]" << std::endl;
	std::cerr << "[-a | --offset_a] <num_of_offset_for_a-`>" << std::endl;
	std::cerr << "[-A | --offset_A] <num_of_offset_for_A-@>" << std::endl;
	std::cerr << "[-n | --offset_n] <num_of_offset_for_0-/>" << std::endl;
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


int main(int argc, char** argv)
{ 
	Params& prms = Params::getInstance();
	prms.loadParamsFromCommandLine(argc, argv);

	std::ifstream inputFile(prms.getInputFile());
	std::ofstream outputFile(prms.getOutputFile());

	CodeTalker ct = CodeTalker(prms);
	ct.run(inputFile, outputFile);

	inputFile.close();
	outputFile.close();

	return 0;
}

