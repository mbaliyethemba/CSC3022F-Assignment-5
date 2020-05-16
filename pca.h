//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 5
//17 May 2020

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <functional>
#include <numeric>
#include "Eigen/Dense"

#ifndef PCA_H
#define PCA_H

using namespace Eigen;

class pca{
	private:
		std::vector<double> jan, jul;
		std::vector<std::vector<double>> matrix;
	
	public:
		pca(); //constructor
		~pca(); //destructor
		void read_january(); //read the averages of rainfall in january
		void read_july(); //read the averages of rainfall in july
		void find_mean();
};

#endif
