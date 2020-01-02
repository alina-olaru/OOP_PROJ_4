#pragma once
#include <string>
#include <ostream>
#include <iostream>



enum tip_unitate
{
	bucata,
	greutate,
	volum
};



class Produs
{
private:
	std::string nume;
	std::string unitate;
	bool perisabilitate;
public:
	Produs();
	Produs(std::string, std::string,bool);
	void afis_info();


	std::string get_nume() const;
	std::string get_unitate() const;
	bool is_perisabilitate() const;

	void set_nume(std::string nume);
	void set_unitate(std::string unitate);
	void set_perisabilitate(bool perisabilitate);
};

