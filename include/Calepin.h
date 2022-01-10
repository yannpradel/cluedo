#ifndef CALEPIN_H
#define CALEPIN_H
#include <vector>
#include <allegro.h>


class Calepin
{
    public:
        Calepin();
        ~Calepin();
        void croixSurCalepin(int i); ///on va cocher en memoire
        void afficherTout(); ///on va afficher QUE LES CROIX


    private:
        std::vector<bool> m_appartenance;
};

#endif // CALEPIN_H
