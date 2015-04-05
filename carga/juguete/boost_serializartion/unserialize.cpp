#include "base.cpp"

#include <fstream>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/archive/binary_iarchive.hpp>
int main(){
	Nodo* A;
	std::ifstream ifs(FILENAME);
	boost::archive::binary_iarchive ia(ifs);
	ia >> A;
	
	A->imprimir();
	
	return 0;
}
