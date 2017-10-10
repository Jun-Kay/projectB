#include "App.h"

App::App()
{
	readFiles();
	loginedUser = nullptr;
}

App::~App()
{
}

void App::run()
{

	while (1)
	{

		cout << endl << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t   1 : Login" << endl;
		cout << "\t   2 : Logout" << endl;
		cout << "\t   3 : 글쓰기" << endl;
		cout << "\t   4 : 내 게시글 출력" << endl;
		cout << "\t   5 : 내 타임라인 출력" << endl;
		cout << "\t   6 : 메세지 보내기" << endl;
		cout << "\t   7 : 메세지 출력" << endl;
		cout << "\t   8 : 친구 요청" << endl;
		cout << "\t   9 : 친구 요청 받기" << endl;
		cout << "\t   0 : Quit" << endl;

		int command;
		cout << "\tcommand : ";
		cin >> command;

		switch (command)
		{
		case 1:
			login();
			break;
		case 2:
			logout();
			break;
		case 3:
			writePost();
			break;
		case 4:
			printMyPosting();
			break;
		case 5:
			printTimeline();
			break;
		case 6:
			sendMessage();
			break;
		case 7:
			printMessages();
			break;
		case 8:
			requestFriend();
			break;
		case 9:
			acceptFriend();
			break;
		case 0:
			cout << " 끝! " << endl;
			return;
		default:
			cout << "\t=====잘못된 입력값=====" << endl;
			break;
		}
	}

}

void App::readFiles()
{
	load_user();
	load_post();
	load_message();
	load_Relation();
}

void App::login()
{
	if (loginedUser)
	{
		cout << "=====이미 로그인 상태 입니다.=====" << endl;
		return;
	}
	else
	{
		int id;
		string pw;
		int length = userList.size();
		cout << "\tId: ";
		cin >> id;

		for (int i = 0; i < length; i++)
		{
			if (userList[i]->getId() == id)
			{
				cout << "\tPw: ";
				cin >> pw;

				if (userList[i]->getPw() == pw)
				{
					loginedUser = userList[i];
					cout << "======로그인 성공!=======" << endl;
					return;
				}
				else
				{
					cout << "=====잘못된 password======" << endl;
					return;
				}
			}
		}
		cout << "=======잘못된 id========" << endl;
		return;
	}
}

void App::logout()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
	}
	else
	{
		loginedUser = nullptr;
		cout << "=====로그아웃 하였습니다.=====" << endl;
	}
}

void App::writePost()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}

	Post* newPost = new Post();

	newPost->setUserId(loginedUser->getId());
	newPost->setItemId(PitemId);

	string a;

	cout << "\t내용 입력 : ";
	cin >> a;

	string b;

	cout << "\t공개/비공개(O/C) : ";
	cin >> b;

	Accessibility* acs;
	
	vector<Observer*> ob;
	

	if (b =="O")
	{
		acs = new AcsPublic();

		vector<User*> fr = loginedUser->getFriendList();
		for (int i = 0; i < userList.size(); i++)
		{
			ob[i] = fr[i];
		}

		acs->update(ob, loginedUser->getId(), PitemId, a);

	}
	else if (b == "C")
	{
		for (int i = 0; i < 1; i++)
		{
			ob[i] = loginedUser;
		}
		acs = new AcsPrivate();
		acs->update(ob, loginedUser->getId(), PitemId, a);
	}
	else 
	{
		cout << "=====잘못된 입력=====" << endl;
	}

	newPost->setContent(a);
	newPost->setAcs(acs);

	loginedUser->addPost(newPost);
	loginedUser->addTimeLine(newPost);

	PitemId++;
}

void App::printMyPosting()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}
	loginedUser->_printMyPost();
}

void App::printTimeline()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}
	loginedUser->_printTimeLine();
}

