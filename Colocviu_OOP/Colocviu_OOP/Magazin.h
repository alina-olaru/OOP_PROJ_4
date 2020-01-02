#pragma once
#include "Lot.h"
#include <iostream> 
#include <vector>
#include <unordered_map>

#include <memory>
#include <string>
using namespace std;

class Magazin
{
private:

	unordered_map<Produs*, vector<Lot*>> produse;
public:
	
	
	Produs* AddProdus();
	void afis_produse();
	void afis_produse_comercializate();
	Lot* add_lot();
	void afis_between();
	bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);
	void vanzare();
	
};

