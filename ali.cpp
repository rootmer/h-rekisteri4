#include <iostream>
#include <string>
#include <vector>

#include "maarittely.h"


using namespace std;

/** Valikko näkyville
*   nyt aliohjelmana
*/
int valikko(void) {
	int valinta = 99;
    cout << endl;
	cout << "=====================================================================" << endl;
    cout << "VALIKKO" << endl;
    cout << "0 - Lopeta" << endl;
    cout << "1 - Lisaa henkilo" << endl;
    cout << "2 - Listaa tietty henkilo" << endl;
    cout << "3 - Listaa kaikki henkilot" << endl;
	cout << "4 - Poista tietyn henkilon tiedot" << endl;
	cout << "=====================================================================" << endl;
	cin >> valinta;
    return valinta;
}


/** Henkilön lisäämiseen tarkoitettu
*   aliohjelma. Tarkistaa myös onko tilaa tiedoille.   
*/
void LisaaHenkilo(vector<tietue> TIEDOT) {
	cout << " boolean VielaMahtuu arvo on: " << VielaMahtuu << endl;
	if (VielaMahtuu) {
		string EtuNimi;
		float KouluMatka;
		int HattuKoko;
		cout << "Henkilön etunimi" << endl;
		cin >> EtuNimi;
		cout << "Henkilön koulumatka" << endl;
		cin >> KouluMatka;
		cout << "Henkilön hatun koko" << endl;
		cin >> HattuKoko;

		TIEDOT.push_back( {EtuNimi,KouluMatka,HattuKoko} );

		/** Testausta varten!!!!!!!!!!!!!!! */
		TIEDOT.insert(TIEDOT.begin(), { "Toni", 4.2, 44 });
		TIEDOT.push_back( { "Toni", 4.5, 55 } );

		if ( int(TIEDOT.size()) == TAULUN_MAX_KOKO) { VielaMahtuu = false; }
	}

	else if (!VielaMahtuu) { cout << endl << "Taulukko täynnä!" << endl; }
}


/** Aliohjelma joka hakee henkilön tiedot
*   syötetyn nimen perusteella
*/
void TulostaHenkilo(vector<tietue> TIEDOT) {
	string nimi;
    cout << "Syötä hakemasi henkilön etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < int(TIEDOT.size()); a++) {
        if (TIEDOT.at(a).EtuNimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT.at(a).EtuNimi << " " << TIEDOT.at(a).KouluMatka <<
            " " << TIEDOT.at(a).HattuKoko << endl;
            break;
        }

        if (a == (TAULUN_MAX_KOKO - 1) && TIEDOT.at(a).EtuNimi != nimi) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkilöt
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(vector<tietue> TIEDOT) {
	for (int a = 0; a < int(TIEDOT.size()); a++) {
        cout << "Henkilö " << a << ": " << TIEDOT.at(a).EtuNimi << " "
        << TIEDOT.at(a).KouluMatka << " " << TIEDOT.at(a).HattuKoko << endl;
    }
}


/** Poistaa henkilön tiedot
*	etunimen perusteella
*/
void PoistaHenkilo(vector<tietue> TIEDOT) {
	string nimi;
	string vastaus;
	int poistokohta;
	cout << "Syötä henkilön etunimi jonka tiedot haluat poistaa" << endl;
    cin >> nimi;

    for (int a = 0; a < int(TIEDOT.size()); a++) {
        if (TIEDOT.at(a).EtuNimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT.at(a).EtuNimi << " " << TIEDOT.at(a).KouluMatka <<
            " " << TIEDOT.at(a).HattuKoko << endl;
			cout << "Haluatko poistaa henkilön tiedot? k/e" << endl;
			cin >> vastaus;
			poistokohta = a;
			
			if (vastaus == "k") {
				for (int b = a; b < int(TIEDOT.size()); b++) {
					TIEDOT.erase(TIEDOT.begin() + (poistokohta-1));
				}
			 }
			
		else if (vastaus == "e") break;
        
		break;
        }

        if ( (a == int(TIEDOT.size()) ) && (TIEDOT.at(a).EtuNimi != nimi)) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}