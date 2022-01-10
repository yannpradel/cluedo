#ifndef JEU_H
#define JEU_H
#include <vector>




class Joueur;

class PlateauJeu;

class Jeu
{
    public:
        Jeu();
        ~Jeu();
        void initialiser_joueur(); // on donne des noms aux joueurs, faire les comptes ?
        void initialiser_joueur(int nbJoueur,std::vector<Joueur*> monVecteur); // on initialise le plateau avec toutes les cases et allegro

    protected:

    private:
        PlateauJeu* m_plateau;
        std::vector<Joueur*> m_joueurs;

};

#endif // JEU_H
