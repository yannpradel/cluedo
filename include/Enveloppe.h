#ifndef ENVELOPPE_H
#define ENVELOPPE_H
#include "Pioche.h"
#include <Hypothese.h>

class Lieu;
class Arme;
class Suspect;

class Enveloppe
{
    public:
        Enveloppe();
        Enveloppe(Carte* _sus, Carte* _arme, Carte* _lieu);
        ~Enveloppe();

        ///getter
        Carte* getSus();
        Carte* getArme();
        Carte* getLieu();

        void afficherEnv();
        void initEnv(Pioche& pioch);
        bool verifierAccusation(Hypothese hyp) const;

        void sauvegarder();
        void charger_env(Enveloppe& v);

    private:
        Carte* m_lieu;
        Carte* m_arme;
        Carte* m_suspect;
};

#endif // ENVELOPPE_H
