
// Provides definitions for the declarations made in Menu.h
#include "text.h"
#include "menu.h"
#include <iostream>
#include <cstring>
#include<string>


using namespace std;

//default constructor
Menu::Menu() :str{"?->"}, top_text{""}, top_prompt{""}, bottom_text{""}, bottom_prompt{""}, count{0}, max_list_size{1}, option_list{ new Text[1] }
{}

Menu::Menu(const Menu & m)				//copy constructor
{
	top_text = m.top_text;              //copies all the contents of menu m into new menu one by one
	top_prompt = m.top_prompt;
	bottom_text = m.bottom_text;
	bottom_prompt = m.bottom_prompt;
	option_list = new Text[m.count + 1];   
	for (int i = 0; i <count; i++)
		option_list[i] = m.option_list[i];
}

Menu::~Menu()							//destructor
{
	cout << "menu destructor";
	delete[] option_list;
	option_list = nullptr;
}

Menu& Menu::operator=(const Menu & m)   //=operator overloaded to assign one menu object to another
{
	top_text = m.top_text;				//all contents of menu m are copied into calling menu objects
	top_prompt = m.top_prompt;
	bottom_text = m.bottom_text;
	bottom_prompt = m.bottom_prompt;
	option_list = new Text[m.count + 1];
	count = m.count;
	for (int i = 0; i <m.count; i++)
		option_list[i] = m.option_list[i];
	return *this;
}

void Menu::insert(int option_index, const Text & option) //inset text option at given option_index
{
	if (isFull())                       //checks if option_list is full
	doublecapacity();					//if yes,then calls double capacity()
	Text* temp = new Text[++count];
	if (option_index > count+1)			//generates error if user inputs wrong option_index
	cout << "Invalid option_index";
	else
	{
	for (int i = 0; i<count; i++)       
		{
		if (i < option_index)
			temp[i] = option_list[i];
		if (i > option_index)
			temp[i] = option_list[i - 1];
		if(i==option_index)
			temp[option_index] = option;	//option is inserted at given option_index
		}
		delete[] option_list;
		option_list = temp;
		
	}
}

void Menu::push_back(char * c)      //insert the supplied option at the end of option_list
{
	if (isFull())					//before inserting checks whether option_list is full
		doublecapacity();
	insert(count, c);				//calls the insert function
}

void Menu::push_back(const Text & t)     //insert the text object at the end of option_list
{
	if (isFull())						 //before inserting checks whether option_list is full
		doublecapacity();
	insert(count, t);					//calls the insert function
}

void Menu::doublecapacity()				//double the capacity of option_list
{
		int newcap = 2 * max_list_size;  //capacity is doubled
		Text *temp = new Text[newcap];   
		for (int i = 0; i < max_list_size; i++)
			temp[i] = option_list[i]; 
		delete[] option_list;
		option_list = temp;
	 	max_list_size=newcap;
}

Text Menu::remove(int x)				//removes the option from option_list at index x
{
	if (count == 0)
	cout << "No options in menu list"<<endl;  //generates error at screen if user tries to delete when option_list is empty
	if(x>count)
	cout << "cannot delete at index " <<x<<"  because no element exists there"<< endl;
	Text tx= option_list[x];
		Text *temp = new Text[count-1];
	for (int i = 0; i < count; i++)
	{
		if (i < x)
			temp[i] = option_list[i];
		else if (i > x)
			temp[i-1]=option_list[i];
	}
	count--;								//after removing the element count is decremented
	option_list = temp;
	return tx;
}

int Menu::size() const						//returns the size of option_list
{
	return count;
}

int Menu::capacity() const					//returns the maximum capacity of option_list
{
	return max_list_size;
}

void Menu::pop_back()						//removes the option from back from option_list
{
	if (count == 0)
	cout << "Cannot delete No options in menu list" << endl;   //generates error at screen if user tries to delete when option_list is empty
	Text *temp = new Text[--count];
	for (int i = 0; i < count; i++)
		temp[i] = option_list[i];
	delete [] option_list;
	option_list = temp;
	
}

Text Menu::get(int x)              //returns the option at index x in option_list
{
	return option_list[x];
}

Text Menu::tostring() const			//converts whole menu into one text object 
{
	Text t = "";					//empty text object is created
	t.append(top_text);				//top text is appeneded to text object by calling append function of text class
	t.append("\n");
	t.append(top_prompt);			//top_prompt is appended to text object
	t.append("\n");
	for (int i = 0; i < count; i++)
	{
		t.append("(");
		    t.append(t.int_to_string(i+1));   //int_to_string function is called to dispaly the index of menu options
			t.append(")");
			t.append("  ");
			t.append(option_list[i]);		//options in option_list are appended iteratively
			t.append("\n");
		}
	t.append(bottom_text);					//bottom text is appeneded to text object
	t.append(str);
	t.append(bottom_prompt);				// bottom prompt is appeneded to text object
	return t;                               //single text object is returned
}

int Menu::read_option_number()				//reads the choice entered by user after displaying menu
{
	cout<<tostring();                       //menu is displayed
	
	int x;
	cin>>x;
	if (count == 0)							//error at screen is given if no options in option_list
		cout << "No options in menu list"<<endl;
	else if(x<0||x>count)						//checks if user entered valid option
	{
		cout << "Invalid choice." << x <<  "  It must be in the range [" << "1" << ","<<(count)<< "]";
		int y=read_option_number();
		return y;
		
	}
	return x;                              //returns the choice entered by user
}

void Menu::set_top_prompt(const Text & t)		//set the top prompt to text object t
{
	top_prompt = t;
}


void Menu::set_bottom_prompt(const Text & t)     //set the bottom prompt to text object t
{
	bottom_prompt = t;
}


void Menu::set_top_message(const Text & t)       //set the top message to text object t
{
	top_text = t;
}


void Menu::set_bottom_message(const Text & t)	//set the bottom message to text object t
{
	bottom_text = t;
}


void Menu::clear_top_prompt()					//clears the top prompt
{
	top_prompt = "";
}


void Menu::clear_bottom_prompt()				//clears the bottom prompt
{
	bottom_prompt = "";
}

void Menu::clear_top_message()					//clears the top message
{
	top_text= "";
}


void Menu::clear_bottom_message()				//clears the bottom message
{
	bottom_text = "";
}


bool Menu::isFull() const						//checks whether option_list is full upto maximum capacity
{
	if (count != 0)
	{
		if (count == max_list_size)
			return true;
		else
			return false;
	}
	else
		return false;							//returns false if there is no element in option list
}

bool Menu::isEmpty() const						//checks whether option_list is empty
{
	if (count == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const Menu & m)		//overload the << operator to display menu
{
	out << m.tostring();
	return out;
}

