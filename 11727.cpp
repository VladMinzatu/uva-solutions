#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int s1, s2, s3;
        std::cin>>s1>>s2>>s3;
        
        std::vector<int> salaries;
        salaries.push_back(s1); 
        salaries.push_back(s2); 
        salaries.push_back(s3);
        
        std::sort(salaries.begin(), salaries.end());
        std::cout<<"Case "<<(i+1)<<": "<<salaries[1]<<std::endl;
    }
    return 0;
}
