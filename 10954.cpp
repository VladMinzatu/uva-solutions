#include <iostream>
#include <queue>

int main(int argc, char **argv)
{
    int N;
    while(true)
    {
        std::cin>>N;
        if(!N)
            break;
        std::priority_queue<long long> pq;
        for(int i = 0; i < N; i++)
        {
            int x; std::cin>>x;
            pq.push(-x);
        }
        long long cost = 0; 
        while(pq.size() > 1)
        {
            long long sum = 0;
            sum += pq.top(); pq.pop();
            sum += pq.top(); pq.pop();
            pq.push(sum);
            cost += sum;
        }
        std::cout<<-cost<<std::endl;
    }
    return 0;
}

