#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    std::string str;
    int n;
    int case_nr = 0;
    while(std::cin>>str)
    {
        if(str == "")
            break;
        int sum = 0;
        std::vector<int> prefix_sums;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '1')
                sum++;
            prefix_sums.push_back(sum);
        }
        std::cin>>n;
        std::cout<<"Case "<<(++case_nr)<<":"<<std::endl;
        for(int k = 0; k < n; k++)
        {
            int i,j;
            bool yes = false;
            std::cin>>i>>j;
            if(i < j)
            {
                int aux = i;
                i = j; 
                j = aux;
            }
            if((str[i] == '1' && str[j] == '1' && prefix_sums[j] - prefix_sums[i] == (j - i)) ||
                (str[i] == '0' &&  str[j] == '0' && prefix_sums[i] == prefix_sums[j]))
                yes = true;
            if(yes)
                std::cout<<"Yes"<<std::endl;
            else
                std::cout<<"No"<<std::endl;
        }
    }
    return 0;
}
