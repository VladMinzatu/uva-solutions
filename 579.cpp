#include <iostream>
#include <cstdlib>
#include <cmath>

void read_time(const std::string& time, int& H, int& M);

int main(int argc, char **argv)
{
	int H,M;
	std::string time;
	std::cout.setf(std::ios::fixed);
    	std::cout.precision(3);
	while(true)
	{
		std::cin>>time;
		if(time == "0:00")
			break;
		read_time(time, H, M);
		float h = 30*H + 0.5*M;	
		float m = 6*M;
		float deg = std::abs(h - m);
		if(deg > 180)
			std::cout<<(360 - deg)<<std::endl;
		else
			std::cout<<deg<<std::endl;
	}
	return 0;
}

void read_time(const std::string& time, int& H, int& M)
{
	size_t pos = time.find(":");
	H = std::atoi(time.substr(0, pos).c_str());
	M = std::atoi(time.substr(pos + 1).c_str());
}
