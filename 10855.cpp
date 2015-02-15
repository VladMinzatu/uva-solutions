#include <iostream>
#include <string>
#include <vector>

void readSquare(std::vector<std::string>& square, int dim);

void rotate(std::vector<std::string>& square, int n);

int occurrences(std::vector<std::string>& smallSquare, std::vector<std::string>& bigSquare, int N, int n);

int main(int argc, char **argv)
{
    int N,n;
    while(true)
    {
        std::cin>>N>>n;
        if(!N && !n)
            break;
        std::vector<std::string> bigSquare;
        std::vector<std::string> smallSquare;
        readSquare(bigSquare, N);
        readSquare(smallSquare, n);
        for(int i = 0; i < 4; i++)
        {
            int found = occurrences(smallSquare, bigSquare, N, n);
            std::cout<<found;
            if(i < 3)
                std::cout<<" ";
            rotate(smallSquare, n);
        }
        std::cout<<std::endl;
    }
    return 0;
}

void readSquare(std::vector<std::string>& square, int dim)
{
    for(int i = 0; i < dim; i++)
    {
        std::string line;
        std::cin>>line;
        square.push_back(line);
    }
}

void rotate(std::vector<std::string>& square, int n)
{
    for(int i=0; i<n/2; i++)
        for(int j=0; j<(n+1)/2; j++)
        {
            int temp = square[i][j];
            square[i][j] = square[n-1-j][i];
            square[n-1-j][i] = square[n-1-i][n-1-j];
            square[n-1-i][n-1-j] = square[j][n-1-i];
            square[j][n-1-i] = temp;
        }
}

int occurrences(std::vector<std::string>& smallSquare, std::vector<std::string>& bigSquare, int N, int n)
{
    int result = 0;
    for(int i = 0; i <= N - n; i++)
        for(int j = 0; j <= N - n; j++)
        {
            bool same = true;
            for(int ii = 0; ii < n; ii++)
                for(int jj = 0; jj < n; jj++)
                 {
                    if(smallSquare[ii][jj] != bigSquare[i + ii][j + jj])
                        same = false;
                 }
            if(same)
                result++;
        }
    return result;
}
