#pragma once
#include "Observer.h"
#include <vector>
using namespace std;

class Subject
{
public:
	Subject() {}
	~Subject() {}

private:
	vector<Observer*> oblist;
	void setOblist(vector<Observer*>& friendList)
	{
		oblist = friendList;
	}
};

