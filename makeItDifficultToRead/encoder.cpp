#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>

std::string replaceAlphabet(std::string input, int ofsa, int ofsA, int ofsn)
{
	std::string output = "";
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			// aをbに、bをcに...、zをaに
			output += static_cast<char>((input[i] - 'a' + ofsa) % 26 + 'a');
		}
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
			// AをBに、BをCに...、ZをAに
			output += static_cast<char>((input[i] - 'A' + ofsA) % 26 + 'A');
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			// 0を1に、1を2に...、9を0に
			output += static_cast<char>((input[i] - '0' + ofsn) % 10 + '0');
		}
		else
		{
			// アルファベットと数値以外の文字はそのまま出力
			output += input[i];
		}
	}
	return output;
}


class Params
{
private:
	Params()  = default;
	~Params() = default;
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

	const char* optstring = "ha:A:n:i:o:";
	const struct option longopts[] = {
		{"help",                     0, 0, 'h'},
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
	std::cout << "aaa" << std::endl;
	std::cout << "offset_a: " << this->offset_a << std::endl;
	std::cout << "offset_A: " << this->offset_A << std::endl;
	std::cout << "offset_n: " << this->offset_n << std::endl;
	std::cout << "fin:      " << this->fin      << std::endl;
	std::cout << "fout:     " << this->fout     << std::endl;
}

void Params::printUsageAndExit() const
{
	std::cerr << "Usage of CodeTalker:" << std::endl;
	std::cerr << "[-a | --offset_a] <num_of_offset_for_a-z>" << std::endl;
	std::cerr << "[-A | --offset_A] <num_of_offset_for_A-Z>" << std::endl;
	std::cerr << "[-n | --offset_n] <num_of_offset_for_0-9>" << std::endl;
	std::cerr << "[-i | --input]    <input_flie_name>" << std::endl;
	std::cerr << "[-o | --output]   <output_file_name>" << std::endl;
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
	const int ofsa = prms.getOffseta();
	const int ofsA = prms.getOffsetA();
	const int ofsn = prms.getOffsetn();

	if (!inputFile.is_open())
	{
		std::cerr << "Cannot open input.txt." << std::endl;
		return 1;
	}

	if (!outputFile.is_open())
	{
		std::cerr << "Cannot open output.txt." << std::endl;
		return 1;
	}

	std::string inputLine;
	while (std::getline(inputFile, inputLine))
	{
		std::string outputLine = replaceAlphabet(inputLine, ofsa, ofsA, ofsn);
		outputFile << outputLine << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}

