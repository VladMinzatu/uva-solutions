#include <iostream>
#include <map>

int main(int argc, char **argv)
{
    int n,m,c;
    int nof_sequence = 0;
    do{
        std::cin>>n>>m>>c;
        if(!n && !m && !c)
            break;

        std::map<int, int> consumption;
        std::map<int, bool> on;
        for(int i = 0; i < n; i++)
        {
            int c_i;
            std::cin>>c_i;
            consumption[i+1] = c_i;
            on[i+1] = false;
        }
       
        int current_consumption = 0;
        int max_consumption = 0;
        for(int i = 0; i < m; i++)
        {
            int device;
            std::cin>>device;
            if(on[device])
            {
                on[device] = false;
                current_consumption -= consumption[device];
            }
            else
            {
                on[device] = true;
                current_consumption += consumption[device];
            }
            
            if(current_consumption > max_consumption)
                max_consumption = current_consumption;
        }
        
        std::cout<<"Sequence "<<(++nof_sequence)<<std::endl;
        if(max_consumption > c)
            std::cout<<"Fuse was blown."<<std::endl;
        else
        {
            std::cout<<"Fuse was not blown."<<std::endl;
            std::cout<<"Maximal power consumption was "<<max_consumption<<" amperes."<<std::endl;
        }
        std::cout<<std::endl;
    }while(true);
    return 0;
}
