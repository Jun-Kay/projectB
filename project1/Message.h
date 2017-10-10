#pragma once
#include <string>
using namespace std;
class Message
{
public:
	Message();
	~Message();

	int getUserId();
	int getToId();
	int getItemId();
	string getContent();

	void setUserId(int _uId);
	void setToId(int _toId);
	void setItemId(int _item);
	void setContent(string _ct);


private:
	int userId;
	int toId;
	int itemId;
	string content;
};

