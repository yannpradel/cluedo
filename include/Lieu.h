#ifndef LIEU_H
#define LIEU_H
#include <Carte.h>

class Lieu : public Carte
{
    public:
        Lieu();
        virtual ~Lieu();

    protected:

    private:
        bool m_lieuActuel;
};

#endif // LIEU_H
