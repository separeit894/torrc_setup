#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

bool IsThereFileOrNot();
bool CreateFile(std::string TorFileLocation);
bool ReadFile(std::vector<std::string> &data);
bool WriteMost(std::string TorFileLocation, std::vector<std::string> NewMost);
std::string LocationFileTor();
std::string ReadLocationFileTor(std::vector<std::string> data);
std::vector<std::string> ReadFileTorrc(std::string TorFileLocation);


int main(int argc, char* argv[])
{
    
    for(int i = 1; i < argc; ++i)
    {
        std::string line = argv[i];
        if(line == "--help" || line == "-h")
        {
            std::cout << "Yep" << std::endl;
            return 0;
        }
    }
    
    std::string TorFileLocation;
    if(fs::exists("config") && fs::is_directory("config"))
    {
        if(IsThereFileOrNot())
        {
            std::cout << "file \"config.txt\" there" << std::endl;
        } else {
            std::cout << "file \"config.txt\" not there! Create..." << std::endl;
            TorFileLocation = LocationFileTor();
            CreateFile(TorFileLocation);
        }
    }
    else {
        fs::create_directory("config");
        // std::cout << "directory create!!" << std::endl;
        TorFileLocation = LocationFileTor();
        CreateFile(TorFileLocation);
    }

    std::vector<std::string> NewMost;
    std::string line;
    while(std::getline(std::cin, line))
    {
        if(line.empty()) break;
        NewMost.push_back("Bridge " + line +"\n");
    }

    std::vector<std::string> data;
    if(ReadFile(data))
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

    } else
    {

    }
    return 0;
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



bool ReadFile(std::vector<std::string> &data_file)
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

bool WriteMost(std::string TorFileLocation, std::vector<std::string> NewMost)
{
    std::vector<std::string> dataTorrc = ReadFileTorrc(TorFileLocation);
    int NumStrStartBridge = 0;
    std::cout << "Data size vector : " << dataTorrc.size() << std::endl;
    for(int i = 0; i <= dataTorrc.size(); i++)
    {
        std::string line = dataTorrc[i];
        
        if(line.find("Bridge") == 0)
        {
            NumStrStartBridge = i;
            std::cout << "NumStrStartBridge : " << NumStrStartBridge << std::endl;
        }
    }

    return true;
}

std::string LocationFileTor()
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