#include <string>
#include <list>
#include <map>
#include <boost/serialization/access.hpp>
#define CONTADOR_PALABRAS map<string, int>
#define I_CP CONTADOR_PALABRAS::iterator
#define P_CP(iterator) (*iterator).first
#define C_CP(iterator) (*iterator).second

using namespace std;
class User;
class Badge;
class Link;
class Post;
class Comment;
class Vote;
class History;


class User{

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version){
		ar & reputation;
		ar & creation_date;
		ar &  display_name;
		ar &  last_access_date;
		ar &  web_site_url;
		ar &  profile_image_url;
		ar &  location;
		ar &  up_votes;
		ar &  down_votes;
		ar &  about_me;
		ar &  views;
		ar &  account_id;
		ar &  age;
		//ar &  badges;
	}
public:
	int reputation;
	long int creation_date;
	string display_name;
	long int last_access_date;
	string web_site_url;
	string profile_image_url;
	string location;
	int up_votes;
	int down_votes;
	string about_me;
	int views;
	int account_id;
	int age;
	
	list <Badge *> badges;
};

class Badge{
	string name;
	long int date;
};

class Link{
	long int creation_date;
	Post* related_post;
	int link_type;
};
class Post{
	Post* parent;
	Post* accepted_answer;
	User* owner;
	User* last_editor;
	int post_type;
	long int creation_date;
	int score;
	int view_count;
	//palabra, count
	CONTADOR_PALABRAS body;
	long int community_owned_date;
	long int closed_date;
	long int last_edit_date;
	long int last_activity_date;
	//palabra, count
	CONTADOR_PALABRAS title;
	int answer_count;
	int comment_count;
	int favorite_count;
	
	
	list <Link*> links;
	list <Comment*> comments;
	list <string> tags;
	list <Vote*> votes;
	list <History*> history;
	
};
class Comment{
	User* user;
	int score;
	//palabra, count
	CONTADOR_PALABRAS text;
	long int creation_date;
};
class Vote{
	int bounty_amount;
	User* user;
	int vote_type;
	long int creation_date;
};