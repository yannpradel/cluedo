#include <../header.h>


Carte::Carte()
{
    //ctor
}

Carte::Carte(std::string nom, char type, BITMAP* image): m_nom(nom), m_typeC(type), m_bitmap(image)
{
    //ctor
}

Carte::Carte(std::string nom, char type): m_nom(nom), m_typeC(type)
{
    //ctor
}


Carte::~Carte()
{
    //dtor
}

///getter
std::string Carte::getNom()
{
    return m_nom;
}

char Carte::getType()
{
    return m_typeC;
}

///setter
void Carte::setNom(std::string saisie)
{
    m_nom = saisie;
}

void Carte::setType(char type)
{
    m_typeC = type;
}

void Carte::setBtm(BITMAP* im)
{
    m_bitmap = im;
}

void Carte::afficherBitmap(int x, int y, int x1, int y1)
{
    blit(m_bitmap,screen,x,y,x1,y1,SCREEN_W,SCREEN_H);
}
