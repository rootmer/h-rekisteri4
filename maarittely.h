#ifndef MAARITTELY_H
#define MAARITTELY_H


/** Tietue joka tulee pit‰m‰‰n sis‰ll‰‰n
*   nimen, koulumatkan pituuden sek‰ hatun
*   koon. Oletuksena etunimi- j‰sen alustetaan tilaan
*   "empty" jotta voidaan tiet‰‰ mik‰ alkio on ns. tyhj‰.
*/
struct tietue {
    std::string etunimi;
    float koulumatka;
    int hattukoko;
    tietue(): etunimi("empty"), koulumatka(0.0), hattukoko(0) {}
};

/** taulukon koko vakiomuuttujana
*	
*/
extern const int taulunKoko;
extern int tauluTemp;
extern int *pTauluKoko;
extern bool taynna;

/** aliohjelmien prototyypit
*
*/
int valikko(void);
void TulostaHenkilo(std::vector<tietue> TIEDOT);
void TulostaKaikkiHenkilot(std::vector<tietue> TIEDOT, int lkm);
void LisaaHenkilo(std::vector<tietue> TIEDOT, int *lkm);
void PoistaHenkilo(std::vector<tietue> TIEDOT);
void TallennaTiedostoon(std::string tiedosto,std::vector<tietue> TIEDOT);
void LueTiedostosta(std::string tiedosto,std::vector<tietue> TIEDOT);

#endif