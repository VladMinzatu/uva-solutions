#include <iostream>
#include <string>
#include <vector>

void initWords(std::vector<std::string>& words);

int main(int argc, char **argv)
{
    int n;
    std::cin>>n;
    std::vector<std::string> names;
    std::vector<std::string> words;
    initWords(words);

    for(int i = 0; i < n; i++)
    {
        std::string name;
        std::cin>>name;
        names.push_back(name);
    }

    int reps = (n%16 ? n/16 + 1 : n/16);
    int nameIndex = 0;
    for(int i = 0; i < reps; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            std::cout<<names[nameIndex]<<": "<<words[j]<<std::endl;
            nameIndex = (nameIndex + 1)%names.size();
        }
    }
    return 0;
}

void initWords(std::vector<std::string>& words)
{
     words.push_back("Happy");
     words.push_back("birthday");
     words.push_back("to");
     words.push_back("you");
     words.push_back("Happy");
     words.push_back("birthday");
     words.push_back("to");
     words.push_back("you");
     words.push_back("Happy");
     words.push_back("birthday");
     words.push_back("to");
     words.push_back("Rujia");
     words.push_back("Happy");
     words.push_back("birthday");
     words.push_back("to");
     words.push_back("you");
}
