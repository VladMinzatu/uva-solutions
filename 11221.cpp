#include <iostream>
#include <vector>
#include <math.h>

int magic(const std::string& word);

//converts the line into a lower case word, removing
//punctuation.
std::string get_word(const std::string& line);

int main(int argc, char **argv)
{
	int T;
	std::cin>>T;
	std::cin.get();
	for(int i = 0; i < T; i++)
	{
		std::string line;
		std::getline(std::cin, line);
		std::string word = get_word(line);
		int k = magic(word);
		std::cout<<"Case #"<<(i+1)<<":"<<std::endl;
		if(k == -1)
			std::cout<<"No magic :("<<std::endl;
		else
			std::cout<<k<<std::endl;
		
	}
	return 0;
}

int magic(const std::string& word)
{
	double sz = sqrt(word.size());
	if(sz*sz != word.size())
		return -1;
	int k = (int)sz;
	std::vector<std::vector<char> > square;
	for(int i = 0; i < k; i++)
	{
		square.push_back(std::vector<char>());
		for(int j = 0; j < k; j++)
			square[i].push_back(word[i*k + j]);
	}

	std::vector<char> array1;
	for(int i = 0; i < k; i++)
		array1.insert(array1.end(), square[i].begin(), square[i].end());
	std::string word1(array1.begin(), array1.end());

	std::vector<char> array2;
	for(int j = 0; j < k; j++)
		for(int i = 0; i < k; i++)
			array2.push_back(square[i][j]);
	std::string word2(array2.begin(), array2.end());

	std::vector<char> array3;
	for(int i = k - 1; i >= 0; i--)
		for(int j = k - 1; j >= 0; j--)
			array3.push_back(square[i][j]);
	std::string word3(array3.begin(), array3.end());

	std::vector<char> array4;
        for(int j = k - 1; j >= 0; j--)
                for(int i = k - 1; i >= 0; i--)
                        array4.push_back(square[i][j]);
        std::string word4(array4.begin(), array4.end());

	if((word1 == word2) && (word2 == word3) && (word3 == word4))
		return k;
	else
		return -1;
}

std::string get_word(const std::string& line)
{
	std::vector<char> array;
	for(int i = 0; i < line.size(); i++)
	{
		if(line[i] >= 'a' && line[i] <= 'z')
			array.push_back(line[i]); 
	}
	std::string word(array.begin(), array.end());
	return word;
}
