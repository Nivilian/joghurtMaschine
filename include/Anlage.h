#ifndef ANLAGE_H
#define ANLAGE_H

// Laden der Deklaration der ben�tigten Klassen
#include "Zutatenbehaelter.h"
#include "Becherbehaelter.h"
#include "Becher.h"


// Diese Klasse wird verwendet um eine Anlage zu erstellen
// Eine Anlage besteht in diesem Fall aus einem Becherbeh�lter und zwei Zuatenbeh�lter
// Au�erdem kann nur ein Becher gerade in der Anlage sein
class Anlage
{
    public:
        // Konstruktor
        Anlage();

        // Destruktor
        ~Anlage();

        // Methode um einen neuen Joghurt zu bestellen
        // Gibt true zur�ck, wenn die Bestellung erfolgreich war
        bool bJoghurtBestellen();

        // Methode um den aktuellen Zustand der Anlage in der Konsole auzugeben
        void printZustand();

    protected:

    private:

        // Enth�lt den aktuellen Becher, welcher bef�llt werden soll
        Becher m_Becher;

        // Enth�lt den Beh�lter f�r den Joghurt
        ZutatenBehaelter m_JoghurtBehaelter;

        // Enth�lt den Beh�lter f�r das Topping
        ZutatenBehaelter m_ToppingBehaelter;

        // Enth�lt den Beh�lter f�r die Becher
        BecherBehaelter m_BecherBehaelter;

        // Variable um zu tracken wie viele Becher schon bef�llt wurden
        unsigned int m_uiID;
};

#endif // ANLAGE_H
