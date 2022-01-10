#include "Compte.h"
#include <Joueur.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <allegro.h>
#include <fstream>
#include <string>
#include <iostream>



Compte::Compte(std::string pseudo,std::string mdp,std::string couleur)
{
    m_login=pseudo;
    m_password=mdp;
    m_niveau="D�butant";

    if (couleur=="bleu")
    m_couleur=makecol(0,0,255);

    if (couleur=="vert")
    m_couleur=makecol(0,255,0);

    if (couleur=="magenta")
    m_couleur=makecol(255,0,255);

    if (couleur=="orange")
    m_couleur=makecol(255,165,0);

    if (couleur=="marron")
    m_couleur=makecol(90,60,17);

    if (couleur=="cyan")
    m_couleur=makecol(0,255,255);

    if (couleur=="jaune")
    m_couleur=makecol(255,255,0);
    //ctor
}

Compte::~Compte()
{
    //dtor
}


void Compte::afficher()
{
    std::cout << m_login << " : " << m_password <<" : "  << m_couleur << std::endl;
}

void Compte::init_compte(std::string& log, std::string& pass)
{
    std::string line1, line2;

    std::string nom = "data.txt";
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture

    if(fichier)
    {
        while(getline(fichier, line1))  //parcour chaque ligne du fichier
        {
            std::cout << "line1 : " << line1 << std::endl;
            if(line1 == log)    //si log correspond
            {
                getline(fichier, line2);
                std::cout << "line2 : " << line2 << std::endl;

                if(line2 == pass)   //si mdp correspond
                {
                    std::string nm = "datas/";
                    nm+= getLog();
                    nm += ".txt";
                    std::ifstream flux(nm.c_str());   //ofstream : ecriture

                    if(flux)
                    {
                        std::string lvl;
                        int cmptP, cmptPG;

                        getline(fichier, lvl);
                        fichier  >> cmptP;
                        fichier  >> cmptPG;

                        setNiveau(lvl);
                        setCompteur(cmptP);
                        setCompteurGagnee(cmptPG);
                    }
                    else{"ERREUR OUVERTURE FICHIER ";}
                }
            }
        }
    }
    else
    {
        std::cout << "ERREUR Impossible d'ouvrir le fichier en lecture" << std::endl;
    }
}

void Compte::save()
{
    std::string nom = "data/";
    nom += getLog();
    nom  += ".txt";
    std::cout << nom;
    int a;
    std::cin >> a;

    std::ofstream fichier(nom.c_str());   //ofstream : ecriture

    if(fichier)
    {
        fichier << getNiveau();
        fichier << getCompteur();
        fichier << getComptGagnee();
    }
    else
    {
        std::cout << "ERREUR : " << nom << std::endl;
    }
}

void Compte::load(std::string log)
{
    std::string nom = "data/";
    nom += log;
    nom  += ".txt";
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture

    if(fichier)
    {
        std::string lvl;
        int cmpt, cmptg;

        fichier >> lvl;
        fichier >> cmpt;
        fichier >> cmptg;
    }
    else
    {
        std::cout << "ERREUR Impossible d'ouvrir le fichier en lecture" << std::endl;
    }
}

