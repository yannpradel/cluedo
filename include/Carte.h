#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <allegro.h>
#include <stack>
#include <vector>


class Carte
{
    public:
        Carte();
        Carte(std::string nom, char type);
        Carte(std::string nom, char type, BITMAP* image);
        ~Carte();

        ///setter
        void setNom(std::string saisie);
        void setType(char type);
        void setBtm(BITMAP* image);

        ///getter
        std::string getNom();
        char getType();
        BITMAP* getBitmap(){return m_bitmap;}

        void afficherBitmap(int x, int y, int x1, int y1);


    private:
        BITMAP* m_bitmap;
        std::string m_nom;
        char m_typeC;


   protected:

};

#endif // CARTE_H
