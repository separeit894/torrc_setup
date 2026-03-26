OS = $(shell echo %OS%)
CXX_COMPILER=g++
all:
	@echo $(OS)

ifeq ($(OS), Windows_NT)
	$(CXX_COMPILER) -o torrc_setup.exe main.cpp create_file_config_and_read/CreateFileConfigAndRead.cpp read_file/ReadFile.cpp set_path_to_torrc/SetPathToTorrc.cpp write_file/WriteFile.cpp create_backup_torrc_file/CreateBackupTorrcFile.cpp
else
	@echo Linux
	$(CXX_COMPILER) -o torrc_setup main.cpp create_file_config_and_read/CreateFileConfigAndRead.cpp read_file/ReadFile.cpp set_path_to_torrc/SetPathToTorrc.cpp write_file/WriteFile.cpp create_backup_torrc_file/CreateBackupTorrcFile.cpp
endif

