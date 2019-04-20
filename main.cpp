#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "d_list.h"

using namespace std;

void print_menu() {
	cout << "   1  SHOW LIST" << endl;
	cout << "   2  SHOW LIST BACKWARD" << endl;
	cout << "   3  ADD ELEMENT" << endl;
	cout << "   4  DELETE ELEMENT" << endl;
	cout << "   5  MOST EXPENSIVE LEGO" << endl;
	cout << "   6  IDK" << endl;
}

int main(int argc, char *argv[])
{
	d_list *list = new d_list;

	string path = "C:/Users/catav/Desktop/DataStructures/lab_1_1/catalog.bin";
	string b_name;
	string b_var;
	int b_price;
	int b_remain;
	int b_lim_a;
	int b_lim_b;
	if (argc > 1)
		path = argv[1];
	ifstream catalog;
	catalog.open(path);
	while (!catalog.is_open()) {
		cout << "File could not been opened" << endl;
		cout << "Enter new path to file" << endl;
		cin >> path;
		catalog.open(path);
		system("cls");
		if (path == "trp")
			return 0;
	}

	while (!catalog.eof()) {
		catalog >> b_name;
		if (b_name == "tableGame" || b_name == "chess" || b_name == "videoGame" || b_name == "lego" || b_name == "softToy")
			catalog >> b_var;
		catalog >> b_price;
		catalog >> b_remain;
		catalog >> b_lim_a;
		catalog >> b_lim_b;
		list->insert(b_name, b_var, b_price, b_remain, b_lim_a, b_lim_b);
	}
	list->del_end();

	bool exit = false;

	while (!exit) {
		print_menu();
		switch (_getch())
		{
			case 49: {                  // Print list
				system("cls"); 
				list->print_list(); 
				break; 
			}
			case 50: {					// Print list back
				system("cls"); 
				list->print_list_back(); 
				break; 
			}
			case 51: {					// Insert element
				bool u_exit = 0;
				system("cls");
				while (!u_exit) {
					cout << "Type name:" << endl;
					cin >> b_name;
					cin.clear();
					cout << endl;
					if (b_name.length() > (unsigned int)10) {
						cout << "Number of chars in name shouldn't be more then 10" << endl;
						Sleep(3000);
					}
					else
						u_exit = true;
					system("cls");
				}
				u_exit = false;
				if (b_name == "lego")
					while (!u_exit) {
						cout << "Type amount of details" << endl;
						cin >> b_var;
						cin.clear();
						if (atoi(b_var.c_str()) < 10)
							cout << "Amount of details should be more then 10" << endl;
						else
							u_exit = true;
						system("cls");
					}
				if (b_name == "videoGame")
					while (!u_exit) {
						cout << "Type genre" << endl;
						cin >> b_var;
						cin.clear();
						if (b_var.length() > 10)
							cout << "Amount of chars should be less then 10" << endl;
						else
							u_exit = true;
						system("cls");
					}
				if (b_name == "chess")
					while (!u_exit) {
						cout << "Type size of figures" << endl;
						cin >> b_var;
						cin.clear();
						u_exit = true;
						system("cls");
					}
				if (b_name == "tableGame")
					while (!u_exit) {
						cout << "Type amount of players" << endl;
						cin >> b_var;
						cin.clear();
						if (atoi(b_var.c_str()) < 0 || atoi(b_var.c_str()) > 20)
							cout << "Amount of players should be more then 0 and less then 20" << endl;
						else
							u_exit = true;
						system("cls");
					}
				if (b_name == "softToy")
					while (!u_exit) {
						cout << "Type type of animal" << endl;
						cin >> b_var;
						cin.clear();
						if (b_var.length() > 10)
							cout << "Amount of chars should be more less then 10" << endl;
						else
							u_exit = true;
						system("cls");
					}
				u_exit = false;
				while (!u_exit) {
					cout << "Type price:" << endl;
					cin >> b_price;
					cin.clear();
					cout << endl;
					if (b_price > 10000) {
						cout << "Price shouldn't be more then 10000" << endl;
						Sleep(3000);
					}
					else
						u_exit = true;
					system("cls");
				}
				u_exit = false;
				while (!u_exit) {
					cout << "Type remains:" << endl;
					cin >> b_remain;
					cin.clear();
					cout << endl;
					if (b_remain > 1000) {
						cout << "Remains can't be more then 1000" << endl;
						Sleep(3000);
					}
					else
						u_exit = true;
					system("cls");
				}
				u_exit = false;
				while (!u_exit) {
					cout << "Type lim_a:" << endl;
					cin >> b_lim_a;
					cin.clear();
					cout << endl;
					if (b_lim_a > 100) {
						cout << "First limit should be less then 100" << endl;
						Sleep(3000);
					}
					else
						u_exit = true;
					system("cls");
				}
				u_exit = false;
				while (!u_exit) {
					cout << "Type lim_b:" << endl;
					cin >> b_lim_b;
					cout << endl;
					if (b_lim_b < b_lim_a || b_lim_b > 100) {
						cout << "Second limit should be less then 100 and more then first" << endl;
						Sleep(3000);
					}
					else
						u_exit = true;
					system("cls");
				}
				list->insert(b_name, b_var, b_price, b_remain, b_lim_a, b_lim_b);
				break; 
			}
			case 52: {					// Delete element
				bool u_exit = false;
				int b_index = 0;
				system("cls"); 
				while (!u_exit) {
					cout << "Type index of element to delete" << endl;
					cin >> b_index;
					if (!list->del_element(b_index)) {
						cout << "There is no element with this index" << endl;
						cin.clear();
						Sleep(3000);
					}
					else
						u_exit = true;
					system("cls");
				}
				break; 
			}
			case 53: {
				system("cls");
				list->find_lego();
				break;
			}
			case 54: {
				system("cls");
				int age;
				int price_lim;
				cout << "\n   Type age     ";
				cin >> age;
				cout << endl;
				cout << "\n\n   Type price limit     ";
				cin >> price_lim;
				system("cls");
				list->for_idk(age, price_lim);
				break;
			}
			case 27: {					// Quit
				exit = 1;
				break;
			}
		}
		system("cls");
	}
	catalog.open(path, std::ios::in | std::ios::out);
	catalog.close();

	list->load_out(path);

	return 0;
}
