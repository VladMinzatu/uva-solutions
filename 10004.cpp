#include <iostream>
#include <vector>
#include <queue>

bool bipartite(std::vector<std::vector<int> >& adj_list);

int main(int argc, char **argv)
{
    while(true)
    {
        int n,l,a,b;
        std::cin>>n;
        if(!n) break;
        std::vector<std::vector<int> > adj_list;
        for(int i = 0; i < n; i++) adj_list.push_back(std::vector<int>());
        std::cin>>l;
        for(int i = 0; i < l; i++)
        {
            std::cin>>a>>b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        if(bipartite(adj_list))
            std::cout<<"BICOLORABLE."<<std::endl;
        else
            std::cout<<"NOT BICOLORABLE."<<std::endl;
    }
    return 0;
}

bool bipartite(std::vector<std::vector<int> >& adj_list)
{
    std::queue<int> q;
    std::vector<int> color;
    for(int i = 0; i < adj_list.size(); i++) color.push_back(-1);
    q.push(0);
    color[0] = 0;
    bool bipart = true;
    while(!q.empty() && bipart)
    {
        int v = q.front(); q.pop();
        for(int i = 0; i < adj_list[v].size(); i++)
        {
            int u = adj_list[v][i];
            if(color[u] == -1)
            {
                color[u] = 1 - color[v];
                q.push(u);
            }
            else if(color[u] == color[v])
            {
                bipart = false; break;
            }
        }
    }
    return bipart;
}
