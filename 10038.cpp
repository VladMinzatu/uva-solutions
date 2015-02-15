#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	int n;
	while(std::cin>>n)
	{
		std::vector<bool> value_used;
		value_used.reserve(n - 1);
		for(int i = 0; i < n - 1; i++)
			value_used[i] = false;

		int prev, cur;
		std::cin>>prev;
		for(int i = 1; i < n; i++)
		{
			std::cin>>cur;
			int diff = (cur > prev?(cur - prev):(prev - cur)) - 1;
			if(diff >= 0 && diff < n - 1)
				value_used[diff] = true; 
			prev = cur;
		}

		bool jolly = true;
		for(int i = 0; i < n - 1; i++)
		{
			jolly = jolly && value_used[i];
			if(!jolly)
				break;
		} 
		if(jolly)
			std::cout<<"Jolly"<<std::endl;
		else
			std::cout<<"Not jolly"<<std::endl;
	}
	return 0;
}
