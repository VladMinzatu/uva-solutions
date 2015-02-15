#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

void get_words(std::string line, std::vector<std::string>& words);

int main(int argc, char **argv)
{
    std::string line;
    std::map<std::string, std::set<std::string> > anagrams;

    while(true)
    {
        std::getline(std::cin, line); 
        if(line == "#")
            break;
        std::vector<std::string> words;
        get_words(line, words);
        for(std::vector<std::string>::iterator word = words.begin(); word != words.end(); word++)
        {
            std::string key = *word;
            std::transform(word->begin(), word->end(), key.begin(), ::tolower);
            std::sort(key.begin(), key.end());
            if(anagrams.find(key) == anagrams.end())
            {
                std::set<std::string> s;
                s.insert(*word);
                anagrams[key] = s;
            }
            else
            {
                anagrams[key].insert(*word);
            }
        }
    }
    std::set<std::string> result;
    for(std::map<std::string, std::set<std::string> >::iterator it = anagrams.begin(); it != anagrams.end(); it++)
    {
        if(it->first.size() == 1)
            result.insert(it->second.begin(), it->second.end());
        else if(it->second.size() == 1)
            result.insert(*(it->second.begin()));
    }

    for(std::set<std::string>::iterator it = result.begin(); it != result.end(); it++)
        std::cout<<(*it)<<std::endl;
    return 0;
}

void get_words(std::string line, std::vector<std::string>& words)
{
    int pos = 0;
    while(pos < line.size())
    {
        std::vector<char> chars;
        char c = line[pos];
        while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            chars.push_back(c);
            if(pos < line.size())
                c = line[++pos];
            else 
                break;
        }
        if(chars.size() > 0)
            words.push_back(std::string(chars.begin(), chars.end()));
        else 
            pos++;
    }
}
