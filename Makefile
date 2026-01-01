CXX = g++

build: 
	$(CXX) -o torrc_setup_x64.exe main.cpp

build32:
	$(CXX) -m32 -o torrc_setup_x32.exe main.cpp