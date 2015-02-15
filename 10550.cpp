#include <iostream>

int main(int argc, char **argv)
{
    int s,a,b,c;
    while(std::cin>>s>>a>>b>>c)
    {
        if((!s) && (!a) && (!b) && (!c))
            break;
        int degrees = 720 + 360;
        degrees += ((s<a) ? (s + 40 - a): (s - a))*9;
        degrees += ((b<a) ? (b + 40 - a): (b - a))*9;
        degrees += ((b<c) ? (b + 40 - c): (b - c))*9;
        std::cout<<degrees<<std::endl;
    }
    return 0;
}
