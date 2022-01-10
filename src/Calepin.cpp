#include "Calepin.h"
#include <stdio.h>
#include <iostream>

Calepin::Calepin()
{
    for (int i=0;i<23;i++)
        m_appartenance.push_back(false);
}

Calepin::~Calepin()
{
    //dtor
}

void Calepin::croixSurCalepin(int i)
{
        std::cout << "on a cocher la case " << i << " sur le calepin" << std::endl;

        m_appartenance[i]=true;

        afficherTout();
}

void Calepin::afficherTout()
{
    int j;
    for (int i=1;i<23;i++)
    {

            if(m_appartenance[i]==false)
            {
            std::cout << "la case n'est pas cochee" << std::endl;
            if(i<7 || (i>7 && i <14))
                rectfill(screen,1165,65+(i*23),1183,85+(i*23),makecol(255,255,255));
            if(i>13 && i<24)
            {
                j=i-13;

                rectfill(screen,1415,65+(j*22),1433,85+(j*22),makecol(255,255,255));
            }


            }

            else
            {
            std::cout << "la case est cochee" << std::endl;
            if(i<7 || (i>7 && i <14))
            rectfill(screen,1165,65+(i*23),1183,85+(i*23),makecol(255,0,0));
            if(i>13 && i<24)
            {

                j=i-13;

                rectfill(screen,1415,65+(j*22),1433,85+(j*22),makecol(255,0,0));
            }
            }
    }
}
