#ifndef ACCUSATION_H
#define ACCUSATION_H
#include <Hypothese.h>



class Lieu;

class Accusation
{
    public:
        Accusation();
        ~Accusation();
        bool verifierAccusation();

    protected:

    private:
        Hypothese m_sonHypothese;
        Lieu* m_lieu;
};

#endif // ACCUSATION_H
