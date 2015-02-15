#include <iostream>
#include <bitset>

int main(int argc, char **argv)
{
    while(true)
    {
        int n,m;
        std::cin>>n>>m;
        if(!n && !m)
            break;

        std::bitset<1000000> b;
        bool conflict = false;
        for(int i = 0; i < n; i++)
        {
            int start, end;
            std::cin>>start>>end;
            for(int j = start; j < end; j++)
            {
                if(b.test(j))
		{
                    conflict = true;
		    break;
		}
                b.set(j);
            }
        }

        for(int i = 0; i < m; i++)
        {
            int start, end, period;
            std::cin>>start>>end>>period;
            int k = 0;
            while(true)
            {
                for(int j = start + k*period; j < end + k*period; j++)
                {
                    if(j < 1000000)
                    {
                        if(b.test(j))
			{
                            conflict = true;
			    break;
			}
                        b.set(j);
                    }
                }
                k++;
                if(start + k*period >= 1000000)
                    break;
            }
        }

        if(conflict)
            std::cout<<"CONFLICT"<<std::endl;
        else
            std::cout<<"NO CONFLICT"<<std::endl;
    }
    return 0;
}
