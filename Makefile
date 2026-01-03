OS = $(shell echo %OS%)
CXX_COMPILER=g++
all:
	@echo $(OS)

ifeq ($(OS), Windows_NT)
	$(CXX_COMPILER) -o torrc_setup.exe main.cpp CreateFileConfigAndRead/CreateFileConfigAndRead.cpp ReadFile/ReadFile.cpp SetPathToTorrc/SetPathToTorrc.cpp WriteFile/WriteFile.cpp
else
	@echo Linux
	$(CXX_COMPILER) -o torrc_setup main.cpp CreateFileConfigAndRead/CreateFileConfigAndRead.cpp ReadFile/ReadFile.cpp SetPathToTorrc/SetPathToTorrc.cpp WriteFile/WriteFile.cpp
endif

