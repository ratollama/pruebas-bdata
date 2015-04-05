#include "clases.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/archive/binary_iarchive.hpp>

#define UT list<User*>
using namespace std;
int main(){
	UT usuarios;
	
	std::ifstream ifs("usuarios.bs");
	boost::archive::binary_iarchive ia(ifs);
	ia >> usuarios;
	
	long total = 0;
	for (UT::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
		User* usuario = (*it);
		total += usuario->up_votes;
		total -= usuario->down_votes;
	}
	cout << total << endl;
	//sleep(10);
	
}
