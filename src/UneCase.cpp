#include "UneCase.h"
#include <iostream>
#include <allegro.h>

void gotoXY(float x, float y);

UneCase::UneCase(int x,int y)
{
    m_x=x;
    m_y=y;
}

UneCase::UneCase()
{
    //dtor
}

UneCase::~UneCase()
{
    //dtor
}

bool UneCase::est_salon()
{
    if((m_x==14 && m_y==8) ||(m_x==9 && m_y==8) ||(m_x==7 && m_y==5) || (m_x==16 && m_y==5))
    {
        return true;
    }
    return false;

}
int UneCase::est_piece()
{
    if((m_x==18 && m_y==5 )||(m_x==20 && m_y==13 )||(m_x==8 && m_y==12 )||(m_x==6 && m_y==18 )|| (m_x==6 && m_y==16 )|| (m_x==11 && m_y==17) || (m_x==12 && m_y==17) || (m_x==15 && m_y==20 )||( m_x==17 && m_y==20) || (m_x==16 && m_y==16) || (m_x==17 && m_y==9) || (m_x==14 && m_y==8) ||(m_x==9 && m_y==8) ||(m_x==4 && m_y==7) ||(m_x==7 && m_y==5) || (m_x==16 && m_y==5) || (m_x==22 && m_y==13) || m_x==21 && m_y==18)
    {
        m_piece=1;
        afficherCase(makecol(255,0,0),'j');
    }
    return m_piece;
}

std::string UneCase::getNomPiece()
{
    return m_nomPiece;
}

void UneCase::afficherCase(int x,char c)
{
    rectfill(screen,29+m_x*26,35+2+m_y*32,29+m_x*26+20,20+2+m_y*32+35,x);
}

void UneCase::localiserJoueur()
{
    if(m_x==17 && m_y==20)
    {
        m_nomPiece = "Le restaurant chinois";
    }
    if(m_x==15 && m_y==20 ||  m_x==11 && m_y==17 || m_x==12 && m_y==17)
    {
        m_nomPiece = "L'eglise";
    }
    if(m_x==6 && m_y==18)
    {
        m_nomPiece = "Le comissariat";
    }
    if(m_x==6 && m_y==16 || m_x==8 && m_y== 12)
    {
        m_nomPiece = "L'ecole";
    }
    if(m_x==7 && m_y==6 || m_x== 9 && m_y== 8 ||m_x== 14 && m_y== 8||m_x== 16 && m_y== 5)
    {
        m_nomPiece = "Centre commercial";
    }
     if(m_x==18 && m_y==5)
    {
        m_nomPiece = "La foret";

    }
     if(m_x==16 && m_y==16)
    {
        m_nomPiece = "Le lac";

    }
     if(m_x==17 && m_y==9|| m_x== 20 && m_y== 13 ||m_x== 22 && m_y== 13)
    {
        m_nomPiece = "Maison de Kenny";

    }
    if(m_x==4 && m_y==7)
    {
        m_nomPiece = "Le Canada";

    }

}
