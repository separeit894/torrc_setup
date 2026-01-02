#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "../SetPathToTorrc/source.h"

namespace fs = std::filesystem;

bool IsThereFileOrNot();
bool CreateFile(std::string TorFileLocation);
void CreateFileConfig();
bool ReadFileConfig(std::vector<std::string> &data);