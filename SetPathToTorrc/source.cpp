#include "source.h"

std::string SetLocationFileTor()
{
    std::string TorFileLocation;
    std::cout << "Enter tor file location (without quotes): ";
    std::getline(std::cin, TorFileLocation);
    return TorFileLocation;
}

std::string ReadLocationFileTor(std::vector<std::string> data)
{
    
    size_t pos = data[0].find(":");
    std::string location;
    if(pos != std::string::npos)
    {
        location = data[0].substr(++pos);
        std::cout << location << std::endl;
    } else
    {
        std::cerr << "Not find torrc location" << std::endl;
    }

    return location;
}

void SetNewPathTorrc(std::vector<std::string> &data)
{
    size_t pos = data[0].find(":");
    std::string location;
    std::string NewLocation;
    if(pos != std::string::npos)
    {
        location = data[0].substr(0, ++pos);
        std::cin >> NewLocation;
        location += NewLocation;
        data[0] = location;
    } else
    {
        std::cerr << "Not find torrc location" << std::endl;
    }

    
}

void WriteNewPathTorrc(std::vector<std::string> const data)
{
    std::ofstream fileOpenWrite("config/config.txt");
    if(fileOpenWrite.is_open())
    {
        for(std::string line : data)
        {
            fileOpenWrite << line << std::endl;
        }
    } else
    {
        std::cerr << "Error" << std::endl;
    }
    fileOpenWrite.close();
}