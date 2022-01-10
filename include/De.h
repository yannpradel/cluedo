#ifndef DE_H
#define DE_H
#include <allegro.h>
#include <vector>


class De
{
    public:
        De();
        ~De();
        void deAleatoire();
        int getChiffre(){return m_chiffre;}
        void setChiffre(int x){m_chiffre=x;}

        void init_vec_de();
        void anim(int res);


    protected:

    private:
        int m_chiffre;
        std::vector<BITMAP*>m_faces_de;
};

#endif // DE_H
