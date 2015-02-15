#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int b,s, case_nr = 1;
    std::cin>>b;
    while(case_nr <= b)
    {
        std::cin>>s;
        std::vector<int> nice_vec;
        for(int i = 0; i < s - 1; i++)
        {
            int nice; std::cin>>nice;
            nice_vec.push_back(nice);
        }

        int sum = 0, max = 0, start = -1, end = -1, reset = -1;
        for(int i = 0; i < nice_vec.size(); i++)
        {
            sum += nice_vec[i];
            if(sum > max || (sum == max && ((end - start) < (i - reset - 1))))
            {
                start = reset + 1;
                end = i;
                max = sum;
            }
            
            if(sum < 0)
            {
                reset = i;
                sum = 0;
            }
        }

        if(max <= 0)
            std::cout<<"Route "<<case_nr<<" has no nice parts"<<std::endl;
        else
            std::cout<<"The nicest part of route "<<case_nr<<" is between stops "<<(start+1)<<" and "<<(end+2)<<std::endl;
        case_nr++;
    }
    return 0;
}
