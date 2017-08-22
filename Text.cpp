
#include <iostream>
#include <cstring>
#include "text.h"
using namespace std;


Text::Text() :Text("")            //default constructor
{}

Text::~Text()					//destructor
{
	delete[] text;
	text = nullptr;				
}


Text::Text(const char *x)			//conversion constructor
{
	int len = strlen(x);
	text = new char[len + 1];		//creates next text of length one more than that of x's text
	strcpy(text, x);				//x is copied to this objects text
}

Text::Text(const Text &t)			//copy constructor
{
	int len = strlen(t.text);		
	text = new char[len + 1];		//creates next text of length one more than that of Text object t's text
	strcpy(text, t.text);			//t's text is copied to this objects text
}
void Text::set(char *x)				//sets this object to *t
{
	int len = strlen(x);
	text = new char[len + 1];
	strcpy(text, x);
}
void Text::set(const Text &t)		//sete this object to that of t	
{
	text = t.text;
}
void Text::append(const char *x)	//appends *t to this object's text
{
	int len = strlen(text);
	int len1 = strlen(x);
	char *temp = new char[len + len1 + 1];
	strcpy(temp, text);
	strcat(temp, x);
	text = temp;
}

void Text::append(const Text & t)	//appends t's text to this object's text
{
	int len = strlen(text);
	int len1 = strlen(t.text);
	char *temp = new char[len + len1 + 1];
	strcpy(temp, text);
	strcat(temp, t.text);
	text = temp;
	}


Text & Text::operator=(const Text & t)		//assigns one text object to another
{
	if (this == &t)
		return *this;
	delete[] text;
	int len = strlen(t.text);
	text = new char[len + 1];
	strcpy(text, t.text);
	return *this;
}

Text Text::int_to_string(int x)				//converts the integer to string
{
	int y = 0;
	do {
		int d = x % 10;
		x /= 10;
		y = y * 10 + d;
	} while (x != 0);

		x = y;
		char str[2]{};
	Text t;
	do {
		int d = x % 10;
		x /= 10;
		str[0] = '0' + d;
		t.append(str);
	} while (x != 0);

	return t;
}

ostream&  operator<<(ostream& out, const Text& t)	//<< operator overloaded to displlay object's text
{
	out << t.text;
	return out;
}


int Text::length()				//finds the length of text
{

	return strlen(this->text);
}

bool Text::isempty()			//checks whetherobject's text is  empty
{
	if (this->length() == 0)
		return true;
	else
		return false;
}

