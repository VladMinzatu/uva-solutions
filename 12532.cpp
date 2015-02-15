#include <iostream>
#include <vector>

// Use a fenwick tree
class FenwickTree
{
private:
    std::vector<int> counts;
public:
    FenwickTree(int n)
    {
        counts.reserve(n + 1);
        for(int i = 0; i <= n; i++)
            counts.push_back(0);
    }
    
    // the sum [1..i]
    int sum(int i)
    {
        int sum = 0;
        for(; i; i -= lsb(i))
            sum += counts[i];
        return sum;
    }

    // the sum [i..j]
    int sum(int i, int j)
    {
        return sum(j) - (i == 1 ? 0:sum(i - 1));
    }
    
    // least significant bit of x
    int lsb(int x){return x & (-x);}

    void adjust(int i, int v)
    {
        for(; i < (int)counts.size(); i+= lsb(i))
            counts[i] += v;
    }
};
int main(int argc, char **argv)
{
    int N,K;
    while(std::cin>>N)
    {
        std::cin>>K;
        std::vector<int> values;
        values.reserve(N + 1);
        values.push_back(0);
        FenwickTree zeros(N);
        FenwickTree negatives(N);
        for(int i = 1; i <= N; i++)
        {
            int x;
            std::cin>>x;
            values.push_back(x);
            if(x == 0)
                zeros.adjust(i, 1);
            else if(x < 0)
                negatives.adjust(i, 1);
        }

        for(int i = 0; i < K; i++)
        {
            char c;
            std::cin>>c;
            if(c == 'C')
            {
                int j,v;
                std::cin>>j>>v;
                if(v == 0)
                {
                    if(values[j] != 0)
                    {
                        zeros.adjust(j, 1);
                    }
                    if(values[j] < 0)
                    {
                        negatives.adjust(j, -1);
                    }
                } 
                else if(v < 0)
                {
                    if(values[j] >= 0)
                    {
                        negatives.adjust(j, 1);
                    } 
                    if(values[j] == 0)
                    {
                        zeros.adjust(j, -1);
                    }
                }
                else // v>0
                {
                    if(values[j] < 0)
                    {
                        negatives.adjust(j, -1);
                    } 
                    else if(values[j] == 0)
                    {
                        zeros.adjust(j, -1);
                    }
                }
                values[j] = v;
            }
            else if(c == 'P')
            {
                int j,k;
                std::cin>>j>>k;
                if(zeros.sum(j,k) > 0)
                    std::cout<<0;
                else if(negatives.sum(j,k)%2)
                    std::cout<<'-';
                else std::cout<<'+';
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}
