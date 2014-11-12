/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*
*/

#include <iostream>
#include <vector>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien m��rittelyt
*/
const string tiedosto = "tiedosto.dat";
const int TAULUN_MAX_KOKO = 3;
bool VielaMahtuu = true;


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