/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*   Tekij�: Toni Turpeinen
*   PVM: 14.11.2014
*   Versio: 0.9.9
*/

/** Tarpeelliset kirjastot k�ytt��n */
#include <iostream>
#include <vector>

/** Otsaketiedoston sis�llytt�minen */
#include "maarittely.h"

/** Helpottaa cinien ja coutien k�ytt�� */
using namespace std;

/** Globaalien muuttujien m��rittelyt. Taulukon 
*   maksimikoko m��ritetty vakiomuuttujassa
*/
bool VielaMahtuu = true;
const int TAULUN_MAX_KOKO = 7;


/** Ohjelman main funktio
*
*/
int main(void)
{
	/** Tietuevectorin 'HRekisteri' alustus.
	*   tietuevectorin max -kokona 10 alkiota,
	*   m��ritetty vakiomuuttujassa 'TAULUN_MAX_KOKO'
	*/
	vector<tietue> HRekisteri;
	

	/** Testausta helpottamaan 5 valmista tietuette vectoriin */
	//HRekisteri.push_back(tietue());
	//HRekisteri.at(0).EtuNimi = "Teppo";
	//HRekisteri.at(0).KouluMatka = 0.9f;
	//HRekisteri.at(0).HattuKoko = 26;
	//HRekisteri.push_back(tietue());
	//HRekisteri.at(1).EtuNimi = "Auvo";
	//HRekisteri.at(1).KouluMatka = 1.4f;
	//HRekisteri.at(1).HattuKoko = 27;
	//HRekisteri.push_back(tietue());
	//HRekisteri.at(2).EtuNimi = "Tyyne";
	//HRekisteri.at(2).KouluMatka = 7.4f;
	//HRekisteri.at(2).HattuKoko = 15;
	//HRekisteri.push_back(tietue());
	//HRekisteri.at(3).EtuNimi = "Marko";
	//HRekisteri.at(3).KouluMatka = 5.4f;
	//HRekisteri.at(3).HattuKoko = 31;
	//HRekisteri.push_back(tietue());
	//HRekisteri.at(4).EtuNimi = "Marko";
	//HRekisteri.at(4).KouluMatka = 11.4f;
	//HRekisteri.at(4).HattuKoko = 25;
	

	int valinta = 99;

    do {

        /** Valikosta poistuminen
        *   sy�tt�m�ll� 0
        */
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1
        *   lis�t��n henkil�tieto
        */
        else if (valinta == 1) {
			HRekisteri = LisaaHenkilo(HRekisteri);
        }

        /** Listaa k�ytt�j�n haluaman
        *   henkil�n tiedot
        */
        else if (valinta == 2) {
            TulostaHenkilo(HRekisteri);
        }

        /** Listaa kaikki henkil�tiedot
        *   taulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(HRekisteri);
        }

		/** Poistaa k�ytt�j�n haluaman henkil�n tiedot */
		else if (valinta == 4) {
			HRekisteri = PoistaHenkilo(HRekisteri);
		}

		/** Jos valinta ei ole 0 tai 4 v�lilt�, pyydet��n valitsemaan uudelleen */
        else cout << endl << "Valitse uudelleen" << endl;

		/** Ohjelma loppuu valinnalla 0 */
    } while (valinta != 0);
}