#ifndef PIOCHE_H
#define PIOCHE_H
#include "Carte.h"
#include <algorithm>



class Joueur;
class Pioche
{
    public:
        Pioche();
        virtual ~Pioche();
        void init(std::vector<BITMAP*> mesessgdhf);
        void initPioche(int c, int d, int e);
        void distribution_Carte(std::vector<Joueur*> mesJoueurs);
        void afficher();

        ///getter
        std::vector<Carte*> getCartes();


    private:
        std::vector<Carte*> m_liste_all;
        std::stack<Carte*> m_pioche_all;

};

#endif // PIOCHE_H
