#include "Post.h"

Post::Post()
{
	userId = 0;
	itemId = 0;
	content = "";
	acs = nullptr;
}

Post::~Post()
{
}

int Post::getUserId()
{
	return userId;
}

int Post::getItemId()
{
	return itemId;
}

string Post::getContent()
{
	return content;
}

bool Post::getAcs()
{
	bool duqn = acs->getAcs();
	return duqn;
}

void Post::setUserId(int _userId)
{
	userId = _userId;
}

void Post::setItemId(int _itemId)
{
	itemId = _itemId;
}

void Post::setContent(string _ct)
{
	content = _ct;
}

void Post::setAcs(bool _acs)
{
	if (true)
	{
		acs = new AcsPublic();
	}
	else
	{
		acs = new AcsPrivate();
	}

}
