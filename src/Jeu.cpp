#include <../header.h>

Jeu::Jeu()
{
    //ctor
}

Jeu::~Jeu()
{
    //dtor
}

void Jeu::initialiser_joueur(int nbJoueur,std::vector<Joueur*> monVecteur)
{
        m_joueurs = monVecteur;
}
