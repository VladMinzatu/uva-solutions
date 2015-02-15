#include <iostream>
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int M,N;
char l,d; // land and discovered characters

char map[20][20];

int floodfill(int x, int y);

int main(int argc, char **argv)
{
    int x,y;
    d = '#';
    while(std::cin>>M>>N)
    {
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                std::cin>>map[i][j];
        std::cin>>x>>y;
        l = map[x][y];
        floodfill(x,y); //already explored

        int max = 0;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                if(map[i][j] == l)
                {
                    int size = floodfill(i, j);
                    if(size > max)
                        max = size;
                }
        std::cout<<max<<std::endl;
    }
}

int floodfill(int x, int y)
{
    if(y == N) y = 0;
    if(y == -1) y = N - 1; 
    if(x < 0 || x >= M || y < 0 || y >= N)
        return 0;
    if(map[x][y] != l) return 0;
    int ans = 1;
    map[x][y] = d;    //mark it discovered
    for(int i = 0; i < 4; i++)
        ans += floodfill(x + dr[i], y + dc[i]);
    return ans;
}
