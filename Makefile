OS = $(shell echo %OS%)
CXX_COMPILER=g++
all:
	@echo $(OS)
	
ifeq ($(OS), Windows_NT)
	$(CXX_COMPILER) -o torrc_setup.exe main.cpp
else
	@echo Linux
	
	$(CXX_COMPILER) -o torrc_setup main.cpp
endif

