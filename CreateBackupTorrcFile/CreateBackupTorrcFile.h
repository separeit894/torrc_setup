#pragma once
#ifndef _CREATEBACKUPTORRCFILE_H_
#define _CREATEBACKUPTORRCFILE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void CreateBackupFileTorrc(std::string TorFileLocation, std::vector<std::string> data);
#endif