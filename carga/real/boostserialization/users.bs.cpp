#include "clases.cpp"
#include "xml_utils.cpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/assume_abstract.hpp>

#define USS(f_name, attr) void f_name(string d){attr = d;}
#define USI(f_name, attr) void f_name(string d){attr = atoi(d.c_str());}
#define USD(f_name, attr) void f_name(string d){struct tm tm; strptime(d.c_str(), "%Y-%m-%dT%H:%M:%S.%f", &tm); attr = static_cast<long int> (mktime(&tm));}



using namespace std;

list<User *> usuarios;

User* _user;

void init_user(){
	_user = new User();
	usuarios.push_back(_user);
}
void uadd_to_map(string c){
	int id;
	id = atoi(c.c_str());
	_user->account_id = id;
}

USI(uset_reputation		, _user->reputation)
USD(uset_creation_date		, _user->creation_date)
USS(uset_display_name		, _user->display_name)
USD(uset_last_access_date	, _user->last_access_date)
USS(uset_web_site_url		, _user->web_site_url)
USS(uset_profile_image_url	, _user->profile_image_url)
USS(uset_location		, _user->location)
USI(uset_up_votes		, _user->up_votes)
USI(uset_down_votes		, _user->down_votes)
USS(uset_about_me		, _user->about_me)
USI(uset_views			, _user->views)
USI(uset_account_id		, _user->account_id)
USI(uset_age			, _user->age)

map<string, sfunc_t > fsuser;

void poblar_mapeo_usuarios(){
	fsuser["Reputation"] = uset_reputation;
	fsuser["CreationDate"] = uset_creation_date;
	fsuser["DisplayName"] = uset_display_name;
	fsuser["LastAccessDate"] = uset_last_access_date;
	fsuser["WebsiteUrl"] = uset_web_site_url;
	fsuser["ProfileImageUrl"] = uset_profile_image_url;
	fsuser["Location"] = uset_location;
	fsuser["UpVotes"] = uset_up_votes;
	fsuser["DownVotes"] = uset_down_votes;
	fsuser["AboutMe"] = uset_about_me;
	fsuser["Views"] = uset_views;
	fsuser["AccountId"] = uadd_to_map;
	fsuser["Age"] = uset_age;
}
unsigned long mapSize(const map<int, User*> &map){
	unsigned long size ;
	int noElements = map.size();
	size = sizeof(map);
	
	size += noElements * sizeof(int);
	size += noElements * sizeof(User);
	size += noElements * sizeof(User*);
	return size;
}
void serializar_usuarios(){
	std::ofstream ofs("usuarios.bs");
	boost::archive::binary_oarchive oa(ofs);
	oa << usuarios;
}
void mapear_usuarios(){
	poblar_mapeo_usuarios();
	mapper_loop("data/Users.xml", fsuser, init_user);
	cout << "mapeado " << usuarios.size() << " usuarios" << endl;
	serializar_usuarios();
}

