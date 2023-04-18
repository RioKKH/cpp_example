#include <iostream>
#include <fstream>
#include <string>

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

int main()
{ std::string inputFileName = "input.txt";
	std::string outputFileName = "output.txt";

	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);

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
		std::string outputLine = replaceAlphabet(inputLine);
		outputFile << outputLine << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}

