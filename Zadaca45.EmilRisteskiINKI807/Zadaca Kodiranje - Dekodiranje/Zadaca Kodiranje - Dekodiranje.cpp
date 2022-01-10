//Emil Risteski INKI807
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Kodiranje(string tekst, int kod) {   //funkcija koja prima tekst (niza), i kod (broj), i vrakja kodiran tekst (niza)
	for (int i = 0; i < tekst.size(); i++) {
		tekst[i] = char((int(tekst[i] + kod)));
	}
	return tekst;
}

string Dekodiranje(string tekst, int kod) {   //funkcija koja prima tekst (niza), i kod (broj), i vrakja dekodiran tekst (niza)
	for (int i = 0; i < tekst.size(); i++) {
		tekst[i] = char((int(tekst[i] - kod)));
	}
	return tekst;
}

bool ValidirajTekst(string tekst) {           //funkcija koja validira dali vnesenata niza sodrzi samo bukvi, brojki i pzazni mesta
	for (int i = 0; i < tekst.size(); i++) {  //ako sozdrzi i drugi simboli vrakja false
		//ako ne e broj bukva ili prazno mesto togash e simbol
		if (!isdigit(tekst.at(i)) && !isalpha(tekst.at(i)) && tekst.at(i) != ' ') {
			return false;
		}
	}

	return true;
}

int brojNaCifri(long long broj) { // funkcija koja prima broj (od tipot long long) kako argument, i presmetuva (vrakja) broj na cifri od brojot
	int brojac = 0;
	while (broj != 0)
	{
		broj = broj / 10;
		++brojac;
	}
	return brojac;
}

int main() {

	int opcija;
	cout << "Izberete opcija: " << endl;  //se bara od korisnikot da izbere opcija, i istata se vnesuva vo int opcija
	cout << "1. Kodiranje" << endl;
	cout << "2. Dekodiranje" << endl;
	cin >> opcija;

	long long broj = 0;
	int kod = 0;

	do {												  //ciklusot proveruva (vrti) se dodeka korisnikot ne vnesi validna sifra t.e
		cout << "Vnesete shifra za kodiranje: " << endl;  //broj koj ne e pozitiven i nema povekje od 10 cifri
		cin >> broj;
		kod = brojNaCifri(broj);					      // se povikuva funkcijata brojNaCifri(), i toa sto kje go vrati se zapisuva vo kod
		if (broj <= 0 || kod > 10) {
			cout << "Vnesete pozitiven broj, so najmnogu 10 cifri!" << endl;
		}

	} while (broj <= 0 || kod > 10);

	string tekst;
	cin.ignore();
	do {												// ciklusot proveruva (vrti) se dodeka korisnikot ne vnesi validna niza t.e
		cout << "Vnesete niza: " << endl;				// koja ne e pogolema od 400 karakteri i ne sodrzi simboli
		getline(cin, tekst);
		if (tekst.size() > 400) {
			cout << "Vnesete niza pomala od 400 karakteri!" << endl;
		}
		else if (opcija == 1 && ValidirajTekst(tekst) == false) {
			cout << "Vnesete niza samo so bukvi, brojki i prazni mesta!" << endl;
		}
		else {
			break;
		}
	} while (true);


	if (opcija == 1) {									// pri izbor na opcija 1 se povikuva funkcijata Kodiranje
		auto rezultat = Kodiranje(tekst, kod);
		cout << "Kodiraniot tekst e: " << rezultat << endl;
	}
	if (opcija == 2) {									// pri izbor na opcija 2 se povikuva funkcijata Dekodiranj
		auto rezultat = Dekodiranje(tekst, kod);
		cout << "Dekodiraniot tekst e: " << rezultat << endl;
	}

	return 0;
}