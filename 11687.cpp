#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

std::string to_string(int x);

int main(int argc, char **argv)
{
    std::string nr;
    do{
        std::getline(std::cin, nr);
        if(nr == "END")
            break;
        if(nr == "1")
        {
            std::cout<<"1"<<std::endl;
            continue;
        }
        int i = 1;
        int x = nr.size(); // x1
        while(x != 1)
        {
            i++;
            x = to_string(x).size();
        }
        std::cout<<(i+1)<<std::endl;
    }while(true);
    return 0;
}

std::string to_string(int x)
{
    std::stringstream ss;
    ss<<x;
    return ss.str();
}
