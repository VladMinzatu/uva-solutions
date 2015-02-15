#include <iostream>

int main(int argc, char **argv)
{
    int A, C;
    do{
        std::cin>>A;
        if(!A)
            break;
        std::cin>>C;
        int prev_height, height;
        std::cin>>prev_height;

        int laser_actions = A - prev_height;
        for(int i = 1; i < C; i++)
        {
            std::cin>>height;
            if(height < prev_height)
                laser_actions += (prev_height - height);
            prev_height = height;
        }
        std::cout<<laser_actions<<std::endl;
    }while(true);
}
