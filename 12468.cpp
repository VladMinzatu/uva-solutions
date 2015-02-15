#include <iostream>

int main(int argc, char **argv)
{
    int a,b;
    do{
        std::cin>>a>>b;
        if(a == -1 && b == -1)
            break;
        int up = (a < b? b - a : 100 - a + b);
        int down = (a < b? a + 100 - b : a - b);
        std::cout<<(up<down ? up : down)<<std::endl;
    }while(true);
    return 0;
}
