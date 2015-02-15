#include <iostream>

int main(int argc, char **argv)
{
    int n;
    std::string letters;
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {
        std::cin>>letters;
        if(letters.length() == 5)
            std::cout<<3<<std::endl;
        else
        {
            // count the mistakes assuming it is a spelling of
            // 'one'. If there are <= 1 mistakes, it must be 1,
            // otherwise it must be 2.
            int mistakes = 0;
            mistakes += (letters[0] != 'o' ? 1 : 0);
            mistakes += (letters[1] != 'n' ? 1 : 0);
            mistakes += (letters[2] != 'e' ? 1 : 0);
            if(mistakes <= 1)
                std::cout<<1<<std::endl;
            else 
                std::cout<<2<<std::endl;
        }
    }
    return 0;
}
