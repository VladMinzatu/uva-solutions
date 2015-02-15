#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int N;
    while(true)
    {
        std::cin>>N;
        if(!N) break;
        std::vector<int> seq;
        for(int i = 0; i < N; i++)
        {
            int x; std::cin>>x;
            seq.push_back(x);
        }

        int sum = 0, max = 0;
        for(int i = 0; i < N; i++)
        {
            sum += seq[i];
            max = sum > max ? sum : max;
            if(sum < 0) sum = 0;
        }
        if(max <= 0)
            std::cout<<"Losing streak."<<std::endl;
        else
            std::cout<<"The maximum winning streak is "<<max<<"."<<std::endl;
    }
    return 0;
}
