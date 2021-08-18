#include <utility>
#include <tuple>
#include <vector>

/**********
	* Set Cover with Pairs Problem (SCPP)
*/
class SCPP{

public:
	/*
		* SCPP() -> contrutor padrão
	*/

	int n_elements, // Número de elementos
			n_objects,	// Número de objetos
			n_pairs;		// Número de pares
	
	/*
		* Pair -> Pares de objetos
	*/
	struct Pair {
		int ob1;
		int ob2;
		std::vector<int> covered_elements;
	};
	std::vector<Pair> data;
};