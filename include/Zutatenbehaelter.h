#ifndef ZUTATENBEHAELTER_H
#define ZUTATENBEHAELTER_H

// Einfügen der benötigten Deklarationen
#include "Behaelter.h"
#include "Becher.h"

// Diese Klasse wird verwendet um einen Zutatenbehälter darzustellen
// Die Klasse erbt von der KLasse Behaelter
class ZutatenBehaelter : public Behaelter
{
    public:
        // Konstruktor
        ZutatenBehaelter();
        // Überladener Konstruktor
        ZutatenBehaelter(std::string sInhalt, float fFuellstand);
        // Destruktor
        ~ZutatenBehaelter();

        // Gibt den aktuellen Zustand des Behälters in der Konsole aus
        // "Überschreibt" die virtuelle Methode aus der Eltern-Klasse
        void printBehaelterZustand();

        // Liest die einzufüllende Menge über die Konsole ein
        float fZutatenMengeEinlesen();

        // Befüllt den Becher, welcher als Zeiger übergeben wird, mit der Menge die auch übergeben wird
        // Gibt true zurück, wenn das befüllen geklappt hat
        bool bBecherBefuellen(Becher* pBecher, float fZutatenMenge);

        // Befüllt den Becher, welcher als Zeiger übergeben wird, komplett
        // Es handelt sich hierbei um eine überladene Methode, da es schon eine Methode gibt, die den selben Namen hat
        // Gibt true zurück, wenn das befüllen geklappt hat
        bool bBecherBefuellen(Becher* pBecher);

    protected:

    private:

        // Attribut beinhaltet die Menge an Zutaten die aktuell im Behälter ist
        float m_fFuellstand;

        // Attribut kann verwendet werden, um den aktuellen Becher, welche befüllt werden soll, zu speichern
        Becher* m_pBecher;

};

#endif // ZUTATENBEHAELTER_H
