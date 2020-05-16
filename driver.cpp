//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 5
//17 May 2020

#include "pca.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]){
	pca p; //constructs pca
	p.read_january();
	p.read_july();
	p.find_mean();
}
