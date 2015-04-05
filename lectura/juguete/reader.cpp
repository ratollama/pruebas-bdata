#include <iostream>
#include <string>
#include <list>
#include <map>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;

struct Nodo{
	string nombre;
	list<Nodo *> hijos;
	void imprimir(){
		imprimir(0);
	}
	void imprimir(int nivel){
		int x;
		for (x=0; x< nivel; x++){
			cout << "\t";
		}
		cout << this->nombre << endl;
		for(list<Nodo *>:: iterator it = this->hijos.begin(); it != this->hijos.end(); it++){
			(*it)->imprimir(nivel +1);
		}
	}
};

string get_val(xmlNodePtr cur, string prop){
	char * ret;
	ret = (char *) xmlGetProp(cur, (xmlChar *) prop.c_str());
	if(ret == NULL){
		return "";
	}else{
		return ret;
	}
}
void reader_loop(string filename, (f*)(xmlNodePtr)){
	xmlDocPtr doc;
	xmlNodePtr cur;
	cur = xmlDocGetRootElement(doc);
	cur = cur->xmlChildrenNode;
	while(cur != NULL){
		string name;
		name = (char *)cur->name;
		if(name == "row"){
			(f*)(cur);
		}
	}
}


map<int, Nodo *> nodos;

int main(){
	xmlDocPtr doc;
	xmlNodePtr cur;
	doc = xmlReadFile("input.xml", NULL, 0);
	
	cur = xmlDocGetRootElement(doc);
	
	cur = cur->xmlChildrenNode;
	
	while(cur != NULL){
		string name;
		name = (char *)cur->name;
		
		if(name == "row"){
			Nodo * nodo = new Nodo();
			
			string tparent;
			int id;
			
			nodo->nombre = get_val(cur, "Text");
			
			id =  atoi(get_val(cur, "DataID").c_str());
			
			nodos[id] = nodo;
			tparent = get_val(cur, "Parent");
			if(tparent != ""){
				int parent;
				parent =  atoi(tparent.c_str());
				nodos[parent]->hijos.push_back(nodo);
			}
			
			
			
		}
		cur = cur->next;
	}
	nodos[10]->imprimir();
	
	
	return 1;
}
