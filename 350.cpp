#include <iostream>

int f(int Z, int L, int I, int M);
int cycleLength(int Z, int L, int I, int M);

int main(int argc, char **argv)
{
    int Z,I,M,L,n = 0;
    while(std::cin>>Z>>I>>M>>L && M > 0)
    {
        std::cout<<"Case "<<(++n)<<": "<<cycleLength(Z,L,I,M)<<std::endl;
    }
    return 0;
}

int f(int Z, int L, int I, int M)
{
    return (Z*L + I)%M;
}

int cycleLength(int Z, int L, int I, int M)
{
    int i = f(Z, L, I, M), j = f(Z, f(Z, L, I, M), I, M);
    while(i != j) { i = f(Z, i, I, M); j = f(Z, f(Z, j, I, M), I, M); }
    j = L;
    while(i != j) { i = f(Z, i, I, M); j = f(Z, j, I, M); }
    i = j; j = f(Z, i, I, M); int length = 1;
    while(i != j) { j = f(Z, j, I, M); length++; }
    return length;
}
