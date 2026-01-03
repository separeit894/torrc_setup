#pragma once
#ifndef _SETPATHTOTORRC_H_
#define _SETPATHTOTORRC_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::string SetLocationFileTor();
std::string ReadLocationFileTor(std::vector<std::string> data);
void SetNewPathTorrc(std::vector<std::string> &data);
void WriteNewPathTorrc(std::vector<std::string> const data);
#endif