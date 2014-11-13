/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*   Tekij�: Toni Turpeinen
*   PVM: 12.11.2014
*   Versio: 0.9.0
*/

#include <iostream>
#include <vector>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien m��rittelyt. Taulukon koko
*   m��ritetty vakiomuuttujassa. tauluTemp t�ss� koska
*   osoitinta ei voi m��ritt�� vakion kautta. 
*/
bool VielaMahtuu = true;
const int TAULUN_MAX_KOKO = 10;
const string tiedosto = "tiedosto.dat";


/** Ohjelman main funktio
*
*/
int main(void)
{
	/** tietuevectorin kokona 10 alkiota,
	*   m��ritetty vakiomuuttujassa taulunkoko
	*/
	vector<tietue> HRekisteri;
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
			LisaaHenkilo(HRekisteri);
        }

        /** Listaa k�ytt�j�n haluaman
        *   henkil�n tiedot
        *
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

		/** Poistaa henkil�n tiedot
		*
		*
		*/
		else if (valinta == 4) {
			PoistaHenkilo(HRekisteri);
		}

        else cout << endl << "Valitse uudelleen" << endl;

    } while (valinta != 0);
}