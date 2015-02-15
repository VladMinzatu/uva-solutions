#include <iostream>

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int n;
        std::cin>>n;

        int y1,y2;
        bool yes = true;
        std::cin>>y1>>y2;
        int diff = y1-y2;

        for(int j = 0; j < n - 1; j++)
        {
            std::cin>>y1>>y2;
            if(y1 - y2 != diff)
                yes = false;
        }

        std::cout<<(yes?"yes":"no")<<std::endl;

        if(i < T -1)
            std::cout<<std::endl;
    }
    return 0;
}