void App::sendMessage()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}

	int toId;
	string content;

	cout << "\t받을 사람의 ID : ";
	cin >> toId;
	
	cout << "\t내용 입력 : ";
	cin >> content;

	Message* msg = new Message;

	msg->setUserId(loginedUser->getId());
	msg->setItemId(MitemId);
	msg->setToId(toId);
	msg->setContent(content);

	MitemId++;

	loginedUser->addSentMessage(msg);
	findUserById(toId)->addReceivedMessage(msg);
}

void App::printMessages()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}
	loginedUser->_printMessages();
}

void App::friendRecommendation()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}
	cout << "\t=====친구 추천====" << endl;

}

void App::requestFriend()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}
	int toId;

	cout << "\t=====친구 요청 ID 입력 : ";
	cin >> toId;
	
	loginedUser->_requestFriend(findUserById(toId));
}

void App::acceptFriend()
{
	if (!loginedUser)
	{
		cout << "=====로그인상태가 아닙니다.=====" << endl;
		return;
	}
	loginedUser->_acceptFriend();
}

User * App::findUserById(int _Id)
{
	int length = userList.size();
	for (int i = 0; i < length; i++)
	{
		if (userList[i]->getId() == _Id)
		{
			return userList[i];
		}
		
	}
	cout << "=====그런 사람 없는딩=====" << endl;

	return nullptr;
}

void App::load_Relation()
{

	ifstream read("friend.txt");
	ifstream read2("requested.txt");

	while (!read.eof()) {
		int userId, friendsCnt, friendId;
		read >> userId >> friendsCnt;
		User*  curUser = findUserById(userId);
		for (int i = 0; i < friendsCnt; i++)
		{
			read2 >> friendId;
			User* _friend = findUserById(friendId);
			curUser->addFriend(_friend);
		}
	}
	while (!read.eof()) {
		int userId, friendsCnt, friendId;
		read >> userId >> friendsCnt;
		User*  curUser = findUserById(userId);
		for (int i = 0; i < friendsCnt; i++)
		{
			read2 >> friendId;
			User* _friend = findUserById(friendId);
			curUser->addFriend(_friend);
		}
	}

	read.close();
	read2.close();
}

void App::load_user()
{
	ifstream read("user.txt");	
	
	int userId;// , postCount, postID;
	
	string pw, username, attr1, attr2, attr3, attr4;
	
	while (!read.eof()) {

		read >> userId >> pw >> username >> attr1 >> attr2 >> attr3 >> attr4;

		User* curUser= new User;

		curUser->setId(userId);
		curUser->setPw(pw);
		curUser->setAttrs("이름", username);
		curUser->setAttrs("나이", attr1);
		curUser->setAttrs("성별", attr2);
		curUser->setAttrs("학교", attr3);
		curUser->setAttrs("주소", attr4);

		userList.push_back(curUser);
	}


	read.close();

}

void App::load_post()
{
	ifstream read("post.txt");
	int userId, itemId;

	string content;

	while (!read.eof())
	{
		read >> userId;
		Post* newPost = new Post();
		newPost->setUserId(userId);
		read >> itemId;
		newPost->setItemId(itemId);
		read >> content;
		newPost->setContent(content);

		User* postedUser = findUserById(userId);
		postedUser->addPost(newPost);
		postedUser->addTimeLine(newPost);
		//
	}

	read.close();
}

void App::load_message()
{
	ifstream read("message.txt");	
	
	int userId, toId;
	int itemId;

	string content;
	
	while (!read.eof()) {
		
		Message* newMessage = new Message();

		read >> userId;
		newMessage->setUserId(userId);
		read >> toId;
		newMessage->setToId(toId);
		read >> itemId;
		newMessage->setItemId(itemId);
		read >> content;
		newMessage->setContent(content);
		
		User* sendedUser = findUserById(userId);
		sendedUser->addSentMessage(newMessage);
		
		User* recievingUser = findUserById(toId);
		recievingUser->addReceivedMessage(newMessage);
	}
	
	read.close();
}
