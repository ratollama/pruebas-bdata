#include "xml_utils.cpp"
#include "model.pb.h"
#include "model.pb.cc"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

#define USS(f_name, attr) void f_name(string d){attr(d);}
#define USI(f_name, attr) void f_name(string d){attr(atoi(d.c_str()));}
#define USD(f_name, attr) void f_name(string d){struct tm tm; strptime(d.c_str(), "%Y-%m-%dT%H:%M:%S.%f", &tm); attr(static_cast<long int> (mktime(&tm)));}



using namespace std;

modelo::UserCollection usuarios;

modelo::User* _user;

void init_user(){
	_user = usuarios.add_usuarios();
}

USI(uaccount_id			, _user->set_account_id)
USI(uset_reputation		, _user->set_reputation)
USD(uset_creation_date		, _user->set_creation_date)
USS(uset_display_name		, _user->set_display_name)
USD(uset_last_access_date	, _user->set_last_access_date)
USS(uset_web_site_url		, _user->set_web_site_url)
USS(uset_profile_image_url	, _user->set_profile_image_url)
USS(uset_location		, _user->set_location)
USI(uset_up_votes		, _user->set_up_votes)
USI(uset_down_votes		, _user->set_down_votes)
USS(uset_about_me		, _user->set_about_me)
USI(uset_views			, _user->set_views)
USI(uset_account_id		, _user->set_account_id)
USI(uset_age			, _user->set_age)

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
	fsuser["AccountId"] = uaccount_id;
	fsuser["Age"] = uset_age;
}
void serializar_usuarios(){
	cout << "creando archivo serialziado" << endl;
	fstream output("usuarios.pb", ios::out | ios::trunc | ios::binary);
	usuarios.SerializeToOstream(&output);
}
void mapear_usuarios(){
	poblar_mapeo_usuarios();
	mapper_loop("data/Users.xml", fsuser, init_user);
	cout << "mapeado " << usuarios.usuarios_size() << " usuarios" << endl;
	serializar_usuarios();
}

