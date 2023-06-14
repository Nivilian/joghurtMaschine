#ifndef BEHAELTER_H
#define BEHAELTER_H

// Einf�gen der Bibliothek string, da in dieser Klasse strings verwendet werden
#include <string>

// Diese Klasse wird als Elternklasse verwendet
// Die Klassen Becherbehaelter und Zutatenbehaelter erben von dieser Klasse
// Das bedeutet, dass die hier deklarierten Attribute und Methoden auch in den Kind-Klassen vorhanden sind
// Es handelt sich um eine abstrakte Klasse, da eine virtuelle Methode in dieser Klasse vorhanden ist
class Behaelter
{
    public:
        // Konstruktor
        Behaelter();
        // �berladener Konstruktor
        Behaelter(std::string sInhalt);
        // Destruktor
        ~Behaelter();

        // Virtuelle Methode
        // Diese Methode muss in den Kind-Klassen implementiert werden, damit ein Objekt der Kind-Klasse erstellt werden kann
        // Wegen dieser Methode ist die Klasse abstrakt (d.h. es kann kein Objekt dieser Klasse erstellt werden)
        virtual void printBehaelterZustand()=0;

        // KEINE virtuelle Methode, d.h. diese Methode wir in der Behaelter.cpp Datei implementiert
        // Kann einfach von den Kind-Klassen verwendet werden
        // Methoden um den Inhalte des Beh�lters zu setzen und auszulesen
        // Es handelt sich um den Datentyp string
        // Daf�r muss die Headerdatei <string> eingef�gt werden
        // der Zugriff auf string geschieht �ber den namespace std (std::string)
        // ein string rep�sentiert eine Zeichenkette
        void setInhalt(std::string sInhalt);
        std::string sGetInhalt();

    protected:

        // Definiert ein Attribut, welches den Inhalt des Beh�lters als string enth�lt
        // ist als protected deklariert, damit driekt von den Kind-Klassen darauf zugegriffen werden kann
        std::string m_sInhalt;

    private:
};

#endif // BEHAELTER_H
