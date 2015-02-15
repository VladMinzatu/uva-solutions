#include <iostream>

int main(int argc, char **argv)
{
    int n,case_nr;
    case_nr = 0;
    do{
        std::cin>>n;
        if(n == 0)
            break;
        int balance = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            std::cin>>x;
            if(x > 0)
                balance++;
            else
                balance--;
        }
        std::cout<<"Case "<<(++case_nr)<<": "<<balance<<std::endl;
    }while(true);
    return 0;
}
