#include "base.cpp"

#include <fstream>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

int main(){

	Nodo* A = new Nodo("A");
	Nodo* B = new Nodo("B");
	Nodo* C = new Nodo("C");
	
	Nodo Z = *C;
	
	A->hijos.push_back(B);
	A->hijos.push_back(C);
	
	A->imprimir();
	
	std::ofstream ofs("data");
	boost::archive::binary_oarchive oa(ofs);
	oa << A;
	
	
	return 0;
}