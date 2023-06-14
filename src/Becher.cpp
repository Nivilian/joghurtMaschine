#include "Becher.h"
#include <iostream>

// Konstruktor
Becher::Becher()
{
    //Am Anfang wird alles auf 0 gesetzt, damit wir einen definierten Wert haben
    m_fFuellMenge = 0;
    m_fMaxFuellMenge = 0;
}

// Destruktor
Becher::~Becher()
{
    //dtor
}

// Setzt die aktuelle F�llmenge
void Becher::setFuellMenge(float fFuellMenge)
{
    m_fFuellMenge = fFuellMenge;
}

// Gibt die aktuelle F�llmenge zur�ck
float Becher::fGetFuellMenge()
{
    return m_fFuellMenge;
}

// Gibt die maximale F�llmenge zur�ck
float Becher::fGetMaxFuellMenge()
{
    return m_fMaxFuellMenge;
}

// Setzt die maximale F�llmenge
void Becher::setMaxFuellMenge(float fMaxFuellMenge)
{
    m_fMaxFuellMenge = fMaxFuellMenge;
}

// Schreibt dir ID und die aktuelle F�llmenge auf den RFID-Chip
void Becher::setRFID(unsigned int& uiID)
{
    // Setzt die aktuelle uiID als ID des Chips
    m_RFID_Chip.setRFIDID(uiID);
    // uiID wird hochgez�hlt, da als Refrenz �bergeben gilt dies nicht nur in dieser MEthode!
    uiID++;

    // Schreibt die aktuelle F�llmenge in den RFID-Chip
    m_RFID_Chip.setFuellMenge(m_fFuellMenge);

    // Ausgabe in der Konsole als Info
    std::cout << "Der RFID Chip wurde beschrieben" << std::endl;
    std::cout << "ID: " << m_RFID_Chip.uiGetRFIDID() << std::endl;
    std::cout << "Fuellmenge: " << m_RFID_Chip.fGetFuellMenge() << std::endl;

}

// Konstruktor des RFID-Chips (Wichtig: Auf den namespace achten)
Becher::RFID_Chip::RFID_Chip()
{
    m_uid = 0;
    m_fFuellMenge = 0;
}

// Destruktor des RFID-Chips
Becher::RFID_Chip::~RFID_Chip()
{

}

// Setzt die ID im RFID-Chip
void Becher::RFID_Chip::setRFIDID(unsigned int id)
{
    m_uid = id;
}

// Setzt die F�llmenge im RFID-Chip
void Becher::RFID_Chip::setFuellMenge(float fFuellMenge)
{
    m_fFuellMenge = fFuellMenge;
}

// Gibt die eingeschriebene ID zur�ck
unsigned int Becher::RFID_Chip::uiGetRFIDID()
{
    return m_uid;
}

// Gibt die eingeschriebene F�llmenge zur�ck
float Becher::RFID_Chip::fGetFuellMenge()
{
    return m_fFuellMenge;
}
