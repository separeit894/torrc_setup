#include "source.h"


bool CreateFile(std::string TorFileLocation)
{
    std::ofstream file;
    file.open("config/config.txt");
    if(file.is_open())
    {
        std::cout << "file \"config.txt\" create!" << std::endl;
        file << "TorFile:" << TorFileLocation <<std::endl;
        return true;

    } else
    {
        return false;
    }
}

void CreateFileConfig()
{
    std::string TorFileLocation;
    if(fs::exists("config") && fs::is_directory("config"))
    {
        if(IsThereFileOrNot())
        {
            std::cout << "file \"config.txt\" there" << std::endl;
        } else {
            std::cout << "file \"config.txt\" not there! Create..." << std::endl;
            TorFileLocation = SetLocationFileTor();
            CreateFile(TorFileLocation);
        }
    }
    else {
        fs::create_directory("config");
        TorFileLocation = SetLocationFileTor();
        CreateFile(TorFileLocation);
    }
}

bool ReadFileConfig(std::vector<std::string> &data_file)
{
    std::ifstream file;
    file.open("config/config.txt");
    if(file.is_open())
    {
        std::string line;
        while(std::getline(file, line))
        {
            data_file.push_back(line);
        }
        return true;
    } else
    {
        std::cerr << "could not determine the file" << std::endl;
        return false;
    }
}

bool IsThereFileOrNot()
{
    if(fs::exists("config/config.txt") && fs::is_regular_file("config/config.txt"))
    {
        
        return true;
    } else
    {
        return false;
    }
}