#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string str, char sep){
	std::stringstream ss(str);
	std::vector<std::string> res(10, "");
	std::string temporary;
	std::vector<std::string> result;
	while (std::getline(ss, temporary, sep)){
		result.push_back(temporary);
	}
	if (result.size()>0){
		return result;}
	else{
		return res;
	}
}

std::string func(std::ifstream &file, std::string name){
	while (file){
		std::string str;
		getline(file, str, '\n');
		std::vector<std::string> vect;
		vect = split(str, '\t');
  		if (vect[2] == name){
  			return vect[5];
		} 
	}
	return "";
}


int main(int argc, char *argv[]){ 
	//std::ifstream file("artist_alias");
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
	std::string name = argv[1]; 
	if (file){	
		std::string date = func(file, name);
		if (date != ""){
			std::cout <<"Дата создания: " << date << std::endl;
		}
		else{
			std::cout << "Name not found!" << std::endl;
		}
	}
	else{
		std::cout << "No such file as" << std::endl;
	}
	
	file.close();
	return 0;
}

