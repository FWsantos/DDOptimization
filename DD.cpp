#include "DD.h"

DD::DD(SCPP P){
	U = {};
	std::vector<Vertice> L = {}, L_next = L;
	int obj_i;
	SCPP::Pair pair_k;
	// Inicializando o vertice raiz
	Vertice r{nullptr, {}, {}};
	// Preenchendo o vetor do que ainda falta ser coberto
	for (int i = 1; i <= P.n_elements; ++i){
		r.missing_cover.push_back(i);
	}
	
	L.push_back(r);
	U.push_back(L);

	for (int i = 0; i < P.n_objects; ++i){
		obj_i = i+1;
		L_next.clear();
		for (int j = 0; j < L.size; ++j){
			auto l_j = L[j];
			auto son = l_j;
			son.pai = &l_j;
			L_next.push_back(son);
			son.covered_elements.push_back(i+1);

			for (int k = 0; k < P.n_pairs; ++k){
	
				pair_k = P.data[k];
	
				if(pair_k.ob1 == obj_i || pair_k.ob2 == obj_i){
					for (int m = 0; m < son.missing_cover.size(); ++m){
						for (auto c_element = pair_k.covered_elements.begin(); c_element != pair_k.covered_elements.end(); ++c_element){
							if(*c_element == son.missing_cover[m]){
								son.missing_cover.erase(son.missing_cover.begin()+m);
							}
						}
					}
				}
			}
			L_next.push_back(son);
		}
		L = L_next;
	}
}