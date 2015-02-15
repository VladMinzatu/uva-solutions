#include <iostream>
#include <map>
#include <iomanip>

int main(int argc, char **argv)
{
    int N;
    std::string line;
    std::cin>>N;
    std::cin.get();
    std::getline(std::cin, line);
    //for each test case
    for(int i = 0; i < N; i++)
    {
        std::map<std::string, int> counts;
        int totalCounts = 0;
        while(std::getline(std::cin, line))
        {
            if(line == "")
                break;
            
            if(counts.find(line) == counts.end())
                counts[line] = 1;
            else
                counts[line] += 1;
            totalCounts++;
        }
        if(totalCounts == 0)
            continue;
        std::map<std::string, int>::iterator it = counts.begin();
        for( ; it != counts.end(); it++)
            std::cout<<it->first<<" "<<std::fixed<<std::setprecision(4)<<(float)it->second/totalCounts*100<<std::endl;
        if(i < N - 1)
            std::cout<<std::endl;
    }
    return 0;
}
