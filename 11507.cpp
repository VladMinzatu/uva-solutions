#include <iostream>
#include <map>
#include <string>

void initShifts(std::map<std::pair<std::string, std::string>, std::string>& shift);

int main(int argc, char **argv)
{
    int L;
    // store the direction-shift possibilities
    std::map<std::pair<std::string, std::string>, std::string> shift;
    initShifts(shift);
    
    do{
        std::cin>>L;
        if(!L)
            break;
        std::string current = "+x";
        for(int i = 0; i < L - 1; i++)
        {
            std::string bend;
            std::cin>>bend;
            current = shift[std::pair<std::string, std::string>(current, bend)]; 
        }
        std::cout<<current<<std::endl;
    }while(true);
    return 0;
}

void initShifts(std::map<std::pair<std::string, std::string>, std::string>& shift)
{
    shift[std::pair<std::string, std::string>("+x", "No")] = "+x";
    shift[std::pair<std::string, std::string>("+x", "+y")] = "+y";
    shift[std::pair<std::string, std::string>("+x", "-y")] = "-y";
    shift[std::pair<std::string, std::string>("+x", "+z")] = "+z";
    shift[std::pair<std::string, std::string>("+x", "-z")] = "-z";

    shift[std::pair<std::string, std::string>("-x", "No")] = "-x";
    shift[std::pair<std::string, std::string>("-x", "+y")] = "-y";
    shift[std::pair<std::string, std::string>("-x", "-y")] = "+y";
    shift[std::pair<std::string, std::string>("-x", "+z")] = "-z";
    shift[std::pair<std::string, std::string>("-x", "-z")] = "+z";
    
    shift[std::pair<std::string, std::string>("+y", "No")] = "+y";
    shift[std::pair<std::string, std::string>("+y", "+y")] = "-x";
    shift[std::pair<std::string, std::string>("+y", "-y")] = "+x";
    shift[std::pair<std::string, std::string>("+y", "+z")] = "+y";
    shift[std::pair<std::string, std::string>("+y", "-z")] = "+y";

    shift[std::pair<std::string, std::string>("-y", "No")] = "-y";
    shift[std::pair<std::string, std::string>("-y", "+y")] = "+x";
    shift[std::pair<std::string, std::string>("-y", "-y")] = "-x";
    shift[std::pair<std::string, std::string>("-y", "+z")] = "-y";
    shift[std::pair<std::string, std::string>("-y", "-z")] = "-y";
    
    shift[std::pair<std::string, std::string>("+z", "No")] = "+z";
    shift[std::pair<std::string, std::string>("+z", "+y")] = "+z";
    shift[std::pair<std::string, std::string>("+z", "-y")] = "+z";
    shift[std::pair<std::string, std::string>("+z", "+z")] = "-x";
    shift[std::pair<std::string, std::string>("+z", "-z")] = "+x";

    shift[std::pair<std::string, std::string>("-z", "No")] = "-z";
    shift[std::pair<std::string, std::string>("-z", "+y")] = "-z";
    shift[std::pair<std::string, std::string>("-z", "-y")] = "-z";
    shift[std::pair<std::string, std::string>("-z", "+z")] = "+x";
    shift[std::pair<std::string, std::string>("-z", "-z")] = "-x";
}
