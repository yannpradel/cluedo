#include "PlateauJeu.h"
#include <UneCase.h>
#include <iostream>
#include <Joueur.h>
#include <fstream>

void gotoXY(float x, float y);

PlateauJeu::PlateauJeu()
{

}

PlateauJeu::PlateauJeu(std::vector<Joueur*> toutlesJ)
{
    m_joueurs=toutlesJ;
    //ctor
}

void PlateauJeu::afficher_joueur()
{
    for(int i=0;i<m_joueurs.size();i++)
    m_joueurs[i]->afficher_compte();
}

PlateauJeu::PlateauJeu(UneCase C)
{
    C.afficherCase(makecol(255,0,0),'-');
    m_cases.push_back(C);
}

PlateauJeu::~PlateauJeu()
{
    //dtor
}

void PlateauJeu::ajouterCase(UneCase C)
{
   // C.afficherCase();
    m_cases.push_back(C);
}

void PlateauJeu::afficherPlateau()
{
   // std::cout << "taille du vecteur" << m_cases.size();
   BITMAP *imageMap=load_bitmap("map.bmp",NULL);
   blit(imageMap,screen,0,0,0,0,SCREEN_W,SCREEN_H);
   for (int i=0;i<m_cases.size();i++)
    {
        if(m_cases[i].est_piece()==1)
            m_cases[i].afficherCase(makecol(155,0,0),'-');
    else
        m_cases[i].afficherCase(makecol(150,150,150),'-');
    }

    afficherJsurPlateau();
}

void PlateauJeu::afficherJsurPlateau()
{
    std::cout << "il y a " << m_joueurs.size() << " joueurs" << std::endl;
    for(int i=0;i<m_joueurs.size();i++)
    {
        if(m_joueurs[i]->getCase().getX()!=-1)
        m_joueurs[i]->afficherLeCase();
    }
}

std::vector<UneCase> PlateauJeu::getCases()
{
    return m_cases;
}

///save-loading
void PlateauJeu::save_plat()
{
    std::string nomF("save_plat.txt");   //fichier de sauvegarde de l'enveloppe
    std::ofstream flux(nomF.c_str());   //ofstream : ecriture

    if(flux)
    {
        for(int i = 0; i<m_cases.size(); i++)
        {
            flux << m_cases[i].getX() << std::endl;
            flux << m_cases[i].getY() << std::endl;
            flux << m_cases[i].getPiece() << std::endl;
            flux << m_cases[i].getNomPiece() << std::endl;
        }
    }
    else
    {
        std::cout << "ERREUR : Impossible d'ourvrir le fichier" << std::endl;
    }
}

void PlateauJeu::load_plat()
{
    std::ifstream fichier("save_plat.txt");//ifstream : lecture

    if(fichier)
    {
        for(int i = 0; i<m_cases.size(); i++)
        {
            int a, b, c;
            std::string line;

            fichier >> a;
            fichier >> b;
            fichier >> c;
            getline(fichier, line);

            m_cases[i].setX(a);
            m_cases[i].setY(b);
            m_cases[i].setPiece(c);
            m_cases[i].setNomPiece(line);
        }
    }
    else
    {

    }
}
