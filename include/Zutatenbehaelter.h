#ifndef ZUTATENBEHAELTER_H
#define ZUTATENBEHAELTER_H

// Einf�gen der ben�tigten Deklarationen
#include "Behaelter.h"
#include "Becher.h"

// Diese Klasse wird verwendet um einen Zutatenbeh�lter darzustellen
// Die Klasse erbt von der KLasse Behaelter
class ZutatenBehaelter : public Behaelter
{
    public:
        // Konstruktor
        ZutatenBehaelter();
        // �berladener Konstruktor
        ZutatenBehaelter(std::string sInhalt, float fFuellstand);
        // Destruktor
        ~ZutatenBehaelter();

        // Gibt den aktuellen Zustand des Beh�lters in der Konsole aus
        // "�berschreibt" die virtuelle Methode aus der Eltern-Klasse
        void printBehaelterZustand();

        // Liest die einzuf�llende Menge �ber die Konsole ein
        float fZutatenMengeEinlesen();

        // Bef�llt den Becher, welcher als Zeiger �bergeben wird, mit der Menge die auch �bergeben wird
        // Gibt true zur�ck, wenn das bef�llen geklappt hat
        bool bBecherBefuellen(Becher* pBecher, float fZutatenMenge);

        // Bef�llt den Becher, welcher als Zeiger �bergeben wird, komplett
        // Es handelt sich hierbei um eine �berladene Methode, da es schon eine Methode gibt, die den selben Namen hat
        // Gibt true zur�ck, wenn das bef�llen geklappt hat
        bool bBecherBefuellen(Becher* pBecher);

    protected:

    private:

        // Attribut beinhaltet die Menge an Zutaten die aktuell im Beh�lter ist
        float m_fFuellstand;

        // Attribut kann verwendet werden, um den aktuellen Becher, welche bef�llt werden soll, zu speichern
        Becher* m_pBecher;

};

#endif // ZUTATENBEHAELTER_H
