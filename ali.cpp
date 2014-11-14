/** Tarpeellisten kirjastojen käyttöönotto */
#include <iostream>
#include <string>
#include <vector>

/** Otsaketiedoston sisällyttäminen */
#include "maarittely.h"

/** Helpottaa cinien ja coutien käyttöä */
using namespace std;

/** Valikko aliohjelmana jotta käyttäjä tietää
*   mitä tapahtuu mistäkin numerosta
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
vector<tietue> LisaaHenkilo(vector<tietue> TIEDOT) {
	if (int(TIEDOT.size()) < TAULUN_MAX_KOKO) VielaMahtuu = true;

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

		/** Varmistetaan että ensimmäinen arvo menee vektoriin nätisti,
		*   oppia otettu allaolevan linkin kautta 
		*   http://stackoverflow.com/questions/8067338/c-vector-of-structs-initialization
		*/
		if ( int(TIEDOT.size()) == 0) {
			TIEDOT.push_back(tietue());
			TIEDOT[0].EtuNimi = EtuNimi;
			TIEDOT[0].KouluMatka = KouluMatka;
			TIEDOT[0].HattuKoko = HattuKoko;
			return TIEDOT;
		}

		/** Normaalitilanteen vectoriin tietojen lisääminen */
		else { 
			tietue LISAYS (EtuNimi, KouluMatka, HattuKoko);
			TIEDOT.push_back(LISAYS);

			/** Tarkistetaan että vektorin koko ei ylitä kiinteää 
			*   rajaa 'TAULUN_MAX_KOKO'. Sen mukaisesti muuttuu
			*   'VielaMahtuu'.
			*/
			if (int(TIEDOT.size()) == TAULUN_MAX_KOKO) VielaMahtuu = false;
			
			return TIEDOT;
			}
	}

	/** Taulukko täynnä, ei tehdä muuta kuin ilmoitus asiasta */
	else if (!VielaMahtuu) { 
		cout << "\nTaulukko täynnä!" << endl;
		return TIEDOT;
	}
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
*   tietuevectorissa TIEDOT
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
vector<tietue> PoistaHenkilo(vector<tietue> TIEDOT) {
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
				TIEDOT.erase(TIEDOT.begin() + poistokohta);
				return TIEDOT;
			}
			 
			
			else if (vastaus == "e") return TIEDOT;
        }

        if ( (a == int(TIEDOT.size()) - 1 ) && (TIEDOT.at(a).EtuNimi != nimi) ) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
			return TIEDOT;
        }
    }
}