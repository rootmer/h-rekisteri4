/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Kun taulukko täynnä
*   ohjelma ilmoittaa siitä.
*
*/

#include <iostream>
#include <vector>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien määrittelyt
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
    *   määritetty vakiomuuttujassa taulunkoko
    */
    vector<tietue> HRekisteri;
	int valinta = 99;

    do {

        /** Valikosta poistuminen
        *   syöttämällä 0
        */
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1
        *   lisätään henkilötieto
        */
        else if (valinta == 1) {
			LisaaHenkilo(HRekisteri);
        }

        /** Listaa käyttäjän haluaman
        *   henkilön tiedot
        *
        */
        else if (valinta == 2) {
            TulostaHenkilo(HRekisteri);
        }

        /** Listaa kaikki henkilötiedot
        *   taulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(HRekisteri);
        }

		/** Poistaa henkilön tiedot
		*
		*
		*/
		else if (valinta == 4) {
			PoistaHenkilo(HRekisteri);
		}

        else cout << endl << "Valitse uudelleen" << endl;

    } while (valinta != 0);
}