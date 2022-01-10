#ifndef HYPOTHESE_H
#define HYPOTHESE_H
#include <vector>
#include <stdio.h>
#include <iostream>


class Carte;

class Hypothese
{
    public:
        Hypothese();
        ~Hypothese();
        void recevoirCarte(std::string c);
        std::vector <std::string> getNom_des_Cartes();
        void afficherTout();


    protected:

    private:
        std::vector<std::string> m_nom_des_Cartes;
};

#endif // HYPOTHESE_H
