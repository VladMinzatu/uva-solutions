#include <iostream>
#include <vector>

int value(std::string card);

int main(int argc, char **argv)
{
    int n;
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {
        std::string card;
        std::vector<std::string> pile;
        // read the bottom 27 cards
        for(int j = 0; j < 27; j++)
        {
            std::cin>>card;
            pile.push_back(card);
        } 

        int Y = 0;

        // execute steps
        for(int j = 0; j < 3; j++)
        {
            int X = value(pile[pile.size() - 1]);
            Y += X;
            for(int k = 0; k <= (10 - X); k++)
            {
                pile.pop_back();
            }
        }

        // add the remaining cards. need to be read anyway.
        for(int j = 0; j < 25; j++)
        {
            std::cin>>card;
            pile.push_back(card);
        }

        std::cout<<"Case "<<(i + 1)<<": "<<pile[Y - 1]<<std::endl;
    }
    return 0;
}

int value(std::string card)
{
    if(card[0] >= '2' && card[0] <= '9')
        return card[0] - '0';
    return 10;
}
