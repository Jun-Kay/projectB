#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

class App
{
public:
	App();
	~App();

	void run();

private:
	void readFiles();

	void login();
	void logout();

	void writePost();

	void printMyPosting();
	void printTimeline();

	void sendMessage();
	void printMessages();

	void friendRecommendation();
	void requestFriend();
	void acceptFriend();
	
	User* findUserById(int _Id);

	void load_Relation();
	void load_user();
	void load_post();
	void load_message();

	vector<User*> userList;

	User* loginedUser;

	int PitemId = 0;
	int MitemId = 0;
};

