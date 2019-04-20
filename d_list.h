#pragma once
#include <iostream>
#include <fstream>
class d_list
{
private:
	struct element
	{
		std::string name;
		std::string var_name;
		std::string var_value;
		int price;
		int remain;
		int lim_a;
		int lim_b;
		element *prev, *next;
	};
	element *begin, *end;
	std::string type_1 = "lego";
	std::string type_2 = "videoGame";
	std::string type_3 = "chess";
	std::string type_4 = "tableGame";
	std::string type_5 = "softToy";
	int counter;
public:
	d_list();
	~d_list();

	void del_end();
	void insert(std::string name, std::string var_value, int price, int remain, int lim_a, int lim_b);
	bool del_element(int ind);
	void print_list();
	void print_list_back();
	void load_out(std::string path);
	void find_lego();
	void for_idk(int age, int price_lim);
};

