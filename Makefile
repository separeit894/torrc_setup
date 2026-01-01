OS = $(shell echo %OS%)
all:
	@echo $(OS)
	
ifeq ($(OS), Windows_NT)
	@call prompt.bat
	$(shell echo %CXX_COMPILER%) -o torrc_setup.exe main.cpp
else
	@echo Linux
	@read -p "Enter compiler : " CXX_COMPILER
	$(CXX_COMPILER) -o torrc_setup main.cpp
endif

