#include "User.h"


int User::getId()
{
	return id;
}

string User::getPw()
{
	return pw;
}

string User::getAttrs(string _st)
{
	return attrs[_st];
}

vector<User*> User::getFriendList()
{
	return friendList;
}

void User::setId(int _id)
{
	id = _id;
}

void User::setPw(string _pw)
{
	pw = _pw;
}

void User::setAttrs(string _na, string _attr)
{
	attrs.insert(make_pair(_na, _attr));
}


void User::addFriend(User * _fr)
{
	friendList.push_back(_fr);
}

bool User::_writePost()
{
	int pId;
	cout << "\tPost의 ID : ";
	cin >> pId;

	bool duqn = myPosts[pId]->getAcs();
	if (duqn)
	{	// 공개
		return 1;
	}
	else
	{	// 비공개
		return 0;
	}
}


void User::_requestFriend(User * toUser)
{
	toUser->receivedFriendRequest.push_back(this);
}

void User::_acceptFriend()
{
	int length = receivedFriendRequest.size();
	for (int i = 0; i < length; i++)
	{
		cout << receivedFriendRequest[i]->getId() << endl;
	}
	
	int Id;
	cout << "\t받을 요청의 ID : ";
	cin >> Id;

	for (int i = 0; i < length; i++)
	{
		if (receivedFriendRequest[i]->getId() == Id)
		{
			addFriend(receivedFriendRequest[i]);
			receivedFriendRequest.erase(receivedFriendRequest.begin()+i);
			break;
		}
	}
	
	
}

void User::update(int userId, int itemId, string content)
{
	Post* p = new Post();
	p->setUserId(userId);
	p->setItemId(itemId);
	p->setContent(content);

/*	bool a = p->getAcs();
	p->setAcs(a);
	*/
	timeline.push_back(p);
}

void User::_printMyPost()
{
	int length = myPosts.size();
	for (int i = 0; i < length; i++)
	{
		cout << myPosts[i]->getUserId() << "\t" << myPosts[i]->getItemId() << "\t" << myPosts[i]->getContent() << endl;
	}
}

void User::_printTimeLine()
{
	int length = timeline.size();
	for (int i = 0; i < length; i++)
	{
		cout << timeline[i]->getUserId() << "\t" << timeline[i]->getItemId() << "\t" << timeline[i]->getContent() << endl;
	}
}

void User::_printMessages()
{
	int length = sentMessage.size();

	cout << "=====보낸 메세지=====" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << sentMessage[i]->getUserId() << "\t" << sentMessage[i]->getToId() << "\t" << sentMessage[i]->getItemId() << "\t" << sentMessage[i]->getContent() << endl;
	}
	cout << "===============================================" << endl;

	length = recievedMessage.size();

	cout << "=====받은 메세지=====" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << recievedMessage[i]->getUserId() << "\t" << recievedMessage[i]->getToId() << "\t" << recievedMessage[i]->getItemId() << "\t" << recievedMessage[i]->getContent() << endl;
	}
	cout << "===============================================" << endl;

}

void User::addPost(Post * _post)
{
	myPosts.push_back(_post);
}

void User::addTimeLine(Post * _post)
{
	timeline.push_back(_post);
}

void User::addSentMessage(Message * _msg)
{
	sentMessage.push_back(_msg);
}

void User::addReceivedMessage(Message * _msg)
{
	recievedMessage.push_back(_msg);
}
