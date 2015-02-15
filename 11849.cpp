#include <iostream>
#include <set>

int main(int argc, char **argv)
{
    int M,N;
    while(true)
    {
        std::cin>>N>>M;
        if(!N && !M)
            break;
        std::set<int> jack;
        int common = 0;
        for(int i = 0; i < N; i++)
        {
            int cd;
            std::cin>>cd;
            jack.insert(cd);
        }
        for(int i = 0; i < M; i++)
        {
            int cd;
            std::cin>>cd;
            if(jack.find(cd) != jack.end())
                common++;
        }
        std::cout<<common<<std::endl;
    }
    return 0;
}
