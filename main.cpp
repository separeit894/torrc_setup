#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

bool IsThereFileOrNot();
bool CreateFile(std::string TorFileLocation);
bool ReadFileConfig(std::vector<std::string> &data);
bool WriteMost(std::string TorFileLocation, std::vector<std::string> NewMost);
std::string LocationFileTor();
std::string ReadLocationFileTor(std::vector<std::string> data);
std::vector<std::string> ReadFileTorrc(std::string TorFileLocation);
bool WriteFileTorrc(std::string LocationFileTor, std::vector<std::string> dataTorrc);
void CreateFileConfig();
void SetNewPathTorrc(std::vector<std::string> &data);
void WriteNewPathTorrc(std::vector<std::string> const data);


float VERSION = 0.5;
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
            TorFileLocation = LocationFileTor();
            CreateFile(TorFileLocation);
        }
    }
    else {
        fs::create_directory("config");
        TorFileLocation = LocationFileTor();
        CreateFile(TorFileLocation);
    }
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
