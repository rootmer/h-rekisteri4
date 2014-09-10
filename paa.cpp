/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*
*/

#include <iostream>
#include <vector>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien m��rittelyt. Taulukon koko
*   m��ritetty vakiomuuttujassa. tauluTemp t�ss� koska
*   osoitinta ei voi m��ritt�� vakion kautta. 
*/
const int taulunKoko = 10;
int tauluTemp = taulunKoko;
int *pTauluKoko = &tauluTemp;
bool taynna = false;
const string tiedosto = "tiedosto.dat";


/** Ohjelman main funktio
*
*/
int main(void)
{
    /** tietuevectorin kokona 10 alkiota,
    *   m��ritetty vakiomuuttujassa taulunkoko
    */
    vector<tietue> hRekisteri(taulunKoko);
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
			LisaaHenkilo(hRekisteri,pTauluKoko);
        }

        /** Listaa k�ytt�j�n haluaman
        *   henkil�n tiedot
        *
        */
        else if (valinta == 2) {
            TulostaHenkilo(hRekisteri);
        }

        /** Listaa kaikki henkil�tiedot
        *   taulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(hRekisteri,taulunKoko);
        }

		/** Poistaa henkil�n tiedot
		*
		*
		*/
		else if (valinta == 4) {
			PoistaHenkilo(hRekisteri);
		}

		else if (valinta == 5) {
			TallennaTiedostoon(tiedosto,hRekisteri);
		}

		/** Tallenna tiedostot tiedostoon
		*
		*
		*
		*/
		else if (valinta == 6) {
			LueTiedostosta(tiedosto,hRekisteri);
		}

        else cout << endl << "Valitse uudelleen" << endl;

    } while (valinta != 0);
}