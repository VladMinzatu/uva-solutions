#include <iostream>

int main(int argc, char **argv)
{
    int N,B,H,W;
    while(std::cin>>N>>B>>H>>W)
    {
        int minPrice = B + 1;
        for(int i = 0; i < H; i++)
        {
            int price;
            std::cin>>price;
            for(int j = 0; j < W; j++)
            {
                int a;
                std::cin>>a;
                if(a >= N)
                {
                    int priceHere = N * price;
                    if(priceHere < minPrice)
                    {
                        minPrice = priceHere;
                        // we could break here, but we have to  
                        // read all room availabilities. oh well...
                    }
                }
            }
        }
        if(minPrice <= B)
            std::cout<<minPrice<<std::endl;
        else 
            std::cout<<"stay home"<<std::endl;
    }
    return 0;
}
