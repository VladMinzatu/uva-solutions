#include <iostream>

int main(int argc, char **argv)
{
        int n;
        std::cin>>n;
        std::cin.get();
        for(int i = 0; i < n; i++)
        {
                std::string line;
                std::getline(std::cin, line);
                int nof_M = 0;
                int nof_F = 0;
                for(int j = 0; j < line.size(); j++)
                {
                        if(line[j] == 'M')
                                nof_M++;
                        else if(line[j] == 'F')
                                nof_F++;
                }
                if(nof_M == nof_F && nof_M > 1)
                        std::cout<<"LOOP"<<std::endl;
                else
                        std::cout<<"NO LOOP"<<std::endl;
        }
        return 0;
}
