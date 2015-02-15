#include <iostream>

int main(int argc, char **argv)
{
    int N;
    std::cin>>N;
    std::cout<<"Lumberjacks:"<<std::endl;
    for(int i = 0; i < N; i++)
    {
        int l1,l2;
        std::cin>>l1>>l2;
        bool ordered = true;
        bool inc = true;
        if(l1 > l2)
            inc = false;
        
        for(int j = 2; j < 10; j++)
        {
            int l;
            std::cin>>l;
            if((l2 > l && inc) || (l2 < l && !inc))
                ordered = false;
            l2 = l;
        }
        std::cout<<(ordered?"Ordered":"Unordered")<<std::endl;
    }
    return 0;
}
