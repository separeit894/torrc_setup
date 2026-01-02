#include <iostream>
#include "CreateFileConfigAndRead/source.h"
#include "ReadFile/source.h"
#include "SetPathToTorrc/source.h"
#include "WriteFile/source.h"

float VERSION = 0.6;
std::vector<std::string> data;

int main(int argc, char* argv[])
{
    
    for(int i = 1; i < argc; ++i)
    {
        std::string line = argv[i];
        if(line == "--version" || line == "-v")
        {
            std::cout << "torrc_setup Version: "  << VERSION << std::endl;
            return 0;
        } else if(line == "--new-path-torrc") {
            ReadFileConfig(data);
            SetNewPathTorrc(data);
            WriteNewPathTorrc(data);

            std::cout << "The path to the torrc file has been changed " << std::endl;
            return 0;
        } 
        else if(line == "--help" || line == "-h")
        {
            std::cout << "Torrc Setup - A program that asks you to insert bridges, and then writes it to a torrc file. \n" <<
            "Examples: \n" << "torrc_setup.exe -h " <<  std::endl;
            return 0;
        }
    }
    
    CreateFileConfig();

    std::vector<std::string> NewMost;
    std::string line;
    std::cout << "Enter new most: " << std::endl;
    while(std::getline(std::cin, line))
    {
        if(line.empty()) break;
        NewMost.push_back("Bridge " + line);
    }

    
    if(ReadFileConfig(data))
    {
        std::cout << "file read" << std::endl;
    } else
    {
        std::cerr << "file not read" << std::endl;
        return -1;
    }

    std::string FileLocationTor = ReadLocationFileTor(data);
    bool ResultWriteMost = WriteMost(FileLocationTor, NewMost);
    if(ResultWriteMost)
    {
        std::cout << "Write data succes!" << std::endl;
    } else
    {
        std::cerr << "Write Data not succes!" << std::endl;
        return -1;
    }
    return 0;
}



