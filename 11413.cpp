#include <iostream>
#include <vector>

bool check(int max_capacity, int m, const std::vector<int>& capacities);

int main(int argc, char **argv)
{
    int n,m;
    while(std::cin>>n)
    {
        std::cin>>m;
        std::vector<int> capacities;
        for(int i = 0; i < n; i++)
        {
            int x; std::cin>>x;
            capacities.push_back(x);
        }
        int lo = 1, hi = 1000000000;
        int max_capacity = hi;
        for(int i = 0; i < 40; i++)
        {
            int mid = (lo + hi) / 2;
            if(check(mid, m, capacities))
            {
                max_capacity = mid;
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        std::cout<<max_capacity<<std::endl;
    }
    return 0;
}

bool check(int max_capacity, int m, const std::vector<int>& capacities)
{
    int used_bins = 1;
    int current_capacity = 0;
    for(int i = 0; i < capacities.size(); i++)
    {
        if(capacities[i] > max_capacity)
            return false;
        if(current_capacity + capacities[i] > max_capacity)
        {
            current_capacity = capacities[i];
            used_bins++;
        }
        else
        {
            current_capacity += capacities[i];
        }
    }
    return used_bins <= m;
}
