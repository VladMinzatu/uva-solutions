#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string line;
    std::string language;
    int case_nr = 0;
    do{
        std::getline(std::cin, line);
        if(line == "#")
            break;

        if(line == "HELLO")    
            language = "ENGLISH";
        else if(line == "HOLA")
            language = "SPANISH";
        else if(line == "HALLO")
            language = "GERMAN";
        else if(line == "BONJOUR")
            language = "FRENCH";
        else if(line == "CIAO")
            language = "ITALIAN";
        else if(line == "ZDRAVSTVUJTE")
            language = "RUSSIAN";
        else language = "UNKNOWN";

        std::cout<<"Case "<<(++case_nr)<<": "<<language<<std::endl;
    }while(true);

    return 0;
}
