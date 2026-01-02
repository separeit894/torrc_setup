OS = $(shell echo %OS%)
CXX_COMPILER=g++
all:
	@echo $(OS)
	
ifeq ($(OS), Windows_NT)
	$(CXX_COMPILER) -o torrc_setup.exe main.cpp CreateFileConfigAndRead/source.cpp ReadFile/source.cpp SetPathToTorrc/source.cpp WriteFile/source.cpp
else
	@echo Linux
	$(CXX_COMPILER) -o torrc_setup main.cpp CreateFileConfigAndRead/source.cpp ReadFile/source.cpp SetPathToTorrc/source.cpp WriteFile/source.cpp
endif

