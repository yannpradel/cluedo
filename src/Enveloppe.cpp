#include "Enveloppe.h"
#include <fstream>
#include "time.h"

Enveloppe::Enveloppe()
{
    m_lieu = NULL;
    m_arme = NULL;
    m_suspect = NULL;
}

Enveloppe::Enveloppe(Carte* _sus, Carte* _arme, Carte* _lieu):m_suspect(_sus), m_arme(_arme), m_lieu(_lieu)
{

}

Enveloppe::~Enveloppe()
{
    delete m_lieu;
    m_lieu = NULL;
    delete m_arme;
    m_arme = NULL;
    delete m_suspect;
    m_suspect = NULL;
}

///getter
Carte* Enveloppe::getSus()
{
    return m_suspect;
}
Carte* Enveloppe::getArme()
{
    return m_arme;
}
Carte* Enveloppe::getLieu()
{
    return m_lieu;
}

void Enveloppe::afficherEnv()
{
    std::cout << "Enveloppe : " << getLieu()->getNom()<< " , " << getSus()->getNom() << " , " <<getArme()->getNom();
}

bool Enveloppe::verifierAccusation(Hypothese hyp) const
{
    if(m_lieu->getNom() == hyp.getNom_des_Cartes()[0] && m_suspect->getNom() == hyp.getNom_des_Cartes()[1] && m_arme->getNom() == hyp.getNom_des_Cartes()[2])
    {
        return true;
    }
    return false;
}

///sauvegarde l'enveloppe
void Enveloppe::sauvegarder()
{
    std::string nomF("save_env.txt");   //fichier de sauvegarde de l'enveloppe
    std::ofstream flux(nomF.c_str());   //ofstream : ecriture

    if(flux)
    {
        flux << getSus()->getNom() << std::endl;   //ecrit le nom du suspect en 1ere ligne
        flux << getLieu()->getNom() << std::endl;   //ecrit le nom du lieu en 2eme ligne
        flux << getArme()->getNom() << std::endl;   //ecrit le nom de l'arme en 3eme ligne
    }
    else
    {
        std::cout << "ERREUR : Impossible d'ourvrir le fichier" << std::endl;
    }
}

///charger enveloppe
void Enveloppe::charger_env(Enveloppe& v)
{
    std::ifstream fichier("save_env.txt");//ifstream : lecture

    if(fichier)
    {
        std::string suspect;
        std::string lieu;
        std::string arme;

        //recupere les infos dans le fichier
        getline(fichier, suspect);
        getline(fichier, lieu);
        getline(fichier, arme);

        ///cree des pointeurs de carte a partir des infos du fichier
        Carte* a = new Carte(suspect, 'P');
        Carte* b = new Carte(lieu, 'L');
        Carte* c = new Carte(arme, 'A');

        Enveloppe vv(a, c, b);
        v = vv;
        //initialise une nouvelle pioche avec les pointeurs de cartes en ref
        //Enveloppe v(a, b, c);
        //return v;
    }
    else
    {
        std::cout << "ERREUR : Impossible d'ourvrir le fichier" << std::endl;
        Enveloppe (NULL, NULL, NULL);
    }
}

