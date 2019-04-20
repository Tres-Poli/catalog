#include "d_list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

d_list::d_list()
{
	begin = end = NULL;
	counter = 0;
}


d_list::~d_list()
{
	element *temp;
	while (begin)
	{
		temp = begin;
		begin = begin->next;
		delete(temp);
	}
}

void d_list::insert(std::string name, std::string var_value, int price, int remain, int lim_a, int lim_b)
{
	element *temp = new element;
	element *ptr = begin;
	temp->name = name;
	temp->var_name = "";
	temp->var_value = "";
	if (name == type_1) {
		temp->var_name = "Amount of details - ";
		temp->var_value = var_value;
	}
	if (name == type_2) {
		temp->var_name = "Genre - ";
		temp->var_value = var_value;
	}
	if (name == type_3) {
		temp->var_name = "Size of figures - ";
		temp->var_value = var_value;
	}
	if (name == type_4) {
		temp->var_name = "Amount of players - ";
		temp->var_value = var_value;
	}
	if (name == type_5) {
		temp->var_name = "Animal - ";
		temp->var_value = var_value;
	}
	temp->price = price;
	temp->remain = remain;
	temp->lim_a = lim_a;
	temp->lim_b = lim_b;
	if (!begin) {
		temp->next = begin;
		temp->prev = NULL;
		end = temp;
		begin = temp;
		counter++;
	}
	else 
		if (begin->price >= temp->price) {
			temp->next = begin;
			temp->prev = NULL;
			begin->prev = temp;
			begin = temp;
			counter++;
		}
		else
			if (end->price <= temp->price) {
				temp->next = NULL;
				temp->prev = end;
				end->next = temp;
				end = temp;
				counter++;
			}
			else {
				while (ptr->price <= temp->price)
					ptr = ptr->next;
				temp->next = ptr;
				temp->prev = ptr->prev;
				ptr->prev->next = temp;
				ptr->prev = temp;
				counter++;
			}
		
}

void d_list::del_end()
{
	element *temp;
	if (end)
	{
		temp = end;
		end = end->prev;
		end->next = NULL;
		delete(temp);
		counter--;
	}
	if (end == NULL)
		begin = NULL;
}

bool d_list::del_element(int ind)
{
	if (ind > counter || ind < 1)
		return false;
	element *temp = begin;
	for (ind; ind > 1; ind--)
		temp = temp->next;
	if (temp == begin) {
		if (begin == end) {
			begin = end = NULL;
			delete(temp);
		}
		else {
			begin = begin->next;
			begin->prev = NULL;
			delete(temp);
			counter--;
		}
	}
	else
		if (temp == end) {
			end = end->prev;
			end->next = NULL;
			delete(temp);
			counter--;
		}
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete(temp);
			counter--;
		}
	return true;
}

