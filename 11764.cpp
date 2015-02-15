#include <iostream>

int main(int argc, char **argv)
{
    int T;
    int nr_cases = 0;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int N;
        std::cin>>N;
        int old_wall;
        std::cin>>old_wall;
        int higher = 0;
        int lower = 0;
        for(int i = 1; i < N; i++)
        {
            int new_wall;
            std::cin>>new_wall;
            if(new_wall > old_wall)
                higher++;
            else if(new_wall < old_wall)
                lower++;
            old_wall = new_wall;
        }
        std::cout<<"Case "<<(++nr_cases)<<": "<<higher<<" "<<lower<<std::endl;
    }
    return 0;
}
