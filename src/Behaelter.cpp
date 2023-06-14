#include "../include/Behaelter.h"

// Konstruktor
Behaelter::Behaelter()
{
    m_sInhalt = "Es wurde kein Inhalt gesetzt!";
}

// Überladener Konstruktor, dieser setzt den Inhalt direkt
Behaelter::Behaelter(std::string sInhalt)
{
    m_sInhalt = sInhalt;
}

// Destruktor
Behaelter::~Behaelter()
{
    //dtor
}

// Setzt den Inhalt des Behälters
// Diese Methode wird vererbt, kann also von den Kind-Klassen verwendet werden
void Behaelter::setInhalt(std::string sInhalt)
{
    m_sInhalt = sInhalt;
}

// Gibt den Inhalt des Behälters zurück
// Diese Methode wird vererbt, kann also von den Kind-Klassen verwendet werden
std::string Behaelter::sGetInhalt()
{
    return m_sInhalt;
}

//Achtung! Keine Implementation der Methode printBehaelterZustand, da diese virtuell ist


