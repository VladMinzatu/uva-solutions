#include <iostream>

int main(int argc, char **argv)
{
    int H,U,D,F;
    do{
        std::cin>>H>>U>>D>>F;
        if(!H)
            break;
        
        double pos = H;
        double climb = U;
        double fatigue = (((double)F)/100.0)*U;
        int days = 0;
        do{
            days++;
            pos -= climb; // during the day
            if(pos < 0)
            {
                std::cout<<"success on day "<<days<<std::endl;
                break;
            }

            pos += D; // during the night
            
            if(pos > H)
            {
                std::cout<<"failure on day "<<days<<std::endl;
                break;
            }
            climb = (climb - fatigue < 0 ? 0 : climb - fatigue); 
        }while(true);
    }while(true);
    return 0;
}
