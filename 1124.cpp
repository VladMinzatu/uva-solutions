#include <iostream>

int main(int argc, char** argv)
{
    std::string equation;
    while(std::getline(std::cin, equation))
    {
        std::cout<<equation<<std::endl;
    }
    return 0;
}
