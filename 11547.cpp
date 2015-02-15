#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n;
        std::cin>>n;
        std::cout<<std::abs(((n*315)+36962)/10)%10<<std::endl;
    }
    return 0;
}
