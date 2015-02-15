#include <iostream>
#include <map>

int main(int argc, char **argv)
{
    int N;
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        int n;
        std::cin>>n;
        std::map<int, int> indices;
        int start = -1;
        int max_size = 0;
        for(int j = 0; j < n; j++)
        {
            int x;
            std::cin>>x;
            if(indices.find(x) != indices.end())
            {
                start = start > indices[x] ? start : indices[x];
            }
            indices[x] = j;
            int size = j - start;
            if(size > max_size)
                max_size = size;
        }
        std::cout<<max_size<<std::endl;
    }
    return 0;
}
