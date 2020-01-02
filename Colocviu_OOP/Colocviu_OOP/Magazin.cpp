#include "Magazin.h"
#include <vector>
using namespace std;
#include <stdlib.h>
/*
void Magazin::AddLot(Lot* p2)
{
	if(p.empty())
	{
		p.resize(1);
	}
	else
	{
		p.resize(this->nr_loturi_curente + 1);
	}


	std::cout << "Pe ce data s-a primit?DD/MM/YYYY" << std::endl;
	std::cin >> this->zi >> this->luna >> this->an;
	cout << "Ce cantitate s-a primit?" << endl;
	cin >> this->cantitate;
	cout << "Ce termen de valabilitate ?" << endl;
	cin >> this->valabilitate;
	cout << "La ce pret se vand?" << endl;
	cin >> this->pret;



	// *this;
	
}




Produs Magazin::AddProdus()
{
	string a, b;
	cout <<endl<< "Nume: ";
	cin >> a;
	cout << endl << "Unitate ";
	cin >> b;
	 Produs(this->nume, this->unitate);
	this->nr_produse_inregistrate++;

	this->produse.push_back(new Produs (a,b));
	return *this;
}


void Magazin::afis_produse()
{
	for(auto i=produse.begin();i!=produse.end();++i)
	{
		this->afis_info();
		
	}
}
*/


Produs* Magazin::AddProdus()
{
	string nume_produs;
	cout << endl << "Nume: ";
	cin >> nume_produs;
	cout << endl << "Denumire unitate " << endl;
	cout << tip_unitate::bucata << " -bucata"  << endl;
	cout << tip_unitate::greutate << " -greutate" << endl;
	cout << tip_unitate::volum << " -volum" << endl;
	string unitate;
	cout << "Introdu optiunea ";
	cin >> unitate;



	cout << "Produsul este perisabil?0-nu ,1 -da" << endl;
	int per;
	cin >> per;
	Produs* produs = new Produs(nume_produs,unitate,per==0? false:true);
	vector<Lot*> a;
	this->produse.insert(make_pair(produs, a));
	return produs;
	

}
 

void Magazin::afis_produse()
{
	for(pair<Produs*, vector<Lot*>> x:this->produse)
	{
		x.first->afis_info();
	}
}


void Magazin::afis_produse_comercializate()
{
	for (pair<Produs*, vector<Lot*>> x : this->produse)
	{
		if(x.second.empty()==true)
		{
			continue;
		}
		cout << "Introdu data de azi sub forma de DD-MM-YYYY" << endl;
		int zi, luna, an;
		cin >> zi >> luna >> an;

		for (Lot* y : x.second)
		{

			if (y->get_cantitate_ramasa() == 0)
			{
				continue;
			}

			if (x.first->is_perisabilitate() == false)
			{
				y->afis_info();
			}
			else {

				if (y->get_an() != an)
				{
					continue;
				}

				if (y->get_luna() <= luna)
				{
					if (y->get_zi() + y->get_valabilitate() > zi)
					{
						y->afis_info();

					}
				}

			}
		}
		
	}
}

Lot* Magazin::add_lot()
{
	cout << "Introdu numele produsului pentru care vrei sa inregistrezi un nou lot." << endl;
	string nume_nou; cin >> nume_nou;
	bool flag = 0;
	Produs* prod=new Produs();
	for (pair<Produs*, vector<Lot*>> x : this->produse)
	{
		if(x.first->get_nume()==nume_nou)
		{
			flag = 1;
			prod = x.first;
		}
	
	}

	if(flag==0)
	{
		cout << "Nu exista produsul momentan.Adaugati-l" << endl;
		prod=AddProdus();
	}

	Lot* lot_nou = new Lot();
	lot_nou->citire_lot(prod);
	auto it = this->produse.find(prod);
	it->second.push_back(lot_nou);
	return lot_nou;
	return NULL;
	
}


bool Magazin::isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
	int entryDate = (year * 10000) + (month * 100) + day;
	int startDate = (startYear * 10000) + (startMonth * 100) + startDay;
	int endDate = (endYear * 10000) + (endMonth * 100) + endDay;

	if (entryDate >= startDate && entryDate <= endDate) {
		return true;
	}
	else {
		return false;
	}
}



void Magazin::afis_between()
{
	cout << "Introdu cele 2 date." << endl;
	cout << "data 1 " << endl;
	cout << "zi ";
	int zi_1, luna_1, an_1;
	cin >> zi_1;
	cout << endl<<"luna ";
	cin >> luna_1;
	cout << endl << "an ";
	cin >> an_1;

	cout << endl<<"data 2 " << endl;
	cout << "zi ";
	int zi_2, luna_2, an_2;
	cin >> zi_2;
	cout << endl << "luna ";
	cin >> luna_2;
	cout << endl << "an ";
	cin >> an_2;



	for (pair<Produs*, vector<Lot*>> x : this->produse)
	{
		for(Lot* l : x.second)
		{
			if(this->isDateInRange(l->get_zi(),
				l->get_luna(),
				l->get_an(),
				zi_1,
				luna_1,
				an_1,
				zi_2,
				luna_2,
				an_2)==true)
			{
				l->afis_info();
			}
		}
	}
	
}

void Magazin::vanzare()
{
	cout << "Ce produs doriti sa achizitionati? " << endl;
	string nume_nou; cin >> nume_nou;
	bool flag = 0;
	Produs* prod = new Produs();
	for (pair<Produs*, vector<Lot*>> x : this->produse)
	{
		if (x.first->get_nume() == nume_nou)
		{
			flag = 1;
			prod = x.first;
		}

	}

	if (flag == 0)
	{
		cout << "Nu exista produsul momentan" << endl;
		return;
	}

	cout << "Ce cantitate doriti? " << endl;
	float cant;
	cin >> cant;

	auto it = this->produse.find(prod);
	for(auto y:it->second)
	{
		if(y->get_cantitate_ramasa()>cant)
		{
			cout << "S-a facut vanzarea";
			cout << endl;
			y->set_cantitate_ramasa(y->get_cantitate_ramasa() - cant);
			return;
		}
	}


	for (auto y : it->second)
	{
		cout << y->get_cantitate_ramasa() << '\t' << y->get_luna() <<'\t'<< y->get_an() << '\t' << y->get_zi() << endl;
	}
}
