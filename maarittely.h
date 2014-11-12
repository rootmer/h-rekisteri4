#ifndef MAARITTELY_H
#define MAARITTELY_H


/** Tietue joka tulee pit‰m‰‰n sis‰ll‰‰n
*   nimen, koulumatkan pituuden sek‰ hatun
*   koon.
*/
struct tietue {
    std::string etunimi;
    float koulumatka;
    int hattukoko;
};

/** Vakiomuuttujat t‰ss‰
*	m‰‰riteltyn‰ ja alustettuna
*/
extern const int TAULUN_MAX_KOKO;
extern bool VielaMahtuu;

/** aliohjelmien prototyypit
*	muutettu vectoriyhteensopivaksi
*/
int valikko(void);
void LisaaHenkilo(std::vector<tietue>);
void TulostaHenkilo(std::vector<tietue>);
void TulostaKaikkiHenkilot(std::vector<tietue>);
void PoistaHenkilo(std::vector<tietue>);


#endif