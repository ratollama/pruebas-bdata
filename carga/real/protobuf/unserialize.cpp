#include "model.pb.h"
#include "model.pb.cc"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
int main(){
	modelo::UserCollection usuarios;
	fstream input("usuarios.pb", ios::in | ios::binary);
	usuarios.ParseFromIstream(&input);
	long total = 0;
	for (int j = 0; j < usuarios.usuarios_size(); j++) {
		const modelo::User& usuario = usuarios.usuarios(j);
		total += usuario.up_votes();
		total -= usuario.down_votes();
	}
	cout << total << endl;
	//sleep(10);
	
}
