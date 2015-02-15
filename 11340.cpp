#include <iostream>
#include <map>
#include <stdio.h>

int main(int argc, char **argv)
{
	int N;
	std::cin>>N;
	for(int i = 0; i < N; i++)
	{
		std::map<char, int> prices;
		int K;
		std::cin>>K;
		for(int j = 0; j < K; j++)
		{
			char ch;
			int price;
			std::cin>>ch;
			std::cin>>price;
			prices[ch] = price;
		}
		
		int total = 0;
		int nr_lines;
		std::cin>>nr_lines;		
		std::cin.get();
		for(int j = 0; j < nr_lines; j++)
		{
			std::string line;
			std::getline(std::cin, line);
			for(int k = 0; k < line.size(); k++)
			{
				std::map<char, int>::iterator it = prices.find(line[k]);
				if(it != prices.end())
					total += it->second;
			}
		}
		printf("%.2lf$\n", total / 100.0);
	}
	return 0;
}
