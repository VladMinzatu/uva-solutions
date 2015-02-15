#include <iostream>

#define UNVISITED 0
#define VISITED 1

int visited[25][25];
char image[25][25];
int N;

void init_visited();

void dfs(int i, int j);
void check_and_recurse(int i, int j);

int main(int argc, char **argv)
{
    int image_nr = 0;
    while(std::cin>>N)
    {
        image_nr++;
        init_visited();
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                std::cin>>image[i][j];

        int eagles = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(visited[i][j] == UNVISITED && image[i][j] == '1')
                {
                    eagles++;
                    dfs(i,j);
                }
        std::cout<<"Image number "<<image_nr<<" contains "<<eagles<<" war eagles."<<std::endl;
    }
    return 0;
}

void init_visited()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = UNVISITED;
}

void dfs(int i, int j)
{
    visited[i][j] = VISITED;
    check_and_recurse(i - 1, j - 1);
    check_and_recurse(i - 1 , j);
    check_and_recurse(i - 1 , j + 1);
    check_and_recurse(i     , j - 1);
    check_and_recurse(i     , j + 1);
    check_and_recurse(i + 1 , j - 1);
    check_and_recurse(i + 1 , j);
    check_and_recurse(i + 1 , j + 1);
}

// params potentially out of range
void check_and_recurse(int i, int j)
{
    if(i < 0 || j < 0 || i >= N || j >= N)
        return;
    if(image[i][j] == '1' && visited[i][j] == UNVISITED)
        dfs(i,j);
}
