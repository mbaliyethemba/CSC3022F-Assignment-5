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
		std::cout << "January Observations has been read" << std::endl;
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
			this->july.push_back(std::stod(s));
		}
		julFile.close();
		std::cout << "July Observations has been read" << std::endl;
	}
	else{
		std::cerr << "Unable to open file." << std::endl;
	}
}

//finds the mean
void pca::find_mean(){
	double jansum = 0;
	//finds the sum for jan
	for(size_t i = 0; i < this->jan.size(); i++){
		jansum += this->jan[i];
	}
	double janmean = jansum / this->jan.size();
	//restructor the jan vector using mean
	for(size_t i = 0; i < this->jan.size(); i++){
		this->jan[i] = janmean - this->jan[i];
	}
	
	double julysum = 0;
	//finds the sum for july
	for(size_t i = 0; i < this->july.size(); i++){
		julysum += this->july[i];
	}
	double julymean = julysum / this->july.size();
	//restructor the july vector using mean
	for(size_t i = 0; i < this->july.size(); i++){
		this->july[i] = julymean - this->july[i];
	}
}

//finds the covariance of matrix
double pca::find_covariance(std::vector<double> x, std::vector<double> y){
	double product = 0;
	for(size_t i = 0; i < x.size(); i++){
		product += x[i] * y[i];
	}
	
	return (product)/(x.size() - 1);
}
