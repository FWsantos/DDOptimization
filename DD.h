#include <iostream>
#include <string>
#include "SCPP.h"

typedef struct vertice Vertice;

typedef struct vertice {
	Vertice *pai;
	std::vector<int> missing_cover;
	std::vector<int> covered_objects;
} Vertice;

class DD
{	
public:
	DD(SCPP P);
	std::vector<std::vector<Vertice>> U;
};