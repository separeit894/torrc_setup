#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    
    
    if(fs::exists("config") && fs::is_directory("config"))
    {
        // std::cout << "directory real";
    }
    else {
        fs::create_directory("config");
        // std::cout << "directory create!!" << std::endl;
    }

    std::string allLines;
    std::string line;
    while(std::getline(std::cin, line))
    {
        if(line.empty()) break;
        allLines += line +"\n";
    }


    
}