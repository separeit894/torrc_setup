#include "source.h"

std::vector<std::string> ReadFileTorrc(std::string TorFileLocation)
{
    std::ifstream fileTor;
    std::vector<std::string> dataTorrc;
    fileTor.open(TorFileLocation);
    if(fileTor.is_open())
    {
        std::string line;
        while(std::getline(fileTor, line))
        {
            dataTorrc.push_back(line);
        }
        return dataTorrc;
    } else
    {
        return dataTorrc;
    }
}