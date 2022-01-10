#include <../header.h>

Hypothese::Hypothese()
{
    //ctor
}


Hypothese::~Hypothese()
{
    //dtor
}

void Hypothese::recevoirCarte(std::string a)
{

    m_nom_des_Cartes.push_back(a);
}

void Hypothese::afficherTout()
{
    for (int i=0;i<m_nom_des_Cartes.size();i++)
    {
        std::cout << "Carte : " << i+1 << " : " << m_nom_des_Cartes[i] << " ";
    }


}

std::vector <std::string> Hypothese::getNom_des_Cartes()
{
    return m_nom_des_Cartes;
}
