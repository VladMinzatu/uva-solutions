#include <iostream>

int coin_values[5] = {1,5,10,25,50};
long long ways[30001][5];

long long count_ways(int n);

int main(int argc, char **argv)
{
    int n;
    while(std::cin>>n)
    {
        long long cnt = count_ways(n);
        if(cnt == 1)
        {
            std::cout<<"There is only 1 way to produce "<<n<<" cents change."<<std::endl;
        }
        else
        {
            std::cout<<"There are "<<cnt<<" ways to produce "<<n<<" cents change."<<std::endl;
        }
    }
}

long long count_ways(int n)
{
    for(int i = 0; i < 5; i++)
    {
        ways[0][i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        ways[i][0] = 1;
        for(int j = 1; j < 5; j++)
        {
            ways[i][j] = ways[i][j-1];
            if(i >= coin_values[j])
            {
                ways[i][j] += ways[i - coin_values[j]][j];
            }
        }
    }
    return ways[n][4];
}
