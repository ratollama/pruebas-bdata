#include <iostream>
#include <list>
#include <string>
#include <boost/serialization/access.hpp>
#define FILENAME "data"

using namespace std;


class Nodo{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version){
		ar & nombre;
		ar & hijos;
	}
public:
	string nombre;
	list<Nodo* > hijos;
	Nodo(string nombre){
		this->nombre = nombre;
	}
	Nodo(){
		this->nombre = "NN";
	}
	void imprimir(){
		cout << this->nombre << " ";
		for(list<Nodo *>:: iterator it = this->hijos.begin(); it != this->hijos.end(); it++){
			(*it)->imprimir();
		}
	}
}; 
