#include <iostream>
int lengths[1000][1000];

int longest(const std::string& word);

int main(int argc, char **argv)
{
    int T;
    std::cin>>T;
    std::cin.get();
    while(T--)
    {
        std::string word;
        std::getline(std::cin, word);
        std::cout<<longest(word)<<std::endl;
    }
    return 0;
}

int longest(const std::string& word)
{
    int len = (int)word.size();
    for(int k = 0; k <= len; k++)
    {
        for(int i = 0; i < len - k; i++)
        {
            int l = i, r = i + k;
            if(k == 0)
                lengths[l][r] = 1;
            else if(k == 1)
                lengths[l][r] = (word[l] == word[r]?2:1);
            else if(word[l] == word[r])
                lengths[l][r] = 2 + lengths[l + 1][r - 1];
            else
                lengths[l][r] = (lengths[l][r-1] > lengths[l+1][r] ? lengths[l][r-1] : lengths[l+1][r]);
        }
    }
    return lengths[0][len - 1];
}
