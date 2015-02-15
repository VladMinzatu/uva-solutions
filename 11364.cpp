#include <iostream>

int main(int argc, char **argv)
{
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n,l,r;
        l = 99; r = 0;
        std::cin>>n;
        for(int j = 0; j < n; j++)
        {
            int x;
            std::cin>>x;
            l = x < l? x : l;
            r = x > r? x : r;
        }
        std::cout<<2*(r - l)<<std::endl;

    }
    return 0;
}
