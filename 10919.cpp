#include <iostream>
#include <set>
#include <string>

int main(int argc, char **argv)
{
    int k,m;
    do{
        std::cin>>k;
        if(!k)
            break;
        std::cin>>m;
        std::set<std::string> taken;
        for(int i = 0; i < k; i++)
        {
            std::string course;
            std::cin>>course;
            taken.insert(course);
        }
        bool degree = true;
        for(int i = 0; i < m; i++)
        {
            int c,r;
            std::cin>>c>>r;
            int taken_count = 0;
            for(int j = 0; j < c; j++)
            {
                std::string course;
                std::cin>>course;
                if(taken.find(course) != taken.end())
                    taken_count++;
            }
            if(taken_count < r)
                degree = false;
        }
        if(degree)
            std::cout<<"yes"<<std::endl;
        else
            std::cout<<"no"<<std::endl;
    }while(true);
    return 0;
}
