#include "Message.h"

Message::Message()
{
}

Message::~Message()
{
}

int Message::getUserId()
{
	return userId;
}

int Message::getToId()
{
	return toId;
}

int Message::getItemId()
{
	return itemId;
}

string Message::getContent()
{
	return content;
}

void Message::setUserId(int _uId)
{
	userId = _uId;
}

void Message::setToId(int _toId)
{
	toId = _toId;
}

void Message::setItemId(int _item)
{
	itemId = _item;
}

void Message::setContent(string _ct)
{
	content = _ct;
}
