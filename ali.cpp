#include <iostream>
#include <string>
#include <vector>

#include "maarittely.h"


using namespace std;

/** Valikko n�kyville
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


/** Henkil�n lis��miseen tarkoitettu
*   aliohjelma. Tarkistaa my�s onko tilaa tiedoille.   
*/
void LisaaHenkilo(vector<tietue> TIEDOT) {
	cout << " boolean VielaMahtuu arvo on: " << VielaMahtuu << endl;
	if (VielaMahtuu) {
		string EtuNimi;
		float KouluMatka;
		int HattuKoko;
		cout << "Henkil�n etunimi" << endl;
		cin >> EtuNimi;
		cout << "Henkil�n koulumatka" << endl;
		cin >> KouluMatka;
		cout << "Henkil�n hatun koko" << endl;
		cin >> HattuKoko;

		TIEDOT.push_back( {EtuNimi,KouluMatka,HattuKoko} );

		/** Testausta varten!!!!!!!!!!!!!!! */
		TIEDOT.insert(TIEDOT.begin(), { "Toni", 4.2, 44 });
		TIEDOT.push_back( { "Toni", 4.5, 55 } );

		if ( int(TIEDOT.size()) == TAULUN_MAX_KOKO) { VielaMahtuu = false; }
	}

	else if (!VielaMahtuu) { cout << endl << "Taulukko t�ynn�!" << endl; }
}


/** Aliohjelma joka hakee henkil�n tiedot
*   sy�tetyn nimen perusteella
*/
void TulostaHenkilo(vector<tietue> TIEDOT) {
	string nimi;
    cout << "Sy�t� hakemasi henkil�n etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < int(TIEDOT.size()); a++) {
        if (TIEDOT.at(a).EtuNimi == nimi) {
            cout << endl << "L�ytyi henkil�: " << TIEDOT.at(a).EtuNimi << " " << TIEDOT.at(a).KouluMatka <<
            " " << TIEDOT.at(a).HattuKoko << endl;
            break;
        }

        if (a == (TAULUN_MAX_KOKO - 1) && TIEDOT.at(a).EtuNimi != nimi) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkil�t
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(vector<tietue> TIEDOT) {
	for (int a = 0; a < int(TIEDOT.size()); a++) {
        cout << "Henkil� " << a << ": " << TIEDOT.at(a).EtuNimi << " "
        << TIEDOT.at(a).KouluMatka << " " << TIEDOT.at(a).HattuKoko << endl;
    }
}


/** Poistaa henkil�n tiedot
*	etunimen perusteella
*/
void PoistaHenkilo(vector<tietue> TIEDOT) {
	string nimi;
	string vastaus;
	int poistokohta;
	cout << "Sy�t� henkil�n etunimi jonka tiedot haluat poistaa" << endl;
    cin >> nimi;

    for (int a = 0; a < int(TIEDOT.size()); a++) {
        if (TIEDOT.at(a).EtuNimi == nimi) {
            cout << endl << "L�ytyi henkil�: " << TIEDOT.at(a).EtuNimi << " " << TIEDOT.at(a).KouluMatka <<
            " " << TIEDOT.at(a).HattuKoko << endl;
			cout << "Haluatko poistaa henkil�n tiedot? k/e" << endl;
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
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}