/** Tarpeelliset kirjastot k�ytt��n */
#include <iostream>
#include <string>
#include <vector>

/** Otsaketiedoston sis�llytt�minen */
#include "maarittely.h"

/** Helpottaa coutien ja cinien k�ytt�� */
using namespace std;

/** Valikko n�kyville
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


/** Henkil�n lis��miseen tarkoitettu
*   aliohjelma. Tarkistaa my�s onko tilaa tiedoille.
*   Parametrin� vectorin pointteri jotta voidaan
*   muuttaa aliohjelman ulkopuolista arvoa
*/
void LisaaHenkilo(vector<tietue> TIEDOT) {
	int kohta = 99;
	
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
		TIEDOT.push_back( { EtuNimi, KouluMatka,HattuKoko } );
		if (kohta == TAULUN_MAX_KOKO - 1) { VielaMahtuu = false; }
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

    for (int a = 0; a != TIEDOT.size(); a++) {
        if (TIEDOT.at(a).etunimi == nimi) {
            cout << endl << "L�ytyi henkil�: " << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka <<
            " " << TIEDOT.at(a).hattukoko << endl;
            break;
        }

        if (a == TIEDOT.size() - 1 && TIEDOT.at(a).etunimi != nimi) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}


/** Listaa kaikki henkil�t lkm kokoisessa
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(vector<tietue> TIEDOT) {
	for (int a = 0; a < TIEDOT.size(); a++) {
        cout << "Henkil� " << a << ": " << TIEDOT.at(a).etunimi << " "
        << TIEDOT.at(a).koulumatka << " " << TIEDOT.at(a).hattukoko << endl;
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
	
    for (int a = 0; a < TIEDOT.size(); a++) {
        if (TIEDOT.at(a).etunimi == nimi) {
            cout << endl << "L�ytyi henkil�: " << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka <<
            " " << TIEDOT.at(a).hattukoko << endl;
			cout << "Haluatko poistaa henkil�n tiedot? k/e" << endl;
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
			cout << "Sy�t� 'e' tai 'k'!" << endl;
		}
        
		break;
        }

        if ((a == TIEDOT.size() - 1) && (TIEDOT.at(a).etunimi != nimi)) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}