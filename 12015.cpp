#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int maxRelevance = -1;
        std::vector<std::string> pages;
        for(int j = 0; j < 10; j++)
        {
            std::string page;
            int relevance;
            std::cin>>page>>relevance;
            if(relevance > maxRelevance)
            {
                pages.clear();
                maxRelevance = relevance;
                pages.push_back(page);
            } 
            else if(relevance == maxRelevance)
            {
                pages.push_back(page);
            }
        }

        std::cout<<"Case #"<<(i+1)<<":"<<std::endl;
        for(int j = 0; j < pages.size(); j++)
        {
            std::cout<<pages[j]<<std::endl;
        }
    }
    return 0;
}
