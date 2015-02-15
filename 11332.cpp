#include <iostream>

// Computes the sum of n's digits
int f(int n);

int g(int n);

int main(int argc, char **argv)
{
    int n;
    do{
        std::cin>>n;
        if(!n)
            break;

        std::cout<<g(n)<<std::endl;
    }while(true);
    return 0;
}

int f(int n)
{ 
    int sum = 0;
    while(n != 0)
    {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

int g(int n)
{
    while(n >= 10)
        n = f(n);
    return n;
}

