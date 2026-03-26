#include <iostream>
#include <string>
#include "create_file_config_and_read/CreateFileConfigAndRead.h"
#include "read_file/ReadFile.h"
#include "set_path_to_torrc/SetPathToTorrc.h"
#include "write_file/WriteFile.h"

float VERSION = 0.8;
std::vector<std::string> data;

std::string equalSigns(40, '=');

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
        std::cout << std::endl << equalSigns << std::endl <<
        "file read config/config.txt" << std::endl
        << equalSigns << std::endl;
    } else
    {
        std::cerr << std::endl << equalSigns << std::endl << 
        "file not read config/config.txt" 
        << equalSigns << std::endl;
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



