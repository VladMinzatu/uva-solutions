#include <iostream>

int get_min(int X, int A, int Y, int B, int C);

void update_max(int& min, int candidate);

int main(int argc, char **argv)
{
    do{
        int A,B,C,X,Y;
        std::cin>>A>>B>>C>>X>>Y;
        if(A + B + C + X + Y == 0)
            break;
        int max = 1;    // max, for worst case of the min

        // look at all cases
        update_max(max, get_min(X, A, Y, B, C));
        update_max(max, get_min(X, A, Y, C, B));
        update_max(max, get_min(X, B, Y, A, C));
        update_max(max, get_min(X, B, Y, C, A));
        update_max(max, get_min(X, C, Y, A, B));
        update_max(max, get_min(X, C, Y, B, A));

        if(max > 52)
            std::cout<<-1<<std::endl;
        else
            std::cout<<max<<std::endl;
    }while(true);

    return 0;
}

int get_min(int X, int A, int Y, int B, int C)
{
    int score = 0;
    if(X > A)
        score += 1;
    else 
        score -= 1;

    if(Y > B)
        score += 1;
    else
        score -= 1;

    if(score == -2)
        return 53;
    
    int lowest = 1;
    if(score == 0)  // draw until now
        lowest = C + 1; // must win the last one
        // otherwise, the price has already won it

    while(lowest == X || lowest == A || lowest == Y || lowest == B)
        lowest++;
    return lowest;
}

void update_max(int& max, int candidate)
{
    if(candidate > max)
        max = candidate;
}
