#include "Produs.h"

Produs::Produs()
{
	this->nume = "no";
	this->perisabilitate = true;
	this->unitate = "bucata";
}

Produs::Produs(std::string a, std::string b,bool c)
{
	this->nume = a;
	this->unitate = b;
	this->perisabilitate = c;
}

void Produs::afis_info()
{
	
		std::cout << std::endl << this->nume << " nume";
		std::cout << std::endl << this->unitate << " unitate";
	
}

std::string Produs::get_nume() const
{
	return nume;
}

std::string Produs::get_unitate() const
{
	return unitate;
}

bool Produs::is_perisabilitate() const
{
	return perisabilitate;
}

void Produs::set_nume(std::string nume)
{
	this->nume = nume;
}

void Produs::set_unitate(std::string unitate)
{
	this->unitate = unitate;
}

void Produs::set_perisabilitate(bool perisabilitate)
{
	this->perisabilitate = perisabilitate;
}


