#include "Pioche.h"
#include <stack>
#include <vector>
#include <Joueur.h>

Pioche::Pioche()
{
    //ctor
}

Pioche::~Pioche()
{
    //dtor
}

///getter
std::vector<Carte*> Pioche::getCartes()
{
    return m_liste_all;
}

void Pioche::afficher()
{
    for(int i=0;i<m_liste_all.size();i++)
    {
        std::string temp = m_liste_all[i]->getNom();
        char temp2 = m_liste_all[i]->getType();
        textprintf_ex(screen,font,700,3+17*i,makecol(80,255,136),makecol(0,0,0),"Carte : %d :  %s  | %c",i,temp.c_str(),temp2);
    }
}

void Pioche::init(std::vector<BITMAP*> images)
{
///initialisation des cartes suspect
    // 6 suspects
    Carte* a = new Carte("Mr. Mackey", 'P',images[5]);
    m_liste_all.push_back(a);

    Carte* b = new Carte("Cartman", 'P',images[0]);
  //  b->afficherBitmap(0,0,1100,800);
    m_liste_all.push_back(b);

    Carte* c = new Carte("Kyle", 'P',images[3]);
    m_liste_all.push_back(c);

    Carte* d = new Carte("Stan", 'P',images[2]);
    m_liste_all.push_back(d);

    Carte* e = new Carte("Mr. Garison", 'P',images[1]);
    m_liste_all.push_back(e);

    Carte* f = new Carte("Chef", 'P',images[4]);
    m_liste_all.push_back(f);

///
    // 6 armes
    Carte* aa = new Carte("Le baton de la verite", 'A',images[6]);
    m_liste_all.push_back(aa);

    Carte* bb = new Carte("Shuriken", 'A',images[7]);
    m_liste_all.push_back(bb);

    Carte* cc = new Carte("Epee en bois", 'A',images[8]);
    m_liste_all.push_back(cc);

    Carte* dd = new Carte("Hache", 'A',images[9]);
    m_liste_all.push_back(dd);

    Carte* ee = new Carte("Arc", 'A',images[10]);
    m_liste_all.push_back(ee);

    Carte* ff = new Carte("Flechette", 'A',images[11]);
    m_liste_all.push_back(ff);

///
    //9 lieu
    Carte* aaa = new Carte("L'ecole", 'L',images[12]);
    m_liste_all.push_back(aaa);

    Carte* bbb = new Carte("Maison de Kenny", 'L',images[13]);
    m_liste_all.push_back(bbb);

    Carte* ccc = new Carte("L'eglise", 'L',images[14]);
    m_liste_all.push_back(ccc);

    Carte* ddd = new Carte("Le centre commercial", 'L',images[15]);
    m_liste_all.push_back(ddd);

    Carte* eee = new Carte("Le restaurant chinois", 'L',images[16]);
    m_liste_all.push_back(eee);

    Carte* fff = new Carte("La foret", 'L',images[17]);
    m_liste_all.push_back(fff);

    Carte* ggg = new Carte("Le lac", 'L',images[18]);
    m_liste_all.push_back(ggg);

    Carte* hhh = new Carte("Le comissariat", 'L',images[19]);
    m_liste_all.push_back(hhh);

    Carte* iii = new Carte("Le Canada", 'L',images[20]);
    m_liste_all.push_back(iii);
/*
    for(int i = 0; i<21; i++)//pour verifier
        std::cout << Liste_all[i]->getNom() << std::endl;//pour verifier
        */
}

void Pioche::initPioche(int c, int d, int e)
{

    m_liste_all.erase(m_liste_all.begin()+c);   //supprime le suspecte de la pioche
    m_liste_all.erase(m_liste_all.begin()+d-1); //supprime l'arme de la pioche
    m_liste_all.erase(m_liste_all.begin()+e-2); //supprime le lieu de la pioche

    std::vector<Carte*> l_tempo;
    l_tempo = m_liste_all;

    std::cout << "AVANT LE SHUFFLE" << std::endl;

    for(int i = 0; i<l_tempo.size(); i++)//pour verifier
        std::cout << l_tempo[i]->getNom() << "   " << l_tempo[i]->getType() << std::endl;//pour verifier



    std::random_shuffle(l_tempo.begin(), l_tempo.end());//melange le vecteur

    std::cout << "Apres LE SHUFFLE" << std::endl;
    for(int i = 0; i<l_tempo.size(); i++)//pour verifier
        std::cout << l_tempo[i]->getNom() << "   " << l_tempo[i]->getType() << std::endl;//pour verifier



    for(int i=0; i<l_tempo.size(); i++)
        m_pioche_all.push(l_tempo[i]);
        std::cout << "EMPILE" << std::endl;
}

void Pioche::distribution_Carte(std::vector<Joueur*> mesJoueurs)
{
do{
    for (int i=0;i<mesJoueurs.size();i++)
    {
        if(m_pioche_all.size()!=0)
        {
        Carte* temp = m_pioche_all.top();//new Carte();
        //temp=m_pioche_all.top();
        std::cout << temp->getNom() << std::endl<< std::endl;
        mesJoueurs[i]->setCarte(temp);
        m_pioche_all.pop();
        std::cout << "la pioche se depile, taille : " << m_pioche_all.size() << std::endl;
        }
        else
        {
            std::cout << "Lapioche est vide"<< std::endl;
            break;
        }
    }
}while(m_pioche_all.size()!=0);
}
