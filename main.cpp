#include <iostream>
#include <string>

#include "Anlage.h"

// In der main-Funktion startet die Ausführung des Programms
int main()
{
    // Deklaration und Initialisierung von Variablen
    int iJoghurtBestellen = 0;

    // Erstellen des Objekts anlage
    Anlage anlage;

    // Start der Schleif zum Abfüllen der Joghurtbecher
    do
    {
        anlage.printZustand();

        // Hier wird die als string übergebene Frage in der Konsole ausgegeben
        std::cout << "Wollen Sie einen Joghurt bestellen?" << std::endl;
        std::cout << "0 - nein" << std::endl;
        std::cout << "1 - ja" << std::endl;

        // Einlesen eines int Wertes
        std::cin >> iJoghurtBestellen;


        // Übeprüfen ob eingelesener Wert gültig ist
        while(std::cin.fail() || (iJoghurtBestellen != 1 && iJoghurtBestellen != 0))
        {
            std::cout << "Falscheingabe! Bitte geben Sie 0 oder 1 ein:" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> iJoghurtBestellen;
        }

        if(iJoghurtBestellen == 1)
        {
            // Aufruf der Methode bJoghurtBestellen vom Objekt anlage
            int bBestellungErfolgreich = anlage.bJoghurtBestellen();

            if(bBestellungErfolgreich == false)
            {
                std::cout << "Die Bestellung war nicht erfolgreich!" << std::endl;
                std::cout << "Das Programm wird beendet" << std::endl;

                iJoghurtBestellen = 0;
            }
        }

    // Schleife wird so lange wiederholt, bis iJoghurtBestellen nicht mehr 1 ist
    }while(iJoghurtBestellen == 1);

    return 0;
}


