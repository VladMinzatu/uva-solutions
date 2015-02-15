#include <iostream>
#include <stdio.h>

int main(int argc, char **argv)
{
    int T;
    int case_nr = 0;
    std::cin>>T;
    std::cin.get();
    for(int i = 0; i < T; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        
        // initialize memory
        int memory[100];
        for(int j = 0; j < 100; j++)
            memory[j] = 0;

        // execute program
        int pointer = 0;
        for(int j = 0; j < line.size(); j++)
        {
            if(line[j] == '>')
                pointer = (pointer < 99 ? pointer + 1 : 0);
            else if(line[j] == '<')
                pointer = (pointer > 0 ? pointer - 1 : 99);
            else if(line[j] == '+')
                memory[pointer] = (memory[pointer] < 255 ? memory[pointer] + 1 : 0);
            else if(line[j] == '-')
                memory[pointer] = (memory[pointer] > 0 ? memory[pointer] - 1 : 255);
        }
    
        // output
        std::cout<<"Case "<<(++case_nr)<<":";
        for(int j = 0; j < 100; j++)
            printf(" %02X", memory[j]);
        std::cout<<std::endl;
    }
    return 0;
}
