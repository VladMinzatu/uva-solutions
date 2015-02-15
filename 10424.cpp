#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>

// reduces a sum to a single digit through repeated summing
int digit(int sum);

// returns the sum of the digits of x
int digit_sum(int x);

// gets the sum of numeric values of the letters in the name
int get_sum(std::string name);

int main(int argc, char **argv)
{
    std::string name1, name2;
    while(std::getline(std::cin, name1) && std::getline(std::cin, name2))
    {   
        int digit1 = digit(get_sum(name1));
        int digit2 = digit(get_sum(name2));
        if(digit1 > digit2)
        {
            int aux = digit1;
            digit1 = digit2;
            digit2 = aux;
        }
        std::cout<<std::fixed<<std::setprecision(2)<<((double)digit1)/((double)digit2)*100.0<<" %"<<std::endl;
    }
    return 0;
}

int digit(int sum)
{
    if(sum >= 10)
        return digit(digit_sum(sum));
    return sum;
}

int digit_sum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int get_sum(std::string name)
{
    int sum = 0;
    for(int i = 0; i < name.size(); i++)
    {
        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
            sum += (tolower(name[i]) - 'a' + 1);
    }
    return sum;
}
