#include <iostream>

int main(int argc, char **argv)
{
    while(true)
    {
        int n,a,b;
        std::cin>>n;
        if(!n)
            break;
        a = b = 0;
        bool odd = true;
        while(n)
        {
            // turn off bits from n, in succession
            // and add them to a and b alternatively
            int bit = (n^(n&(n-1)));
            n &= (n-1);
            if(odd)
                a |= bit;
            else
                b |= bit;
            odd = !odd;
        }
        std::cout<<a<<" "<<b<<std::endl;
    }
    return 0;
}
