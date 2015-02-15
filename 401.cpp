#include <iostream>
#include <map>

bool palindrome(const std::string& word);
bool mirrored(const std::string& word, std::map<char, char>& mirror);
void init_mirror(std::map<char, char>& mirror);

int main(int argc, char **argv)
{
	std::string word;
	std::map<char, char> mirror;
	init_mirror(mirror);

	while(std::cin>>word)
	{
		bool pal = palindrome(word);
		bool mir = mirrored(word, mirror);
		if(pal && mir)
			std::cout<<word<<" -- is a mirrored palindrome."<<std::endl;
		else if(pal && !mir)
			std::cout<<word<<" -- is a regular palindrome."<<std::endl;
		else if(!pal && mir)
			std::cout<<word<<" -- is a mirrored string."<<std::endl;
		else
			std::cout<<word<<" -- is not a palindrome."<<std::endl;
		std::cout<<std::endl;
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

bool mirrored(const std::string& word, std::map<char, char>& mirror)
{
	size_t len = word.size();
	std::string mirrored_word(len, ' ');
	for(int i = len - 1; i >= 0; i--)
	{
		if(mirror.find(word[i]) == mirror.end())
			return false;
		else
			mirrored_word[len - i - 1] = mirror[word[i]];
	}
	return mirrored_word == word;
}

void init_mirror(std::map<char, char>& mirror)
{
	mirror['A'] = 'A';
	mirror['E'] = '3';
	mirror['H'] = 'H';
	mirror['I'] = 'I';
	mirror['J'] = 'L';
	mirror['L'] = 'J';
	mirror['M'] = 'M';
	mirror['O'] = 'O';
	mirror['S'] = '2';
	mirror['T'] = 'T';
	mirror['U'] = 'U';
	mirror['V'] = 'V';
	mirror['W'] = 'W';
	mirror['X'] = 'X';
	mirror['Y'] = 'Y';
	mirror['Z'] = '5';
	mirror['1'] = '1';
	mirror['2'] = 'S';
	mirror['3'] = 'E';
	mirror['5'] = 'Z';
	mirror['8'] = '8';
}
