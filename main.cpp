#include <fstream>
#include <sstream>
#include <iostream>     // std::cout
#include <algorithm>
#include "SCPP.h"
// #include "DD.h"

// read_file -> Lê um arquivo apartir de um arquivo passado
SCPP read_file(std::string path_file) {
	int n_elements = 0, 
			n_objects  = 0,
			int_aux    = 0,
			n_pairs    = 0;

	std::string line = "";
	std::vector<int> v_objects = {};

	std::ifstream reader;
	SCPP instance = SCPP();

	std::cout << path_file << std::endl;
	reader.open(path_file, std::ifstream::in);

	if (reader.is_open()) {
		
		reader >> n_elements;
		instance.n_elements = n_elements;
		reader >> n_objects;
		instance.n_objects = n_objects;
		reader >> n_pairs;
		instance.n_pairs = n_pairs;

		instance.data = {};

		for (int i = 0; i < n_pairs; ++i)	{
			SCPP::Pair obj{0,0, {}};

			reader >> obj.ob1;
			reader >> obj.ob2;

			while(std::getline(reader, line)){
				bool teste = false;
				std::istringstream iss(line);
				while(iss >> int_aux){
					teste = true;
					// std::cout << int_aux << "\n";
					obj.covered_elements.push_back(int_aux);
				}

				if (teste) break;
			}
			instance.data.push_back(obj);
		}

		reader.close();
	}
	return instance;
}

void printSCPP(){
	auto a = read_file("ccp1.txt");

	std::cout << a.n_elements << "\n"; 
	std::cout << a.n_objects << "\n"; 
	std::cout << a.n_pairs << "\n";

  for (auto i = a.data.begin(); i != a.data.end(); ++i){

		std::cout << i->ob1 << ", " << i->ob2 << "\n";

		for (int j = 0; j < i->covered_elements.size(); ++j){
			if(j != 0)
    		std::cout << ", " << i->covered_elements[j];
    	else
    		std::cout << i->covered_elements[j];
		}

    std::cout << "\n";
  }
}

int main(int argc, char const *argv[]) {
	printSCPP();
	return 0;
}