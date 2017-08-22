//Provides  declarations of Menu class
#ifndef MENU_H
#define MEHU_H
#include "text.h"
#include "iostream""
using namespace std;

class Menu
{
private:Text top_prompt;			// top prompt
		Text top_text;				//top text
		Text bottom_prompt;			//bottom prompt 
		Text bottom_text;			//bottom text
		Text str;					//represents the literal ?->
		int count;					//total number of options in option list
		int max_list_size;			//maximum number of options supported in option_list
		Text *option_list;			//points to array storing the menu options
		void doublecapacity();		//doubles the capacity of option_list

public:Menu();						//default constructor
	   Menu(const Menu &);			//copy constructor
	   virtual ~Menu();				//destructor
	   Menu& operator=(const Menu&);//assignment operator overloaded
	   void insert(int option_index, const Text & option);//insers the option at given option_index in menu
	   void push_back(char *);		//insert the supplied option at the end of option_list
	   void push_back(const Text&); //insert the text object at the end of option_list
	   Text remove(int);			//removes the option from option_list at index x
	   int size() const;			//returns the size of option_list
	   int capacity() const;		//returns the maximum capacity of option_list
	   void pop_back();				//removes the option from back from option_list
	   Text get(int);				//returns the option at index x in option_list
	   Text tostring()const ;		//converts whole menu into one text object 
	   int read_option_number();	//reads the choice entered by user after displaying menu
	   void set_top_prompt(const Text &);	//set the top prompt to text object t
	   void set_bottom_prompt(const Text &);//set the bottom prompt to text object t
	   void set_top_message(const Text &);	//set the top message to text object t
	   void set_bottom_message(const Text &);//set the bottom message to text object t
	   void clear_top_prompt();		//clears the top prompt
	   void clear_bottom_prompt();	//clears the bottom prompt
	   void clear_top_message();	//clears the top message
	   void clear_bottom_message();	//clears the bottom message
	   bool isEmpty()const;			//checks whether option_list is empty	
	   bool isFull() const;			//checks whether option_list is full upto maximum capacity
	   friend ostream & operator<<(ostream &, const Menu&);
};
#endif;

