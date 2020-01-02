#include "Lot.h"
#include <iostream>
using namespace std;
/* int zi;
int luna;
int an;
float cantitate;
float pret;
int valabilitate;
float discount;

float cantitate_ramasa;/**/


Lot::Lot():Produs()
{


	this->an = 2020;
	this->zi = 20;
	this->luna = 1;
	this->cantitate = 1;
	this->pret = 1;
	this->discount = 0;
	this->cantitate_ramasa = 1;
}

int Lot::get_zi() const
{
	return zi;
}

int Lot::get_luna() const
{
	return luna;
}

int Lot::get_an() const
{
	return an;
}

float Lot::get_cantitate() const
{
	return cantitate;
}

float Lot::get_pret() const
{
	return pret;
}

int Lot::get_valabilitate() const
{
	return valabilitate;
}

float Lot::get_discount() const
{
	return discount;
}

float Lot::get_cantitate_ramasa() const
{
	return cantitate_ramasa;
}

void Lot::citire_lot(Produs* p)
{
	this->set_nume(p->get_nume());
	this->set_perisabilitate(p->is_perisabilitate());
	this->set_unitate(p->get_unitate());
	
	std::cout << "Introduceti data primirii lotului de forma DD.MM.YYYY";
	std::cout << std::endl << "zi: ";
	std::cin >> this->zi;
	std::cout << std::endl << "luna: ";
	std::cin >> this->luna;
	std::cout << std::endl << "an: ";
	std::cin >> this->an;

	cout << endl << "Introduceti cantitatea: ";
	cin >> this->cantitate;
	cout << endl << "Introduceti pret per unitate: ";
	cin >> this->pret;
	if(p->is_perisabilitate()==true)
	{
		cout << "Introduceti zilele de valabilitate: ";
		cin >> this->valabilitate;
	}

	cout << "Exista discount pentru acest lot? 1-da,0-nu";
	int ch;
	cout << endl;
	cin >> ch;
	if(ch==1)
	{
		cin >> this->discount;
	}
	this->cantitate_ramasa = this->cantitate;


	
}
