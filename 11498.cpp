#include <iostream>

int main(int argc, char **argv)
{
    int K;
    do{
        std::cin>>K;
        if(K == 0)
            break;
       int N,M;
       std::cin>>N>>M;
       for(int i = 0; i < K; i++)
       {
           int x,y;
           std::cin>>x>>y;
           if(x < N && y > M)
               std::cout<<"NO"<<std::endl;
           else if(x > N && y > M)
               std::cout<<"NE"<<std::endl;
           else if(x > N && y < M)
               std::cout<<"SE"<<std::endl;
           else if(x < N && y < M)
               std::cout<<"SO"<<std::endl;
           else std::cout<<"divisa"<<std::endl;
       }
    }while(true);   

    return 0;
}
