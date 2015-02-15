#include <iostream>
#include <list>

int main(int argc, char **argv)
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        std::list<char> chars;
        int index = 0;
        while(index < line.size())
        {
            if(line[index] == '[')
            {
                std::list<char> front;
                index++;
                while(index < line.size() && line[index] != '[' && line[index] != ']')
                {
                    front.push_back(line[index]);
                    index++;
                }
                for(std::list<char>::reverse_iterator it = front.rbegin(); it != front.rend(); it++) 
                    chars.push_front(*it);
            } else if(line[index] == ']')
            {
                index++;
            } else{
                chars.push_back(line[index]);
                index++;
            }
        }
        std::cout<<std::string(chars.begin(), chars.end())<<std::endl;
    }
    return 0;
}
