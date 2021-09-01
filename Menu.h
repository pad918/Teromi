#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "TerminalRenderer.h"
#include "StringMagic.h"
using namespace std::filesystem::__cxx11;


std::vector<directory_entry> getAllEntries(std::string dir_path){
	std::vector<directory_entry> entries;
	for(const auto & entry : std::filesystem::directory_iterator(dir_path)){
		entries.push_back(entry);
	}
	return entries;
}

void file_browser(){

	std::string current_path = std::filesystem::current_path();
	trm::clear_screen();
	//File menau
	while(true){
		std::cout << "Choose an option" << std::endl;
		std::cout << "1. ..." << std::endl;
		auto entries = getAllEntries(current_path);

		//Print all files paths
		int i=2;
		for(auto & path : entries){
			std::cout << i++ << path << std::endl; 
		}
		std::cout << (2+entries.size()) << ". Exit" << std::endl;
		int selected_option = 0;
		std::cin >> selected_option;
		
		if(selected_option == 1){
			//GO UP ONE DIR!!!
			int pos = current_path.size()-getLastOccuranceOfChar(current_path, '/');
			removeEveryThingBefore(current_path, pos);
			continue;
		}
		else if(selected_option > 1 && selected_option < entries.size()){
			auto & entry = entries[selected_option-2];
			if(entry.is_directory()){
				current_path = entry.path();
			}
			else if (entry.is_regular_file())
			{
				//Only list .lyr files
				
			}
			
			continue;
		}
		else{
			break;
		}
	}
}

inline void main_menu(){
	bool is_running = true;
	while(is_running){
		trm::clear_screen();
		
		//Print options:
		std::cout << "Main Menu:" << std::endl;
		std::cout << "1. Load file" << std::endl;
		std::cout << "2. Exit" << std::endl;
		int selected_option = 0;
		std::cin >> selected_option;

		switch (selected_option)
		{
		case 1:
			file_browser();
			break;
		case 2:
			is_running = false;
			continue;
		default:
			continue;
		}

	}
	std::cout << "Exited program\n";
}
