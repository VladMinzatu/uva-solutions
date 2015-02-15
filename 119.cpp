#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(int argc, char **argv)
{
    int n;
    int first = true;

    while(std::cin>>n)
    {
        if(first)
            first = !first;
        else
            std::cout<<std::endl;

        std::vector<std::string> names;
        std::map<std::string, int> indices;
        std::vector<int> balance;
        for(int i = 0; i < n; i++)
        {
            std::string name;
            std::cin>>name;
            names.push_back(name);
            indices[name] = i;
            balance.push_back(0);
        }

        for(int i = 0; i < n; i++)
        {
            std::string giver;
            std::cin>>giver;
            int sum, nofReceivers;
            std::cin>>sum>>nofReceivers;
            
            int given = sum;
            if(nofReceivers > 0)
                given /= nofReceivers;
            
            int retained = sum - nofReceivers * given;

            // adjust budgets
            balance[indices[giver]] += (retained - sum);
            for(int j = 0; j < nofReceivers; j++)
            {
                std::string receiver;
                std::cin>>receiver;
                balance[indices[receiver]] += given;
            }
        }

        for(int i = 0; i < n; i++)
        {
            std::cout<<names[i]<<" "<<balance[i]<<std::endl;
        }
    }
    return 0;
}
