#ifndef BECHER_H
#define BECHER_H

// Diese Klasse soll einen Becher mit integrierten RFID-Chip darstellen
class Becher
{
    public:
        // Konstruktor
        Becher();
        // Destruktor
        ~Becher();

        // Methoden um die aktuelle F�llmenge zu setzen und zur�ckzugeben
        void setFuellMenge(float fFuellmenge);
        float fGetFuellMenge();

        // Methoden um die maximale F�llmenge zu setzen und zur�ckzugeben
        void setMaxFuellMenge(float fMaxFuellmenge);
        float fGetMaxFuellMenge();

        //  Methode um den RFID-Chip zu beschreiben
        void setRFID(unsigned int& id);

    protected:

    private:
        // Erstellung der Klasse RFID_Chip innerhalb der Klasse Becher, da es sich um eine Komposition handelt
        // Ein RFID-Chip kann ohne einen Becher nicht existieren
        // Der RFID-Chip wird verwendet um am Ende eine ID und die F�llmenge zu speichern
        class RFID_Chip
        {
            public:
                // Konstruktor
                RFID_Chip();
                // Destruktor
                ~RFID_Chip();

                // Methoden zum Setzen und Lesen der ID
                void setRFIDID(unsigned int id);
                unsigned int uiGetRFIDID();

                // Methoden zum Setzen und Lesen der F�llmenge am Ende
                void setFuellMenge(float fFuellmenge);
                float fGetFuellMenge();

            private:

                // Beinhaltet die ID als positiver Integer - IDs sind selten negativ deswegen unsigned integer
                unsigned int m_uid;

                // Beinhaltet die F�llmenge, welche am Ende hineingeschrieben wird
                float m_fFuellMenge;

        }m_RFID_Chip;   // }<Name eines Attributs>; --> Dieser Syntax deklariert ein Attribut der hier erstellten Klasse
                        // Hier wird also das Attribut m_RFID_Chip der Klasse RFID_Chip deklariert

        // Enh�lt die aktuelle F�llmenge des Bechers als float (Kommazahl)
        float m_fFuellMenge;
        // Enh�lt die maximale F�llmenge des Bechers (wird am Anfang festgelegt)
        float m_fMaxFuellMenge;
};

#endif // BECHER_H
