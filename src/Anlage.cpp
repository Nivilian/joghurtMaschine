#include "Anlage.h"
#include <iostream>

//Standard-Konstruktor
Anlage::Anlage()
{
    // Erstellen des Objekts m_BecherBehaelter der Klasse Becher.
    // Ich erstelle hiermit sozusagen einen Beh�lter in
    // der Anlage der 4x "Kleine Becher" enth�lt, welche ein Volumen von 250 ml haben
    m_BecherBehaelter = BecherBehaelter("Kleine Becher (250 ml)", 250, 4);

    // Erstellen des Objekts m_JoghurtBehaelter der Klassse Zutatenbehaelter mit einem Inhalt von 5000ml Joghurt
    m_JoghurtBehaelter = ZutatenBehaelter("Joghurt", 5000);

    // Erstellen des Objekts m_ToppingBehaelter der Klassse Zutatenbehaelter mit einem Inhalt von 5000ml Kirschtopping
    m_ToppingBehaelter = ZutatenBehaelter("Kirsch Topping", 200);

    // Initialisieren der ID zum Z�hlen als 0
    m_uiID = 0;
}

// Destruktor, hier muss nichts gemacht werden
Anlage::~Anlage()
{
    //dtor
}

// Methode um einen neuen Joghurt zu bestellen
bool Anlage::bJoghurtBestellen()
{
    // Becher aus dem Becherbeh�lter holen
    bool bGetBecherErfolgreich = m_BecherBehaelter.bGetBecher(m_Becher);

    // Wenn der Becher erfolgreich aus dem BechebEh�lter "entnommen" wurde
    if(bGetBecherErfolgreich)
    {
        // Variable zum Einlesen der Eingabe
        int iEingabe;

        do
        {
            // Hier wird die als string �bergebene Frage in der Konsole ausgegeben
            std::cout << "Mit was wollen Sie den Becher befuellen?" << std::endl;
            std::cout << "1 - Joghurt" << std::endl;
            std::cout << "2 - Topping" << std::endl;
            std::cout << "0 - Abfuellen beenden" << std::endl;

            // Einlesen eines int Wertes
            std::cin >> iEingabe;


            // �bepr�fen ob eingelesener Wert g�ltig ist
            while(std::cin.fail())
            {
                std::cout << "Falscheingabe! Bitte geben Sie 0, 1 oder 2 ein!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin >> iEingabe;
            }

            // Erstellung von lokalen Variablen
            bool bBecherBefuellt = false;
            float fZutatenMenge = 0;

            // Switch case, um die richtigen Aktionen durchzuf�hren
            switch(iEingabe)
            {
            case 0:
                // Beschreiben des RFID_Chips vom Becher
                m_Becher.setRFID(m_uiID);
                break;
            case 1:
                // Einlesen der F�llmenge an Joghurt
                fZutatenMenge = m_JoghurtBehaelter.fZutatenMengeEinlesen();
                // Versuch den Becher zu bef�llen, wenn das klappt dann ist bBecherBefuellt true, sonst false
                bBecherBefuellt = m_JoghurtBehaelter.bBecherBefuellen(&m_Becher, fZutatenMenge);
                break;
            case 2:
                // Einlesen der F�llmenge an Topping
                fZutatenMenge = m_ToppingBehaelter.fZutatenMengeEinlesen();
                // Versuch den Becher zu bef�llen, wenn das klappt dann ist bBecherBefuellt true, sonst false
                bBecherBefuellt = m_ToppingBehaelter.bBecherBefuellen(&m_Becher, fZutatenMenge);
                break;
            default:
                // Info, falls etwas Falsches eingegeben wurde
                std::cout << "Falscheingabe! Bitte geben Sie 0, 1 oder 2 ein!" << std::endl;
            }

        // Ausgabe wir so lange wiederholt, bis 0 eingegeben wurde
        }while(iEingabe!=0);


        return true;

    }
    // Ausgabe einer Info, wenn kein Becher mehr im Beh�lter war
    else
    {
        std::cout << "Es wurde kein Becher aus dem Becherbehaelter erhalten!" << std::endl;
        return false;
    }
}

// Methode um den aktuellen Zustand der Anlage in der Konsole auzugeben
void Anlage::printZustand()
{
    // Jeweils aufrufen der printBehaelterZustand-Methode der verschiedenen Objekte
    m_BecherBehaelter.printBehaelterZustand();
    m_JoghurtBehaelter.printBehaelterZustand();
    m_ToppingBehaelter.printBehaelterZustand();
}
