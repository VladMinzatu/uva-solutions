#include <iostream>

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int N;
        std::cin>>N;
        int mileCost = 0;
        int juiceCost = 0;
        for(int j = 0; j < N; j++)
        {
            int seconds;
            std::cin>>seconds;
            mileCost += (seconds/30 + 1) * 10;
            juiceCost += (seconds/60 + 1) * 15;
        }
        std::cout<<"Case "<<(i+1)<<": ";
        if(mileCost < juiceCost)
        {
            std::cout<<"Mile "<<mileCost<<std::endl;
        }
        else if(juiceCost < mileCost)
        {
            std::cout<<"Juice "<<juiceCost<<std::endl;
        } 
        else
        {
            std::cout<<"Mile Juice "<<mileCost<<std::endl;
        }
    }
    return 0;
}
