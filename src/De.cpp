#include "De.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>


De::De()
{
    //ctor
    init_vec_de();
}

De::~De()
{
    //dtor
}

void De::anim(int res)
{
    for(int i = 0; i<12; i++)
    {
        masked_blit(m_faces_de[i%6], screen, 0, 0, 0, 0, m_faces_de[i%6]->w, m_faces_de[i%6]->h);
        usleep(100000);
    }

    masked_blit(m_faces_de[res-1], screen, 0, 0, 0, 0, m_faces_de[res-1]->w, m_faces_de[res-1]->h);
}

void De::deAleatoire()
{
    m_chiffre=rand()%6+1;
    std::cout << m_chiffre << std::endl;
}

void De::init_vec_de()
{
    BITMAP *de1=load_bitmap("de/de1.bmp",NULL);
    m_faces_de.push_back(de1);

    BITMAP *de2=load_bitmap("de/de2.bmp",NULL);
    m_faces_de.push_back(de2);

    BITMAP *de3=load_bitmap("de/de3.bmp",NULL);
    m_faces_de.push_back(de3);

    BITMAP *de4=load_bitmap("de/de4.bmp",NULL);
    m_faces_de.push_back(de4);

    BITMAP *de5=load_bitmap("de/de5.bmp",NULL);
    m_faces_de.push_back(de5);

    BITMAP *de6=load_bitmap("de/de6.bmp",NULL);
    m_faces_de.push_back(de6);
}
