#ifndef UNECASE_H
#define UNECASE_H

#include <iostream>


class UneCase
{
    public:
        UneCase();
        UneCase(int x,int y);
        ~UneCase();

        void afficherCase(int c,char x);
        int est_piece();
        bool est_salon();
        void localiserJoueur();

        ///getter
        int getPiece(){return m_piece;}
        int getX(){return m_x;}
        int getY(){return m_y;}
        std::string getNomPiece();

        ///setter
        void setX(int x){m_x=x;}
        void setY(int y){m_y=y;}
        void setPiece(int p){m_piece=p;}
        void setNomPiece(std::string n){m_nomPiece=n;}


    protected:

    private:
        int m_x=-1;
        int m_y=-1;
        int m_piece=0;
        std::string m_nomPiece;
        //Joueur* j_sur_case;
};

#endif // UNECASE_H
