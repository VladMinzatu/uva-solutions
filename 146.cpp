#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
    std::string line;
    while(true)
    {
        std::getline(std::cin, line);
        if(line == "#")
            break;
        if(std::next_permutation(line.begin(), line.end()))
            std::cout<<line<<std::endl;
        else
            std::cout<<"No Successor"<<std::endl;
    }
    return 0;
}
