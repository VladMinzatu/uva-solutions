#include <iostream>
#include <vector>

bool palindrome(const std::string& word);

//converts the line into a lower case word, removing
//punctuation.
std::string get_word(const std::string& line);

int main(int argc, char **argv)
{
	while(true)
	{
		std::string line;
		std::getline(std::cin, line);
		if(line == "DONE")
			break;
		if(palindrome(get_word(line)))
			std::cout<<"You won't be eaten!"<<std::endl;
		else 
			std::cout<<"Uh oh.."<<std::endl;
	}
	return 0;
}

bool palindrome(const std::string& word)
{
	size_t len = word.size();
	for(int i = 0; i < len / 2; i++)
	{
		if(word[i] != word[len - i - 1])
			return false;
	}
	return true;
}

std::string get_word(const std::string& line)
{
	std::vector<char> array;
	for(int i = 0; i < line.size(); i++)
	{
		if(line[i] >= 'a' && line[i] <= 'z')
			array.push_back(line[i]); 
		else if(line[i] >= 'A' && line[i] <= 'Z')
			array.push_back(line[i] + 32);
	}
	std::string word(array.begin(), array.end());
	return word;
}
