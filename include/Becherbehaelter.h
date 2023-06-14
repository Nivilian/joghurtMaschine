#ifndef BECHERBEHAELTER_H
#define BECHERBEHAELTER_H

// Laden der benötigten Klassen
#include "Becher.h"
#include "Behaelter.h"

// Diese Klasse soll einen Becherbehälter darstellen
// Sie erbt von der Klasse Behaelter (sieht man an dem Syntax " <Kind-Klassen> : public <Eltern-Klasse>)
class BecherBehaelter : public Behaelter
{
    public:
        // Konstruktor
        BecherBehaelter();
        // Überladener Konstruktor
        // Erkennt man daran, dass der Name zum Standard-Konstrukto der selbe ist, aber Werte übergeben werden
        // Dieser Konstruktor wird verwendet, damit man ein Objekt der Klasse direkt mit den passenden Wreten initailisieren kann
        BecherBehaelter(std::string sInhalt, float fBecherGroesse, int iBecherAnzahl);
        // Destruktor
        ~BecherBehaelter();

        // Gibt den aktuellen Zustand des Behälters in der Konsole aus
        // "Überschreibt" die virtuelle Methode aus der Eltern-Klasse
        void printBehaelterZustand();

        // Erstellt einen Becher und speichert ihn in der Referenz
        // Rückgabe von false, wenn kein Becher mehr vorhanden ist
        bool bGetBecher(Becher& rBecher);

    protected:

    private:

        // Gibt die aktuelle Anzahl an Bechern an, welche im Behälter sind
        int m_iBecherAnzahl;

        // Gibt die Größe der Becher an, welche sich in diesem Behälter befinden
        float m_fBechergroesse;
};

#endif // BECHERBEHAELTER_H
