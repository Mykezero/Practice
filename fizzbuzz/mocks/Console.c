#include "Console.h"

char * _message;

void Write(char * message)
{
	_message = message;
}

char * GetLastMessage(void)
{
	return _message;
}