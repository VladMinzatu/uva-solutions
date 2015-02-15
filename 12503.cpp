#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int n;
        std::string instruction;
        std::cin>>n;
        std::vector<int> instructions;
        int position = 0;
        for(int j = 0; j < n; j++)
        {
            std::cin>>instruction;
            if(instruction == "LEFT")
            {
                instructions.push_back(-1);
                position--;
            }
            else if(instruction == "RIGHT")
            {
                instructions.push_back(1);
                position++;
            }
            else
            {
                int pastInstruction;
                std::cin>>instruction;// read the 'AS'
                std::cin>>pastInstruction;
                pastInstruction--;
                instructions.push_back(instructions[pastInstruction]);
                if(instructions[pastInstruction] == 1)
                    position++;
                else
                    position--;
            }
        }

        std::cout<<position<<std::endl;
    }
    return 0;
}
