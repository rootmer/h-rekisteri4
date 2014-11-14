/** Tarpeellisten kirjastojen k�ytt��notto */
#include <iostream>
#include <string>
#include <vector>

/** Otsaketiedoston sis�llytt�minen */
#include "maarittely.h"

/** Helpottaa cinien ja coutien k�ytt�� */
using namespace std;

/** Valikko aliohjelmana jotta k�ytt�j� tiet��
*   mit� tapahtuu mist�kin numerosta
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
vector<tietue> LisaaHenkilo(vector<tietue> TIEDOT) {
	if (int(TIEDOT.size()) < TAULUN_MAX_KOKO) VielaMahtuu = true;

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

		/** Varmistetaan ett� ensimm�inen arvo menee vektoriin n�tisti,
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

		/** Normaalitilanteen vectoriin tietojen lis��minen */
		else { 
			tietue LISAYS (EtuNimi, KouluMatka, HattuKoko);
			TIEDOT.push_back(LISAYS);

			/** Tarkistetaan ett� vektorin koko ei ylit� kiinte�� 
			*   rajaa 'TAULUN_MAX_KOKO'. Sen mukaisesti muuttuu
			*   'VielaMahtuu'.
			*/
			if (int(TIEDOT.size()) == TAULUN_MAX_KOKO) VielaMahtuu = false;
			
			return TIEDOT;
			}
	}

	/** Taulukko t�ynn�, ei tehd� muuta kuin ilmoitus asiasta */
	else if (!VielaMahtuu) { 
		cout << "\nTaulukko t�ynn�!" << endl;
		return TIEDOT;
	}
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
*   tietuevectorissa TIEDOT
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
vector<tietue> PoistaHenkilo(vector<tietue> TIEDOT) {
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
				TIEDOT.erase(TIEDOT.begin() + poistokohta);
				return TIEDOT;
			}
			 
			
			else if (vastaus == "e") return TIEDOT;
        }

        if ( (a == int(TIEDOT.size()) - 1 ) && (TIEDOT.at(a).EtuNimi != nimi) ) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
			return TIEDOT;
        }
    }
}