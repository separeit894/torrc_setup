#pragma once
#ifndef _CREATEFILECONFIGANDREAD_H_
#define _CREATEFILECONFIGANDREAD_H_

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "../set_path_to_torrc/SetPathToTorrc.h"

namespace fs = std::filesystem;

bool IsThereFileOrNot();
bool CreateFile(std::string TorFileLocation);
void CreateFileConfig();
bool ReadFileConfig(std::vector<std::string> &data);
#endif