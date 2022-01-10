//Emil Risteski INKI807
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Kodiranje(string tekst, int kod) {
	for (int i = 0; i < tekst.size(); i++) {
		tekst[i] = char((int(tekst[i] + kod)));
	}
	return tekst;
}

string Dekodiranje(string tekst, int kod) {
	for (int i = 0; i < tekst.size(); i++) {
		tekst[i] = char((int(tekst[i] - kod)));
	}
	return tekst;
}

bool ValidirajTekst(string tekst) {
	for (int i = 0; i < tekst.size(); i++) {
		//ako ne e broj bukva ili prazno mesto togash e simbol
		if (!std::isdigit(tekst.at(i)) && !std::isalpha(tekst.at(i)) && tekst.at(i) != ' ') {
			return false;
		}
	}

	return true;
}

int brojNaCifri(long long broj) { // funkcija koja presmetuva (vrakja) broj na cifri
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
	cout << "Izberete opcija: " << endl;
	cout << "1. Kodiranje" << endl;
	cout << "2. Dekodiranje" << endl;
	cin >> opcija;

	long long broj = 0;
	int kod = 0;

	do {
		cout << "Vnesete shifra za kodiranje: " << endl;
		cin >> broj;
		kod = brojNaCifri(broj);
		if (broj <= 0 || kod > 10) {
			cout << "Vnesete pozitiven broj, so najmnogu 10 cifri!" << endl;
		}

	} while (broj <= 0 || kod > 10);

	string tekst;
	cin.ignore();
	do {
		cout << "Vnesete niza: " << endl;
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


	if (opcija == 1) {
		auto rezultat = Kodiranje(tekst, kod);
		cout << "Kodiraniot tekst e: " << rezultat << endl;
	}
	if (opcija == 2) {
		auto rezultat = Dekodiranje(tekst, kod);
		cout << "Dekodiraniot tekst e: " << rezultat << endl;
	}

	return 0;
}