#include <iostream>
#include <vector>

int land[100][100];

int main(int argc, char **argv)
{
    int M,N;
    do
    {
        std::cin>>M>>N;
        if(M == 0 && N == 0)
            break;
        int maxArea = 0;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
            {
                std::cin>>land[i][j];
                if(land[i][j]) 
                    land[i][j] = -10000;
                else 
                    land[i][j] = 1;
                if(i > 0) land[i][j] += land[i - 1][j];
                if(j > 0) land[i][j] += land[i][j - 1];
                if(i > 0 && j > 0) land[i][j] -= land[i -1][j -1];
            }

        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                for(int k = i; k < M; k++)
                    for(int l = j; l < N; l++)
                    {
                        int area = land[k][l];
                        if(i > 0) area -= land[i-1][l];
                        if(j > 0) area -= land[k][j -1];
                        if(i > 0 && j > 0) area += land[i-1][j - 1];
                        maxArea = maxArea > area ? maxArea : area;
                    }
        std::cout<<maxArea<<std::endl;
    }while(true);
    return 0;
}
