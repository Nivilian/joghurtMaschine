#include "../include/Zutatenbehaelter.h"
#include <iostream>

// Standard-Konstruktor
ZutatenBehaelter::ZutatenBehaelter() : Behaelter()
{
    m_fFuellstand = 0;
}

// �berladener Konstruktor
// Achtung: Aufruf des Konstruktors der Eltern-Klasse nach dem Doppelpunkt mit �bergabe des Parameters std::string sInhalt
ZutatenBehaelter::ZutatenBehaelter(std::string sInhalt, float fFuellstand) : Behaelter(sInhalt)
{
    // Setzen des aktuellen F�llstands in diesem Beh�lter
    m_fFuellstand = fFuellstand;
}

// Destruktor
ZutatenBehaelter::~ZutatenBehaelter()
{
    //dtor
}

// Gibt den aktuellen Zustand des Beh�lters in der Konsole aus
// "�berschreibt" die virtuelle Methode aus der Eltern-Klasse
void ZutatenBehaelter::printBehaelterZustand()
{
    std::cout << std::endl;
    std::cout << "Zustand Zutatenbehaelter:" << std::endl;
    std::cout << "Inhalt: " << m_sInhalt << std::endl;
    std::cout << "Fuellstand: " << m_fFuellstand << std::endl;
    std::cout << std::endl;
}

// Bef�llt den Becher, welcher als Zeiger �bergeben wird, mit der Menge die auch �bergeben wird
// Gibt true zur�ck, wenn das bef�llen geklappt hat
bool ZutatenBehaelter::bBecherBefuellen(Becher* pBecher, float fZutatenMenge)
{
    // Speichern des �bergebenen Pointers auf den Becher im Attribut dieser Klasse
    m_pBecher = pBecher;

    // Zugriff auf Methoden des Objekt erfolgt hier �ber den Pfeiloperator (PointerAufObjekt->Methode)
    // Das muss gemacht werden, da m_pBecher vom Typ Pointer ist
    float fRestMenge = m_pBecher->fGetMaxFuellMenge() - m_pBecher->fGetFuellMenge();

    // �berpr�fen ob noch genug Platz im Becher ist
    if(fZutatenMenge <= fRestMenge)
    {

        // Berechnung der neuen F�llmenge
        float fBecherFuelMenge = m_pBecher->fGetFuellMenge() + fZutatenMenge;

        // Setzen der neuen F�llmenge
        // Das passiert hier �ber den Punktoperator, da der Poniter durch den Stern erst
        // dereferenziert wird. (*m_pBEcher) ist also als Ganzes ein Objekt vom Typ Becher
        // Dann Zugriff auf Methode durch den Punktoperator (Objekt.Methode)
        (*m_pBecher).setFuellMenge(fBecherFuelMenge);

        // F�llstand anpassen
        m_fFuellstand -= fZutatenMenge;

        // Ausgabe wie voll der aktuelle Becher ist
        std::cout << "Im Becher sind " << (*m_pBecher).fGetFuellMenge() << " ml befuellt" << std::endl << std::endl;

        return true;
    }
    else{

        std::cout << "Es ist nicht genug Platz im Becher!" << std::endl;
        std::cout << "Der Becher wurde nicht befuellt!" << std::endl;

        return false;
    }
}

// Bef�llt den Becher, welcher als Zeiger �bergeben wird, komplett
// Es handelt sich hierbei um eine �berladene Methode, da es schon eine Methode gibt, die den selben Namen hat
// Gibt true zur�ck, wenn das bef�llen geklappt hat
bool ZutatenBehaelter::bBecherBefuellen(Becher* pBecher)
{
    // Rest F�llmenge berechnen
    float fRestFuellmenge = pBecher->fGetMaxFuellMenge() - pBecher->fGetFuellMenge();

    // Call zur anderen Methode, damit man die nicht erneut implementieren muss
    return bBecherBefuellen(pBecher, fRestFuellmenge);
}


// Liest die einzuf�llende Menge �ber die Konsole ein
float ZutatenBehaelter::fZutatenMengeEinlesen()
{
    float fZutatenMenge;

    std::cout << "Wie viel " << m_sInhalt << " wollen Sie in den Becher fuellen?" << std::endl;
    std::cin >> fZutatenMenge;

    // �bepr�fen ob eingelesener Wert g�ltig ist
    while(std::cin.fail() || fZutatenMenge < 0)
    {
        std::cout << "Falscheingabe! Bitte geben Sie eine positive Zahl oder 0 ein!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> fZutatenMenge;
    }

    // �berpr�fen, ob genug von der Zutat vorhanden ist
    if(fZutatenMenge > m_fFuellstand)
    {
        std::cout << "Es gibt nicht genug " << m_sInhalt << ". Es werden nur " << m_fFuellstand << " eingefuellt." << std::endl;

        fZutatenMenge = m_fFuellstand;
    }


    return fZutatenMenge;
}
