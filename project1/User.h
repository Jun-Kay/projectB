#pragma once
#include "Observer.h"
#include "Post.h"
#include "Message.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class User :
	public Observer
{
public:
	User() {
		id = 0;
		pw = "";
		
	}
	~User() {}

	int getId();
	string getPw();
	string getAttrs(string _st);

	vector<User*> getFriendList();

	void setId(int _id);
	void setPw(string _pw);
	void setAttrs(string _na, string _attr);

	void uinfo() {
		cout << "id : " << id << "\tpw : "<<  pw << endl;
	}

	void addFriend(User* _fr);

	bool _writePost();


	void _requestFriend(User* toUser);
	void _acceptFriend();


	void update(int userId, int itemId, string content);

	void _printMyPost();
	void _printTimeLine();
	void _printMessages();


	void addPost(Post* _post);
	void addTimeLine(Post* _post);
	void addSentMessage(Message* _msg);
	void addReceivedMessage(Message* _msg);
	
private:
	vector<Post*> myPosts;
	vector<Post*> timeline;

	vector<Message*> sentMessage;
	vector<Message*> recievedMessage;

	vector<User*> friendList;
	vector<User*> receivedFriendRequest;

	int id;
	string pw;
	map<string, string> attrs;

};

