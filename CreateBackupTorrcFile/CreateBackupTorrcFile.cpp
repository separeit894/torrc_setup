#include "CreateBackupTorrcFile.h"

void CreateBackupFileTorrc(std::string TorFileLocation, std::vector<std::string> data)
{
    std::string equalSigns(40, '=');

    std::string FullPath = TorFileLocation + "_backup";
    std::cout << std::endl << 
    equalSigns << std::endl << 
    "A backup file will be created at this path : " << FullPath << std::endl << 
    equalSigns << std::endl << std::endl;

    std::ofstream fileBackupTorrc(FullPath);
    if(fileBackupTorrc.is_open())
    {
        for(std::string line : data)
        {
            fileBackupTorrc << line << std::endl;
        }
        fileBackupTorrc.close();
        std::cout << "The File Torrc Backup Was Created Successfully" << std::endl;
    } else
    {
        std::cerr << "Failed to create file backup torrc" << std::endl;
    }
}