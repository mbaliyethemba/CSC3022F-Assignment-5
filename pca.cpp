//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 5
//17 May 2020

#include "pca.h"
#include "Eigen/Dense"

//constructor
pca::pca(){}

//destructor
pca::~pca(){}

//read the averages of rainfall in january
void pca::read_january(){
	std::ifstream janFile("January Observations.txt", std::ios::in);
	if(janFile.is_open()){
		std::string s;
		while(std::getline(janFile, s)){
			this->jan.push_back(std::stod(s));
		}
		janFile.close();
		std::cout << "File has been read" << std::endl;
	}
	else{
		std::cerr << "Unable to open file." << std::endl;
	}
}

//read the averages of rainfall in july
void pca::read_july(){
	std::ifstream julFile("July Observations.txt", std::ios::in);
	if(julFile.is_open()){
		std::string s;
		while(std::getline(julFile, s)){
			this->jul.push_back(std::stod(s));
		}
		julFile.close();
		std::cout << "File has been read" << std::endl;
	}
	else{
		std::cerr << "Unable to open file." << std::endl;
	}
}
