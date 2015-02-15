#include <iostream>

int main(int argc, char **argv)
{
	int L;
	do{
		std::cin>>L;
		if(!L)
			break;
		int last_d = -1;
		int last_r = -1;
		int min_dist = L;
		char c;
		for(int i = 0; i < L; i++)
		{
			std::cin>>c;
			if(c == 'Z')
			{
				min_dist = 0; 
				// we could break now, but we need to 
				// continue reading the whole input
				last_d = i;
				last_r = i;
			} 
			else if(c == 'R')
			{
				if(last_d != -1)
				{
					int dist = i - last_d;
					if(dist < min_dist)
						min_dist = dist;
				}
				last_r = i;
			}
			else if(c == 'D')
			{
				if(last_r != -1)
				{
					int dist = i - last_r;
					if(dist < min_dist)
						min_dist = dist;
				}
				last_d = i;
			}	
		}
		std::cout<<min_dist<<std::endl;
	}while(true);
}
