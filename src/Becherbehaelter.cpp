#include "BecherBehaelter.h"
#include <iostream>

// Konstruktor
BecherBehaelter::BecherBehaelter() : Behaelter()
{
    m_iBecherAnzahl = 3;
    m_fBechergroesse = 0;
}

// Überladener Konstruktor
// Achtung: Aufruf des Konstruktors der Eltern-Klasse nach dem Doppelpunkt mit Übergabe des Parameters std::string sInhalt
BecherBehaelter::BecherBehaelter(std::string sInhalt, float fBecherGroesse, int iBecherAnzahl) : Behaelter(sInhalt)
{
    m_iBecherAnzahl = iBecherAnzahl;
    m_fBechergroesse = fBecherGroesse;
}

// Destruktor
BecherBehaelter::~BecherBehaelter()
{
    //dtor
}

// Gibt den aktuellen Zustand des Behälters in der Konsole aus
// "Überschreibt" die virtuelle Methode aus der Eltern-Klasse
void BecherBehaelter::printBehaelterZustand()
{
    std::cout << std::endl;
    std::cout << "Zustand Becherbehaelter:" << std::endl;
    std::cout << "Inhalt: " << m_sInhalt << std::endl;
    std::cout << "Anzahl vorhandene Becher: " << m_iBecherAnzahl << std::endl;
    std::cout << std::endl;
}

// Erstellt einen Becher und speichert ihn in der Referenz
// Rückgabe von false, wenn kein Becher mehr vorhanden ist
bool BecherBehaelter::bGetBecher(Becher& rBecher)
{
    // Überprüfen ob noch ein Becher rim Behälter vorhanden ist
    if(m_iBecherAnzahl > 0)
    {
        // Erstellen eines neuen Becher-Objekts
        Becher becher = Becher();
        // Setzen der maximalen Füllmenge
        becher.setMaxFuellMenge(m_fBechergroesse);

        // Neuen Becher in die übergebne Refrenz schreiben
        // Damit "gibt" es den neu erstellten Becher nicht nur in dieser Funktion
        // sondern auch in der Anlage
        rBecher = becher;

        // Die Anzahl der Becher in diesem Behälter um eins verringern
        m_iBecherAnzahl--;

        // Rückgabe, dass die "Entnahme" erfolgreich war
        return true;
    }
    else
    {
        // Rückgabe, dass die kein Becher mehr im Behälter war
        return false;
    }
}
