#pragma once
#include <string>
#include "Produs.h"
#include <vector>
class Lot:public Produs
{
protected:
	int zi;
	int luna;
	int an;
	float cantitate;
	float pret;
	int valabilitate;
	float discount;

	float cantitate_ramasa;
	
public:

	Lot();
	Lot(std::string cs, std::string cs1, int zi, int luna, int an, float cantitate, float pret, int valabilitate,
		float discount,bool perisabilitate)
		: Produs(cs, cs1,perisabilitate),
		  zi(zi),
		  luna(luna),
		  an(an),
		  cantitate(cantitate),
		  pret(pret),
		  valabilitate(valabilitate),
		  discount(discount)
	{
		this->cantitate_ramasa = this->cantitate;
	}

	int get_zi() const;
	int get_luna() const;
	int get_an() const;
	float get_cantitate() const;
	float get_pret() const;
	int get_valabilitate() const;
	float get_discount() const;
	float get_cantitate_ramasa() const;
	void citire_lot(Produs* p);
	void set_cantitate_ramasa(float x)
	{
		this->cantitate_ramasa = x;
	}
};

