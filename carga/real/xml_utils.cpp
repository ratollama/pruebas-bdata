#include <string>
#include <functional>
#include <iostream>
#include <map>

#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <libxml/parser.h>
#include <libxml/tree.h>


using namespace std;
using namespace boost;

typedef void (*sfunc_t)(string);
typedef void (*func_t)(void);

void reader_loop(string filename, function<void(xmlNodePtr)> f){
	xmlDocPtr doc;
	xmlNodePtr cur;
	cout << "abriendo " << filename << endl;
	doc = xmlReadFile(filename.c_str(), NULL, 0);
	cur = xmlDocGetRootElement(doc);
	cur = cur->xmlChildrenNode;
	cout << "iniciando loop de lectura" << endl;
	while(cur != NULL){
		string name;
		name = (char *)cur->name;
		if(name == "row"){
			f(cur);
		}
		cur = cur->next;
	}
	cout << "loop de lectura terminado" << endl;
}



string get_val(xmlNodePtr cur, string prop){
	//cout << "obteniendo " << prop << endl;
	char * ret;
	ret = (char *) xmlGetProp(cur, (xmlChar *) prop.c_str());
	if(ret == NULL){
		return "";
	}else{
		return ret;
	}
}


void mapper_func(xmlNodePtr cur, map<string, sfunc_t> mapper, func_t init_function){
	(*init_function)();
	for(map<string, sfunc_t>::iterator iter = mapper.begin(); iter != mapper.end(); ++iter){
		string key;
		string value;
		
		key = iter->first;
		value = get_val(cur, key);
		
		(iter->second)(value);
	}
}

void mapper_loop(string filename, map<string, sfunc_t> mapper, func_t init_function){
	function<void(xmlNodePtr)> mf = bind(mapper_func, _1, mapper, init_function);
	reader_loop(filename, mf);
}


