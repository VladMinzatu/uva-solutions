#include <iostream>
#include <algorithm>
#include <string>

bool compare(char a, char b)
{
	if(tolower(a) == tolower(b))
		return a < b;
	else
		return tolower(a) < tolower(b);
}

int main(int argc, char **argv)
{
    int N;
    std::cin>>N;
    for(int i = 0; i < N; i++)
    {
        std::string letters;
        std::cin>>letters;
        std::sort(letters.begin(), letters.end(), compare);
        do{
            std::cout<<letters<<std::endl;
        }while(std::next_permutation(letters.begin(), letters.end(), compare));
    }
    return 0;
}
