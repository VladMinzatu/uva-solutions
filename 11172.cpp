#include <iostream>

int main(int argc, char **argv)
{
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++)
    {
        int a,b;
        std::cin>>a>>b;
        std::cout<<(a<b?'<':(a>b?'>':'='))<<std::endl;
    }
    return 0;
}
