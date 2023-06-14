#ifndef ANLAGE_H
#define ANLAGE_H

// Laden der Deklaration der benötigten Klassen
#include "Zutatenbehaelter.h"
#include "Becherbehaelter.h"
#include "Becher.h"


// Diese Klasse wird verwendet um eine Anlage zu erstellen
// Eine Anlage besteht in diesem Fall aus einem Becherbehälter und zwei Zuatenbehälter
// Außerdem kann nur ein Becher gerade in der Anlage sein
class Anlage
{
    public:
        // Konstruktor
        Anlage();

        // Destruktor
        ~Anlage();

        // Methode um einen neuen Joghurt zu bestellen
        // Gibt true zurück, wenn die Bestellung erfolgreich war
        bool bJoghurtBestellen();

        // Methode um den aktuellen Zustand der Anlage in der Konsole auzugeben
        void printZustand();

    protected:

    private:

        // Enthält den aktuellen Becher, welcher befüllt werden soll
        Becher m_Becher;

        // Enthält den Behälter für den Joghurt
        ZutatenBehaelter m_JoghurtBehaelter;

        // Enthält den Behälter für das Topping
        ZutatenBehaelter m_ToppingBehaelter;

        // Enthält den Behälter für die Becher
        BecherBehaelter m_BecherBehaelter;

        // Variable um zu tracken wie viele Becher schon befüllt wurden
        unsigned int m_uiID;
};

#endif // ANLAGE_H
