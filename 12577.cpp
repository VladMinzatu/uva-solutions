#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string line;
    int case_nr = 0;
    do{
        std::cin>>line;
        if(line == "*")
            break;
        if(line == "Hajj")
            std::cout<<"Case "<<(++case_nr)<<": Hajj-e-Akbar"<<std::endl;
        else
            std::cout<<"Case "<<(++case_nr)<<": Hajj-e-Asghar"<<std::endl;
    }while(true);
    return 0;
}
