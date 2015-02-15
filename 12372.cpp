#include <iostream>

int main(int argc, char **argv)
{
    int T,case_nr;
    case_nr = 0;
    std::cin>>T;
    for(int i = 0; i < T; i++)
    {
        int L,W,H;
        std::cin>>L>>W>>H;
        bool good = (L <= 20 && W <= 20 && H <= 20);
        std::cout<<"Case "<<(++case_nr)<<": "<<(good?"good":"bad")<<std::endl;
    }
    return 0;
}
