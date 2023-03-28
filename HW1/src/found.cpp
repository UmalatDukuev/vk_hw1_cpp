#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> Split(std::string str, char sep){
	std::stringstream ss(str);
	std::string temporary;
	std::vector<std::string> result;
	while (std::getline(ss, temporary, sep)){
		result.push_back(temporary);
	}
	return result;
}


std::string FoundTheDate(std::istream &file, std::string name){
	while (file){
		std::string str;
		getline(file, str, '\n');
		std::vector<std::string> vect;
		if (str != ""){
			vect = Split(str, '\t');
  			if (vect[2] == name){
  				return vect[5];
			}
		} 
	}
	return "";
}


int main(int argc, char *argv[]){ 
	std::string artist_alias_path;
	if (argc != 4){
		std::cout << "Invalid number of arguments!" << std::endl;
		return -1;
	}
	
	for (size_t i = 2; i < argc; i+=2){
		std::string arg(argv[i]);
		if (arg == "--artist_alias_path")
			artist_alias_path = std::string(argv[i+1]);
	}
	
	std::ifstream file(artist_alias_path);
	if (!file){
		std::cout << "Something went wrong while opening file" << std::endl;
		return -1;
	}
	
	std::string name = argv[1]; 
	std::string date = FoundTheDate(file, name);
	if (date != ""){
		std::cout <<"Дата создания: " << date << std::endl;
	}
	else{
		std::cout << "Name not found!" << std::endl;
	}
	
	file.close();
	return 0;
}
