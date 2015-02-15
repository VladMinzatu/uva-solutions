#include <iostream>
/** Get the number of sonars per dimension
  */
inline int sonars(int n)
{
    if(n%3 == 0)
        return n/3;
    return n/3 + 1;
}

int main(int argc, char **argv)
{
    int N;
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        int n,m;
        std::cin>>n>>m;
        // subtract eges and multiply the number of 
        // sonars required per dimension
        std::cout<<sonars(n-2)*sonars(m-2)<<std::endl;
    }
    return 0;
}
