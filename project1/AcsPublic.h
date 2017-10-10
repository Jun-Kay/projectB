#pragma once
#include "Accessibility.h"
class AcsPublic :
	public Accessibility
{
public:
	AcsPublic() {}
	~AcsPublic() {}

	void update(vector<Observer*> oblist, int userid, int itemid, string content)
	{
		int length = oblist.size();
		for (int i = 0; i < length; i++)
		{
			oblist[i]->update(userid, itemid, content);
		}
	}

	bool getAcs() {
		return true;
	}
};

