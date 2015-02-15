#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string line;
    bool open = true;
    while(std::getline(std::cin, line))
    {
        size_t pos = line.find("\"");
        while(pos != std::string::npos)
        {
            if(open)
                line.replace(pos,1,"``");
            else
                line.replace(pos,1,"''");
            open = !open;
            pos = line.find("\"");
        }
        std::cout<<line<<std::endl;
    }
    return 0;
}
