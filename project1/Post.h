#pragma once
#include <string>
#include "Subject.h"
#include "AcsPrivate.h"
#include "AcsPublic.h"
using namespace std;

class Post 
	: public Subject
{
public:
	Post();
	~Post();

	int getUserId();
	int getItemId();
	string getContent();
	bool getAcs();

	void setUserId(int _userId);
	void setItemId(int _itemId);
	void setContent(string _ct);
	void setAcs(bool _acs);

private:
	int userId;
	int itemId;
	string content;
	Accessibility* acs;
};

