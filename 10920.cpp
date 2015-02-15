#include <iostream>

void solve(int SZ, int P);

// line and column index shifts
int L[4] = {1, 0, -1, 0};
int C[4] = {0, -1, 0, 1};

int main(int argc, char **argv)
{
    int SZ, P;
    while(true)
    {
        std::cin>>SZ>>P;
        if(!SZ && !P)
            break;
	    solve(SZ,P);
    }
    return 0;
}

void solve(int SZ, int P)
{
    int line, column;
    line = column = (SZ+1)/2;
    int p = 1;
    int direction = 0;  //index in L and C, indicating movement
    int moves = 1;      //number of steps to take in the current direction
    bool even = false;  //used to increment the number of steps only on even iterations
    while(true)
    {
        if(p == P)
        {
            std::cout<<"Line = "<<line<<", column = "<<column<<"."<<std::endl;
            return;
        }
        int steps = moves < P - p ? moves : P - p;  //don't overshoot
        p += steps;
        line += steps*L[direction];
        column += steps*C[direction];
        direction = (direction + 1) % 4;
        if(even)
            moves++;
        even = !even;
    }
}
