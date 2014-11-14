#ifndef MAARITTELY_H
#define MAARITTELY_H


/** Tietue joka tulee pit‰m‰‰n sis‰ll‰‰n
*   nimen, koulumatkan pituuden sek‰ hatun
*   koon. Oletuksena etunimi- j‰sen alustetaan tilaan
*   "empty" jotta voidaan tiet‰‰ mik‰ alkio on ns. tyhj‰.
*/
struct tietue {
    std::string EtuNimi;
    float KouluMatka;
    int HattuKoko;

	/** Tietueen alustus "emptyksi" */
	tietue() { 
		EtuNimi = "empty"; 
		KouluMatka = 0.0; 
		HattuKoko = 0;
	}

	tietue(std::string nimi,float matka,int hattu) {
		EtuNimi = nimi;
		KouluMatka = matka;
		HattuKoko = hattu;
	}
};

/** Vakiomuuttujia
*	
*/
extern const int TAULUN_MAX_KOKO;
extern bool VielaMahtuu;

/** aliohjelmien prototyypit
*	vectoriyhteensopivina
*/
int valikko(void);
std::vector<tietue> LisaaHenkilo(std::vector<tietue> Rekisteri);
void TulostaHenkilo(std::vector<tietue> Rekisteri);
void TulostaKaikkiHenkilot(std::vector<tietue> Rekisteri);
std::vector<tietue> PoistaHenkilo(std::vector<tietue> Rekisteri);

#endif