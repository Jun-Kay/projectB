#pragma once
#include "Observer.h"
#include <vector>
using namespace std;

class Accessibility
{
public:
	Accessibility() {}
	~Accessibility() {}

	virtual void update(vector<Observer*> oblist, int userid, int itemid, string content) = 0;
	virtual bool getAcs() = 0;
};