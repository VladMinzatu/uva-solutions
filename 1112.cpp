#include <iostream>
#include <vector>
#include <set>

// modified dijkstra that returns the number of 
// nodes at distance at most T from the source, s
int dijkstra(const std::vector<std::vector<std::pair<int, int> > >& adj_list, int s, int T);

int main(int argc, char **argv)
{
    int cases,N,E,T,M;
    std::cin>>cases;
    while(cases--)
    {
        std::cin>>N>>E>>T>>M;
        std::vector<std::vector<std::pair<int, int> > > adj_list;
        for(int i = 0; i < N; i++)
            adj_list.push_back(std::vector<std::pair<int, int> >());
        for(int i = 0; i < M; i++)
        {
            int a,b,t;
            std::cin>>a>>b>>t;
            adj_list[b-1].push_back(std::pair<int, int>(a - 1, t));
        } 
        
        std::cout<<dijkstra(adj_list, E - 1, T)<<std::endl;
        if(cases > 0)
            std::cout<<std::endl;
    }
    return 0;
}

int dijkstra(const std::vector<std::vector<std::pair<int, int> > >& adj_list, int s, int T)
{ //O(|E + V| log(V))
    int result = 0;
    std::vector<int> dist;
    for(int i = 0; i < adj_list.size(); i++) 
        dist.push_back(1000000000);
    dist[s] = 0;

    std::set<std::pair<int, int> > pq;
    for(int i = 0; i < adj_list.size(); i++)  // O(V log(V))
        pq.insert(std::pair<int, int>(dist[i], i));

    while(!pq.empty())
    {
        std::pair<int, int> front = (*pq.begin()); pq.erase(pq.begin()); // pop closest element - O(log(V)) - overall O(V log(V))
        int d = front.first, 
        u = front.second; 
        if(dist[u] <= T)    // explored with optimal dist
            result++;

        for(int i = 0; i < adj_list[u].size(); i++) // overall O(E log(V))
        {
            int d_uv = adj_list[u][i].second;
            int v = adj_list[u][i].first;
            if(dist[u] + d_uv < dist[v])
            {   // update distances
                pq.erase(pq.find(std::pair<int, int>(dist[v], v))); //O(log(V))
                dist[v] = dist[u] + d_uv;
                pq.insert(std::pair<int, int>(dist[v], v)); //O(log(V))
            }
        }
    }
    return result;
}
