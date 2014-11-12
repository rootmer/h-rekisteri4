/** Tarpeelliset kirjastot käyttöön */
#include <iostream>
#include <string>
#include <vector>

/** Otsaketiedoston sisällyttäminen */
#include "maarittely.h"

/** Helpottaa coutien ja cinien käyttöä */
using namespace std;

/** Valikko näkyville
*   nyt aliohjelmana
*/
int valikko(void) {
	int valinta = 99;
    cout << endl;
    cout << "VALIKKO" << endl;
    cout << "0 - Lopeta" << endl;
    cout << "1 - Lisaa henkilo" << endl;
    cout << "2 - Nayta henkilo" << endl;
    cout << "3 - Nayta kaikki henkilot" << endl;
	cout << "4 - Poista henkilon tiedot" << endl;
	cin >> valinta;
    return valinta;
}


/** Henkilön lisäämiseen tarkoitettu
*   aliohjelma. Tarkistaa myös onko tilaa tiedoille.
*   Parametrinä vectorin pointteri jotta voidaan
*   muuttaa aliohjelman ulkopuolista arvoa
*/
void LisaaHenkilo(vector<tietue> TIEDOT) {
	int kohta = 99;
	
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
		TIEDOT.push_back( { EtuNimi, KouluMatka,HattuKoko } );
		if (kohta == TAULUN_MAX_KOKO - 1) { VielaMahtuu = false; }
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

    for (int a = 0; a != TIEDOT.size(); a++) {
        if (TIEDOT.at(a).etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka <<
            " " << TIEDOT.at(a).hattukoko << endl;
            break;
        }

        if (a == TIEDOT.size() - 1 && TIEDOT.at(a).etunimi != nimi) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}


/** Listaa kaikki henkilöt lkm kokoisessa
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(vector<tietue> TIEDOT) {
	for (int a = 0; a < TIEDOT.size(); a++) {
        cout << "Henkilö " << a << ": " << TIEDOT.at(a).etunimi << " "
        << TIEDOT.at(a).koulumatka << " " << TIEDOT.at(a).hattukoko << endl;
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
	
    for (int a = 0; a < TIEDOT.size(); a++) {
        if (TIEDOT.at(a).etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka <<
            " " << TIEDOT.at(a).hattukoko << endl;
			cout << "Haluatko poistaa henkilön tiedot? k/e" << endl;
			cin >> vastaus;
			poistokohta = a;
			
			if (vastaus == "k") {
				for (int b = a; b < TAULUN_MAX_KOKO - 1; b++) {
					TIEDOT.erase(TIEDOT.begin() + (poistokohta-1));
					/**TIEDOT[b].etunimi = TIEDOT[b+1].etunimi;
					*TIEDOT[b].koulumatka = TIEDOT[b+1].koulumatka;
					*TIEDOT[b].hattukoko = TIEDOT[b+1].hattukoko;
					*/
				}
			 }
			
		else if (vastaus == "e") break;

		else {
			cout << "Syötä 'e' tai 'k'!" << endl;
		}
        
		break;
        }

        if ((a == TIEDOT.size() - 1) && (TIEDOT.at(a).etunimi != nimi)) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}