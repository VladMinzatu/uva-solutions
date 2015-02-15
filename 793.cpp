#include <iostream>
#include <vector>
#include <sstream>

class UnionFind
{
private:
    std::vector<int> rank;
    std::vector<int> parent;
public:
    UnionFind(int n)
    {
        for(int i = 0; i < n; i++)
        {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int findSet(int i)
    {
        if(i == parent[i]) 
            return i;
        else
            return parent[i] = findSet(parent[i]);
    }

    void unionSet(int i, int j)
    {
        int x = findSet(i);
        int y = findSet(j);
        if(x != y)
        {
            if(rank[x] > rank[y])
                parent[y] = x;
            else
            {
                parent[x] = y;
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

int main(int argc, char **argv)
{
    int N; 
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        int n;
        std::cin>>n;
        UnionFind network(n + 1);
        std::cin.get();
        std::string line;
        int N1 = 0, N2 = 0;
        while(std::getline(std::cin, line))
        {
            if(line == "")
                break;
            char c; int x,y;
            std::stringstream ss(line);
            ss>>c>>x>>y;
            if(c == 'c')
                network.unionSet(x,y);
            else
                if(network.findSet(x) == network.findSet(y))
                    N1++;
                else
                    N2++;
        }
        std::cout<<N1<<","<<N2<<std::endl;
        if(i < N - 1)
            std::cout<<std::endl;
    }
    return 0;
}
