#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int n;
    std::string result;
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {
        std::cin>>result;
        if(result == "1" || result == "4" || result == "78")
            std::cout<<"+"<<std::endl;
        else 
        {
            if(result.compare(result.length() - 2, 2, "35") == 0)
                std::cout<<"-"<<std::endl;
            else if(result[0] == '9' && result[result.length() - 1] == '4')
                std::cout<<"*"<<std::endl;
            else std::cout<<"?"<<std::endl;
        }
    }
    return 0;
}
