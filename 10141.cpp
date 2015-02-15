#include<iostream>

int main(int argc, char **argv)
{
    int n,p;
    int test_case = 0;
    do{
        std::cin>>n>>p;
        if(!n && !p)
            break;
        for(int i = 0; i < n; i++)
        {
            std::cin.get();
            std::string req;
            std::getline(std::cin, req); 
        }
        std::string best;
        int best_met = -1;
        double best_price = 2000000000;
        for(int i = 0; i < p; i++)
        {
            std::string proposal;
            double d;
            int r;
            std::getline(std::cin, proposal);
            std::cin>>d>>r;
            if(r > best_met)
            {
                best = proposal;
                best_met = r;
                best_price = d;
            }
            else if(r == best_met && d < best_price)
            {
                best = proposal;
                best_price = d;
            }

            for(int j = 0; j < r; j++)
            {
                std::cin.get();
                std::string req;
                std::getline(std::cin, req);
            }
        }

        if(test_case) std::cout<<std::endl;
        std::cout<<"RFP #"<<(++test_case)<<std::endl;
        std::cout<<best<<std::endl;
    }while(true);
    return 0;
}
