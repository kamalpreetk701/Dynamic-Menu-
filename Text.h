//provides the declarations of Text class
#ifndef TEXT_H
#define TEXT_H
#include "iostream"

using namespace std;


class Text								//class Text
{
private: char * text;					//character pointer text points to where text object is stored

public:	Text();							//default constructor
		virtual ~Text();				//destructor
		Text(const char *);				//conversion constructor
		Text(const Text &);				//copy constructor
		void set(char * t);				//sets this object to *t
		void set(const Text &t);		//sete this object to that of t	
		void append(const char * t);	//appends *t to this object's text
		void append(const Text &t);		//appends t's text to this object's text
		Text& operator=(const Text &);	//assigns one text object to another
		Text int_to_string(int x);		//converts the integer to string
		int length();					//finds the length of text
		bool isempty();					//checks whetherobject's text is  empty
		friend ostream& operator<<(ostream &, const Text &); //<< operator overloaded to displlay object's text
};
#endif 