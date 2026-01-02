#include "source.h"
#include "../ReadFile/source.h"

bool WriteMost(std::string TorFileLocation, std::vector<std::string> NewMost)
{
    std::vector<std::string> dataTorrc = ReadFileTorrc(TorFileLocation);
    int NumStrStartBridge = 0;
    std::cout << "Data size vector : " << dataTorrc.size() << std::endl;
    for(int i = 0; i < dataTorrc.size(); i++)
    {
        std::string line = dataTorrc[i];
        
        if(line.find("Bridge") == 0)
        {
            NumStrStartBridge = i;
            std::cout << "NumStrStartBridge : " << NumStrStartBridge << std::endl;
            dataTorrc.erase(dataTorrc.begin() + i);
            i--;
        }
        
    }
    
    dataTorrc.insert(dataTorrc.end(), NewMost.begin(), NewMost.end());
    for(std::string lineStr : dataTorrc)
    {
        std::cout << lineStr << std::endl;
    }


    if(WriteFileTorrc(TorFileLocation, dataTorrc))
    {
        return true;
    } else
    {
        return false;
    }
    
}

bool WriteFileTorrc(std::string LocationFileTor, std::vector<std::string> dataTorrc)
{
    std::ofstream fileTorrc;
    fileTorrc.open(LocationFileTor, std::ios::out);
    if(fileTorrc.is_open())
    {
        for(std::string line : dataTorrc)
        {
            fileTorrc << line << std::endl;
        }
        fileTorrc.close();
        return true;
    } else
    {
        std::cerr << "Failed to write data files to Torrc" << std::endl;
        return false;
    }
}

