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
	
	return (product)/63;
}

//set the matrix
void pca::covariance_matrix(){
	std::vector<double> v;
	v.push_back(find_covariance(this->jan, this->jan));
	v.push_back(find_covariance(this->jan, this->july));
	this->matrix.push_back(v);
	v.clear();
	v.push_back(find_covariance(this->july, this->jan));
	v.push_back(find_covariance(this->july, this->july));
	this->matrix.push_back(v);
}

//set the eigen value
void pca::eigen(){
	std::ofstream outfile;
	outfile.open("output_answers.txt");
	if(outfile.is_open()){
		Matrix2f e;
		e << this->matrix[0][0], this->matrix[0][1], this->matrix[1][0], this->matrix[1][1];
		SelfAdjointEigenSolver<Matrix2f> esolver(e);
		if(esolver.info() != Success) abort();
		outfile << "Question 1" << std::endl;
		outfile << "The eigenvalues are:" <<std::endl;
		outfile << "July    : " << esolver.eigenvalues()[1] << std::endl;
		outfile << "January : " << esolver.eigenvalues()[0] << std::endl;
		outfile << " " << std::endl;
		outfile << "**********************" << std::endl;
		outfile << "Question 2" << std::endl;
		outfile << "        | " << "  july  |" << " january" << std::endl;
		outfile << "--------|---------|---------" << std::endl;
		outfile << "July    | " << esolver.eigenvectors().row(1).col(1) << "|" << esolver.eigenvectors().row(1).col(0) << std::endl;
		outfile << "--------|---------|---------" << std::endl;
		outfile << "January | " << esolver.eigenvectors().row(0).col(1) << "|" << esolver.eigenvectors().row(0).col(0) << std::endl;
		outfile << " " << std::endl;
		outfile << "**********************" << std::endl;
		outfile << "Question 3" << std::endl;
		outfile << "        | " << "  july  |" << " january" << std::endl;
		outfile << "--------|---------|---------" << std::endl;
		outfile << "July    | " << matrix[1][1] << " | " << matrix[1][0] << std::endl;
		outfile << "--------|---------|---------" << std::endl;
		outfile << "January | " << matrix[0][1] << " | " << matrix[0][0] << std::endl;
		outfile << " " << std::endl;
		outfile << "**********************" << std::endl;
		outfile << "Question 4" << std::endl;
		outfile << "Variance :\n" << (matrix[0][0] + matrix[1][1]) << std::endl;
		outfile << " " << std::endl;
		outfile << "**********************" << std::endl;
		outfile << "Question 5" << std::endl;
		outfile << "Component 1 with eigenvalue "<< esolver.eigenvalues()[1]<< " explains about "<< lround((esolver.eigenvalues()[1]/(matrix[0][0] + matrix[1][1])) * 100)<<"% of the total variance." <<std::endl;
		outfile << "Component 2 with eigenvalue "<< esolver.eigenvalues()[0] << " explains about " << lround((esolver.eigenvalues()[0]/(matrix[0][0] + matrix[1][1])) * 100)<<"% of the total variance." <<std::endl;
		outfile << "The eigenvalues sum to the total variance." << std::endl;
	}
}

