#pragma once
#ifndef _WRITEFILE_H_
#define _WRITEFILE_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

bool WriteMost(std::string TorFileLocation, std::vector<std::string> NewMost);
bool WriteFileTorrc(std::string LocationFileTor, std::vector<std::string> dataTorrc);
bool WriteMost(std::string TorFileLocation, std::vector<std::string> NewMost);
#endif
