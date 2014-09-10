#include <iostream>
#include <fstream>
#include <sstream>
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
    cout << "VALIKKO" << endl;
    cout << "0 - Lopeta" << endl;
    cout << "1 - Lisaa henkilo" << endl;
    cout << "2 - Listaa tietty henkilo" << endl;
    cout << "3 - Listaa kaikki henkilot" << endl;
	cout << "4 - Poista tietyn henkilon tiedot" << endl;
	cout << "5 - Tallenna tiedot tiedostoon" << endl;
	cout << "6 - Lue tiedot tiedostosta" << endl;
    cin >> valinta;
    return valinta;
}

/** Aliohjelma joka hakee henkilön tiedot
*   syötetyn nimen perusteella
*/
void TulostaHenkilo(vector<tietue> TIEDOT) {
	string nimi;
    cout << "Syötä hakemasi henkilön etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < taulunKoko; a++) {
        if (TIEDOT.at(a).etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka <<
            " " << TIEDOT.at(a).hattukoko << endl;
            break;
        }

        if (a == taulunKoko - 1 && TIEDOT.at(a).etunimi != nimi) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkilöt lkm kokoisessa
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(vector<tietue> TIEDOT, int lkm) {
	for (int a = 0; a < lkm; a++) {
        cout << "Henkilö " << a << ": " << TIEDOT.at(a).etunimi << " "
        << TIEDOT.at(a).koulumatka << " " << TIEDOT.at(a).hattukoko << endl;
    }
}

/** Henkilön lisäämiseen tarkoitettu
*   aliohjelma. Tarkistaa myös onko tilaa tiedoille.
*/
void LisaaHenkilo(vector<tietue> TIEDOT, int *lkm) {
	int kohta = 99;
    for (int a = 0; a < *lkm; a++) {
        if (TIEDOT.at(a).etunimi == "empty") {
            kohta = a;
            break;
        }
    }

    if (!taynna) {
        string eNimi;
        float kMatka;
        int hKoko;
        cout << "Henkilön etunimi" << endl;
        cin >> eNimi;
        cout << "Henkilön koulumatka" << endl;
        cin >> kMatka;
        cout << "Henkilön hatun koko" << endl;
        cin >> hKoko;
        TIEDOT.at(kohta).etunimi = eNimi;
        TIEDOT.at(kohta).koulumatka = kMatka;
        TIEDOT.at(kohta).hattukoko = hKoko;
        if (kohta == *lkm - 1) { taynna = true; }
    }

    else if (taynna) { cout << endl << "Taulukko täynnä!" << endl; }
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

    for (int a = 0; a < taulunKoko; a++) {
        if (TIEDOT.at(a).etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka <<
            " " << TIEDOT.at(a).hattukoko << endl;
			cout << "Haluatko poistaa henkilön tiedot? k/e" << endl;
			cin >> vastaus;
			poistokohta = a;
			
			if (vastaus == "k") {
				for (int b = a; b < taulunKoko - 1; b++) {
					TIEDOT.erase(TIEDOT.begin() + (poistokohta-1));
					/**TIEDOT[b].etunimi = TIEDOT[b+1].etunimi;
					*TIEDOT[b].koulumatka = TIEDOT[b+1].koulumatka;
					*TIEDOT[b].hattukoko = TIEDOT[b+1].hattukoko;
					*/
				}
			 }
			
		else if (vastaus == "e") break;
        
		break;
        }

        if ((a == taulunKoko - 1) && (TIEDOT.at(a).etunimi != nimi)) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}

/** Tallentaa taulukon tiedot tiedostoon
*
*/
void TallennaTiedostoon(string tiedosto,vector<tietue> TIEDOT) {
	ofstream ofilu(tiedosto);
	if (ofilu.is_open())
	{	
		for (int a = 0; a < taulunKoko; a++) {
			ofilu << TIEDOT.at(a).etunimi << " " << TIEDOT.at(a).koulumatka
			      << " " << TIEDOT.at(a).hattukoko << endl;
		}
		ofilu.close();
	}
	else cout << "Ei voitu avata tiedostoa";
}

/** Lukee tiedot tiedostosta
*	ja tallentaa ne dynaamiseen taulukkoon
*/
void LueTiedostosta(string tiedosto,vector<tietue> TIEDOT) {
	string rivi;
	ifstream ifilu (tiedosto);
	if (ifilu.is_open())
	{
		string erotin = " ";
		float kmatka;
		int hkoko;
		int indeksi = 0;
		
		while (getline (ifilu,rivi)) {
			cout << rivi << endl;
			string nimi = rivi.substr(0, rivi.find(erotin));
			istringstream(rivi.substr(0, rivi.find(erotin))) >> kmatka;
			istringstream(rivi.substr(0, rivi.find(erotin))) >> hkoko;
			TIEDOT.at(indeksi).etunimi = nimi;
			TIEDOT.at(indeksi).etunimi = kmatka;
			TIEDOT.at(indeksi).etunimi = hkoko;
			indeksi++;
		}
		for (int a = indeksi; a < *pTauluKoko; a++) {
			TIEDOT.at(a).etunimi = "empty";
			TIEDOT.at(a).koulumatka = 0.0;
			TIEDOT.at(a).hattukoko = 0;
		}

		ifilu.close();
	}
	else cout << "Ei voitu avata tiedostoa"; 
}