void d_list::print_list() {
	element *temp = begin;				     //10					          25						  7					   12						11
	bool exit = false;
	int i = 1;
	int j;
	int dec = 0;
	while (!exit) {
		cout << "   | " << "#" << " | " << "  Name  " << " | " << "       Var field       " << " | " << " Price  " << " | " << "Remain" << " | " << "Age limits" << " | " << endl;
		cout << "   ===========================================================================" << endl;
		for (i = 1 + dec; i <= dec + 10 && begin != NULL; i++)
		{
			cout << "   |"; if (i < 10) { cout << " "; } cout << i; if (i < 100) { cout << " "; } cout << "|"
				<< begin->name; for (int i = 10 - begin->name.length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->var_name << begin->var_value; for (int i = 25 - begin->var_name.length() - begin->var_value.length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->price; for (int i = 10 - to_string(begin->price).length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->remain; for (int i = 8 - to_string(begin->remain).length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->lim_a << "-" << begin->lim_b; for (int i = 11 - to_string(begin->lim_a).length() - to_string(begin->lim_b).length(); i > 0; i--)cout << " ";
			cout << "|" << endl;
			cout << "   ---------------------------------------------------------------------------" << endl;
			begin = begin->next;
		}
		begin = temp;
		cout << "\n\n    Press BACKSPACE to return to the menu " << endl;
		cout << "    Press  <-  ->  to see the whole list (" << counter << " element)" << endl;
		switch (_getch()) {
			case 8: exit = true; break;
			case 77: { //  ->
				if (counter - dec - 10 > 0)
					dec += 10;
				break;
			}
			case 75: { //  <-
				if (dec >= 10)
					dec -= 10;
				break;
			}
		}
		system("cls");
		for (j = 0; j < dec; j++)
			begin = begin->next;
	}
	begin = temp;
}

void d_list::print_list_back() {
	element *temp = end;
	bool exit = false;
	int i = 1;
	int j;
	int dec = 0;
	while (!exit) {
		cout << "   | " << "#" << " | " << "  Name  " << " | " << "       Var field       " << " | " << " Price  " << " | " << "Remain" << " | " << "Age limits" << " | " << endl;
		cout << "   ===========================================================================" << endl;
		for (i = 1 + dec; i <= dec + 10 && end != NULL; i++)
		{
			cout << "   |"; if (this->counter - i + 1 < 10) { cout << " "; } cout << this->counter - i + 1; if (this->counter - i < 100) { cout << " "; } cout << "|"
				<< end->name; for (int i = 10 - end->name.length(); i > 0; i--)cout << " "; cout << "|"
				<< end->var_name << end->var_value; for (int i = 25 - end->var_name.length() - end->var_value.length(); i > 0; i--)cout << " "; cout << "|"
				<< end->price; for (int i = 10 - to_string(end->price).length(); i > 0; i--)cout << " "; cout << "|"
				<< end->remain; for (int i = 8 - to_string(end->remain).length(); i > 0; i--)cout << " "; cout << "|"
				<< end->lim_a << "-" << end->lim_b; for (int i = 11 - to_string(end->lim_a).length() - to_string(end->lim_b).length(); i > 0; i--)cout << " ";
			cout << "|" << endl;
			cout << "   ---------------------------------------------------------------------------" << endl;
			end = end->prev;
		}
		end = temp;
		cout << "\n\n    Press BACKSPACE to return to the menu " << endl;
		cout << "    Press  <-  ->  to see the whole list (" << counter << " element)" << endl;
		switch (_getch()) {
			case 8: exit = true; break;
			case 77: { //  ->
				if (counter - dec - 10 > 0)
					dec += 10;
				break;
			}
			case 75: { //  <-
				if (dec >= 10)
					dec -= 10;
				break;
			}
		}
		system("cls");
		for (j = 0; j < dec; j++)
			end = end->prev;
	}
	end = temp;
}

void d_list::load_out(std::string path) {
	ofstream file;
	file.open(path);
	element *temp = begin;
	while (begin) {
		file << begin-> name << " ";
		if (begin->name == "tableGame" || begin->name == "chess" || begin->name == "videoGame" || begin->name == "lego" || begin->name == "softToy")
			file << begin-> var_value<< " ";
		file << begin->price << " ";
		file << begin->remain << " ";
		file << begin->lim_a << " ";
		file << begin->lim_b << "\n";
		begin = begin->next;
	}
	begin = temp;
	file.close();
}

void d_list::find_lego() {
	element *temp = begin;
	element *lego = begin;
	while (begin) {
		if (begin->name == type_1)
			if (begin->price > lego->price)
				lego = begin;
		begin = begin->next;
	}
	begin = temp;
	cout << "\n    THE MOST EXPENSIVE LEGO:  | " << lego->var_name << lego->var_value << " |  price: " << lego->price << " rub | remains: " << lego->remain << " | age limits: " << lego->lim_a << "-" << lego->lim_b << " |" << endl;
	cout << "\n    Press any key to continue" << endl;
	_getch();
}

void d_list::for_idk(int age, int price_lim) {
	element *temp = begin;
	while (begin) {
		if (begin->price <= price_lim && begin->lim_a <= age && begin->lim_b >= age) {
			cout << "|" << begin->name; for (int i = 10 - begin->name.length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->var_name << begin->var_value; for (int i = 25 - begin->var_name.length() - begin->var_value.length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->price; for (int i = 10 - to_string(begin->price).length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->remain; for (int i = 8 - to_string(begin->remain).length(); i > 0; i--)cout << " "; cout << "|"
				<< begin->lim_a << "-" << begin->lim_b; for (int i = 11 - to_string(begin->lim_a).length() - to_string(begin->lim_b).length(); i > 0; i--)cout << " ";
			cout << "|" << endl;
			cout << "-------------------------------------------------------------------" << endl;
		}
		begin = begin->next;
	}
	begin = temp;
	cout << "\n    Press any key to continue" << endl;
	_getch();
}
