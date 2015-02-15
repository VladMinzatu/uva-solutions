#include <iostream>

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int N,max;
        std::cin>>N;
        std::cin>>max;
        for(int j = 1; j < N; j++)
        {
            int c;
            std::cin>>c;
            if(c > max)
                max = c;
        }
        std::cout<<"Case "<<(i+1)<<": "<<max<<std::endl;
    }
    return 0;
}
