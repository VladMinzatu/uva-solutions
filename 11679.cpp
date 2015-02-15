#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int N,B;
    do{
        std::cin>>B>>N;
        if(!B && !N)
            break;
        // keep track of each bank's balance
        std::vector<int> balance;
        for(int i = 0; i < B; i++)
        {
            int R;
            std::cin>>R;
            balance.push_back(R);
        }
        
        for(int i = 0; i < N; i++)
        {
            int debtor, creditor, debenture;
            std::cin>>debtor>>creditor>>debenture;
            balance[debtor-1] -= debenture;
            balance[creditor-1] += debenture;
        }

        bool S = true;
        for(int i = 0; i < B; i++)
        {
            if(balance[i] < 0)
                S = false;
        }

        std::cout<<(S?"S":"N")<<std::endl;
    }while(true);

    return 0;
}
