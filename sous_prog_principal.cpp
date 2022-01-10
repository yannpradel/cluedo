#include <allegro.h>
#include <winalleg.h>
#include <iostream>
#include <PlateauJeu.h>
#include <UneCase.h>
#include <Joueur.h>
#include <fstream>
#include <string>


void gotoXY(float x, float y);
void fairePlateau(PlateauJeu& plato);
void faireContour();
void creationJoueur(std::vector<Joueur*> mesJoueurs,int nb);
int creerMenu();
void faireCompte(std::string &login,std::string &mdp,std::string &couleur,int nbj);
int creerNbrJoueur();
void verif_compte(std::string& login, std::string& mdp, char& res);
void choix_co(std::string& login, std::string& mdp, std::string& couleur,int i, char& veriff);


int creerMenu()
{
    BITMAP* image;


    while(!key[KEY_ESC])
    {

        show_mouse(screen);
        //std::cout << "x :" << mouse_x << " y :" << mouse_y << std::endl;

        if (640 < mouse_x && mouse_x < 1035 && 210 < mouse_y && mouse_y < 280)
        {
            image = load_bitmap("Bitmap2Bis.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 1;
        }
        else if (640 < mouse_x && mouse_x < 1035 && 322 < mouse_y && mouse_y < 387)
        {
            image = load_bitmap("Bitmap3Bis.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 2;
        }
        else if (640 < mouse_x && mouse_x < 1035 && 444 < mouse_y && mouse_y < 495)
        {
            image = load_bitmap("Bitmap4Bis.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 3;
        }
        else if (640 < mouse_x && mouse_x < 1035 && 537 < mouse_y && mouse_y < 607)
        {
            image = load_bitmap("Bitmap5Bis.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 4;
        }
        else
        {
            image = load_bitmap("Bitmap1Bis.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
        }
    }
    destroy_bitmap(image);


    /*while(!key[KEY_ESC])
    {
        blit(image,screen,0,0,0,0,image->w,image->h);
        show_mouse(screen);

        if(mouse_b & 1)
        {
            rest(20);
            std::cout << "x :" << mouse_x << " y :" << mouse_y << std::endl;
        }
    }*/

    return 0;
}



void initialiser_allegro(int x, int y)
{
    allegro_init();
    install_keyboard();

    install_mouse();


    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,x,y,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}


void faireContour() ///79
{
    for(int i=0;i<74;i++) ///75 en hauteur
    {
        gotoXY(i,0);
        std::cout << "-";
    }

    for(int i=1;i<26;i++) ///25 en hauteur
    {
        gotoXY(0,i);
        std::cout << "|";
    }

    for(int i=0;i<74;i++) ///75 en hauteur
    {
        gotoXY(i,26);
        std::cout << "-";
    }

    for(int i=1;i<26;i++) ///25 en hauteur
    {
        gotoXY(73,i);
        std::cout << "|";
    }

}

void gotoXY(float x, float y)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(H, C);
}



void fairePlateau(PlateauJeu& lePlateau)
{
    textprintf_ex(screen,font,180,650,makecol(255,255,0),makecol(0,0,0),"1");
    textprintf_ex(screen,font,600,500,makecol(255,255,0),makecol(0,0,0),"2");
    textprintf_ex(screen,font,10,420,makecol(255,255,0),makecol(0,0,0),"3");
    textprintf_ex(screen,font,600,150,makecol(255,255,0),makecol(0,0,0),"4");
    textprintf_ex(screen,font,250,20,makecol(255,255,0),makecol(0,0,0),"6");
    textprintf_ex(screen,font,400,20,makecol(255,255,0),makecol(0,0,0),"5");

    for (int i=0;i<9;i++)
        {
            UneCase temp(7,24-i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=15;i<24;i++)
        {
            UneCase temp(7,24-i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=1;i<17;i++)
        {
            UneCase temp(8,24-i);
            lePlateau.ajouterCase(temp);
        }

        UneCase test(8,24-23);
        lePlateau.ajouterCase(test);

        for (int i=1;i<17;i++)
        {
            UneCase temp(15,24-i);
            lePlateau.ajouterCase(temp);
        }

        UneCase test2(15,24-23);
        lePlateau.ajouterCase(test2);

        for (int i=0;i<24;i++)
        {
            UneCase temp(16,24-i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=1;i<9;i++)
        {
            UneCase temp(i,24-6);
            lePlateau.ajouterCase(temp);
        }

        for (int i=15;i<18;i++)
        {
            UneCase temp(i,24-6);
            lePlateau.ajouterCase(temp);
        }

        for (int i=17;i<23;i++)
        {
            UneCase temp(i,24-4);
            lePlateau.ajouterCase(temp);
        }

        for (int i=17;i<24;i++)
        {
            UneCase temp(i,24-5);
            lePlateau.ajouterCase(temp);
        }

        for (int i=8;i<18;i++)
        {
            UneCase temp(9,i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=0;i<15;i++)
        {
            UneCase temp(i,17);
            lePlateau.ajouterCase(temp);
        }

        for (int i=1;i<7;i++)
        {
            UneCase temp(i,16);
            lePlateau.ajouterCase(temp);
        }

        for (int i=2;i<15;i++)
        {
            UneCase temp(17,i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=0;i<2;i++)
        {
            UneCase temp(9,i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=0;i<2;i++)
        {
            UneCase temp(14,i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=5;i<6;i++)
        {
            UneCase temp(18,5);
            lePlateau.ajouterCase(temp);
        }

        for (int i=18;i<24;i++)
        {
            UneCase temp(i,6);
            lePlateau.ajouterCase(temp);
        }

        for (int i=18;i<23;i++)
        {
            UneCase temp(i,7);
            lePlateau.ajouterCase(temp);
        }

        for (int i=18;i<23;i++)
        {
            UneCase temp(i,13);
            lePlateau.ajouterCase(temp);
        }

        for (int i=2;i<10;i++)
        {
            UneCase temp(6,i);
            lePlateau.ajouterCase(temp);
        }

        for (int i=0;i<6;i++)
        {
            UneCase temp(i,7);
            lePlateau.ajouterCase(temp);
        }

        for (int i=1;i<9;i++)
        {
            UneCase temp(i,8);
            lePlateau.ajouterCase(temp);
        }

        UneCase temporaire(5,9);
        lePlateau.ajouterCase(temporaire);

        for (int i=10;i<15;i++)
        {
            UneCase temp(i,8);
            lePlateau.ajouterCase(temp);
        }

        for (int i=10;i<15;i++)
        {
            UneCase temp(i,9);
            lePlateau.ajouterCase(temp);
        }
}

void creationJoueur(std::vector<Joueur*> &mesJoueurs,int nb_joueurs)
{
    std::cout << nb_joueurs;
    for (int i=0;i<nb_joueurs;i++)
    {
        std::string login,mdp;
        std::cout << "Donner le nom du " << i << "�me joueur" << std::endl;
        std::cout << "Donner le mdp du " << i << "�me joueur" << std::endl;
        std::cin >> login >> mdp;
        Joueur j;
        //Compte compte1(log,mdp);

        mesJoueurs.push_back(&j);
    }
}

void faireCompte(std::string& login,std::string& mdp,std::string& couleur, int nbj) ///le code vient principalement du saboteur (projet 2020 avec Yahya Bouayad)
{
    int touche;
    int scancode;
    char carac;
    int fin=0;
    std::string temp = "                ";
    std::string temp2 = "                ";
    int y=0;
    int pos_y=0;
    int pseudoFin=0;
    int mdpFin=0;
    int x=5;

    BITMAP* compte1=load_bitmap("compte1.bmp",NULL);
    BITMAP* compte2=load_bitmap("compte2.bmp",NULL);
    BITMAP* compte3=load_bitmap("compte3.bmp",NULL);
    blit(compte1,screen,0,0,0,0,1600,900);

    while (1)
    {
        textprintf_ex(screen,font,580,30,makecol(255,255,0),makecol(150,105,150),"C'est au joueur %d de choisir son pseudo + mdp + couleur",nbj);

        if(mouse_x < 546 && mouse_x > 188 && mouse_y > 258 && mouse_y < 341 )
        {
            if (mouse_b && 1)
            {
                blit(compte2,screen,0,0,0,0,1600,900);
                while(fin==0)
                {
                    textprintf_ex(screen,font,580,30,makecol(255,255,0),makecol(150,105,150),"C'est au joueur %d de choisir son pseudo + mdp + couleur",nbj);
                    if(keypressed())
                    {
                        x=x+5;

                        touche=readkey();
                        carac=(char)touche;
                        //scancode=touche>>8;
                        scancode=touche;
                        std::cout << scancode;

                        if (carac=='\r')
                        {
                            temp[y+1]='\0';
                            fin=1;
                            x=x+5;

                        }
                        else if(scancode==KEY_BACKSPACE)
                        {
                            y--;
                            temp[y]=' ';
                            x=x+5;

                        }
                        else
                        {
                        temp[y]=carac;

                        y++;
                        x=x+5;
                        }

                    textprintf_ex(screen,font,180+x,300,makecol(0,0,0),makecol(255,0,0),"%c",carac);
                    }
                }

            login=temp;
            std::cout << "voici le pseudo " << temp << ".";
            pseudoFin=1;
            blit(compte1,screen,0,0,0,0,1600,900);
            textprintf_ex(screen,font,580,30,makecol(255,255,0),makecol(150,105,150),"C'est au joueur %d de choisir son pseudo + mdp + couleur",nbj);
            fin=0;
            y=0;

        }
        }

            if(mouse_x < 546 && mouse_x > 188 && mouse_y > 491 && mouse_y < 571 && pseudoFin==1)
        {
            x=5;

            if((mouse_b && 1))
            {
                blit(compte3,screen,0,0,0,0,1600,900);
            while(fin==0)
            {
                textprintf_ex(screen,font,580,30,makecol(255,255,0),makecol(150,105,150),"C'est au joueur %d de choisir son pseudo + mdp + couleur",nbj);
                 if(keypressed())
                {
                    x=x+5;
                    pos_y=pos_y+140;
                    touche=readkey();
                    carac=(char)touche;
                    //scancode=touche>>8;
                    scancode=touche;
                    std::cout << scancode;

                    if (carac=='\r')
                    {
                        temp2[y+1]='\0';
                        fin=1;
                        pos_y=pos_y+140;
                        x=x+5;
                    }
                    else if(scancode==KEY_BACKSPACE)
                    {
                        y--;
                        temp2[y]=' ';
                        x=x+5;
                    }
                    else
                    {
                        temp2[y]=carac;
                        pos_y=pos_y+140;
                         y++;
                         x=x+5;
                    }
                    textprintf_ex(screen,font,180+x,520,makecol(0,0,0),makecol(255,0,0),"%c",carac);
                }
            }

            mdp=temp2;
            std::cout << "voici le mdp " << mdp;
            mdpFin=1;
            blit(compte1,screen,0,0,0,0,1600,900);
            textprintf_ex(screen,font,580,30,makecol(255,255,0),makecol(150,105,150),"C'est au joueur %d de choisir son pseudo + mdp + couleur",nbj);
            fin=0;
            y=0;

            }
        }

        if(mdpFin==1 && pseudoFin==1)
        {

            if(mouse_x > 1060 && mouse_x < 1411 && mouse_y > 200 && mouse_y < 281 )
            {
                if(mouse_b && 1)
                {
                couleur="magenta";
                break;
                }
            }

            if(mouse_x > 1060 && mouse_x < 1411 && mouse_y > 310 && mouse_y < 391)
            {
                if(mouse_b && 1)
                {
                couleur="bleu";
                break;
                }
            }

            if(mouse_x > 1060 && mouse_x < 1411 && mouse_y > 420 && mouse_y < 501)
            {
                if(mouse_b && 1)
                {
                couleur="jaune";
                break;
                }
            }

            if(mouse_x > 1060 && mouse_x < 1411 && mouse_y > 530 && mouse_y < 611)
            {

                if(mouse_b && 1)
                {
                couleur="vert";
                break;
                }
            }

            if(mouse_x > 1060 && mouse_x < 1411 && mouse_y > 640 && mouse_y < 721)
            {

                if(mouse_b && 1)
                {
                couleur="orange";
                break;
                }
            }

            if(mouse_x > 1060 && mouse_x < 1411 && mouse_y > 750 && mouse_y < 831)
            {

                if(mouse_b && 1)
                {
                couleur="bleu";
                break;
                }
            }
        }
    }
}


int creerNbrJoueur()
{
    BITMAP* image;

    while(!key[KEY_ESC])
    {
        show_mouse(screen);
        //std::cout << "x :" << mouse_x << " y :" << mouse_y << std::endl;

        if (mouse_x > 634 && mouse_x < 1054 && mouse_y > 295 && mouse_y < 361)
        {
            image = load_bitmap("Image1.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 2;
        }
        else if (mouse_x > 634 && mouse_x < 1054 && mouse_y > 393 && mouse_y < 460)
        {
            image = load_bitmap("Image2.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 3;
        }
        else if (mouse_x > 634 && mouse_x < 1054 && mouse_y > 484 && mouse_y < 550)
        {
            image = load_bitmap("Image3.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 4;
        }
        else if (mouse_x > 634 && mouse_x < 1054 && mouse_y > 590 && mouse_y < 655)
        {
            image = load_bitmap("Image4.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 5;
        }

        else if (mouse_x > 634 && mouse_x < 1054 && mouse_y > 686 && mouse_y < 751)
        {
            image = load_bitmap("Image5.bmp",NULL);
            blit(image,screen,0,0,0,0,image->w,image->h);
            if(mouse_b & 1)
                return 6;
        }
        else
        {
         image = load_bitmap("Image0.bmp",NULL);
         blit(image,screen,0,0,0,0,image->w,image->h);
        }
    }
}

int load_nbrj()
{
    std::string nom = "save_J1.txt";
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture

    if(fichier)
    {
        int a;
        fichier >> a;
        return a;
    }
    else
    {
        return 0;
    }
}

void verif_compte(std::string& log, std::string& pass, char& res)
{
    std::string line1, line2, lvl;

    std::string nom = "data.txt";
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture

    if(fichier)
    {
        while(getline(fichier, line1))  //parcour chaque ligne du fichier
        {
            std::cout << "line1 : " << line1 << std::endl;
            if(line1 == log)    //si log correspond
            {
                getline(fichier, line2);
                std::cout << "line2 : " << line2 << std::endl;

                if(line2 == pass)   //si mdp correspond
                    res = '1';    //1 -> compte existe
            }
        }
    }
    else
    {
        std::cout << "ERREUR Impossible d'ouvrir le fichier en lecture" << std::endl;
    }
}

void creer_compte(std::string& login, std::string& mdp, std::string& couleur)
{
    std::string nom = "data.txt";
    std::ofstream fichier(nom.c_str(), std::ios::app);   //ofstream : ecriture

    if(fichier)
    {
        fichier << login << std::endl;
        fichier << mdp << std::endl;
    }
    else
    {
        std::cout << "ERREUR ECRITURE DANS FICHIER data.txt" << std::endl;
    }

    std::string nom2 = "datas/";
    nom2 += login;
    nom2 += ".txt";
    std::ofstream flux(nom2.c_str());

    if(flux)
    {
        flux << "Debutant" << std::endl;
        flux << 0 << std::endl;
        flux << 0 << std::endl;
    }
    else{std::cout << "PB D'ECRIRE DANS FICHIER";}
}

void choix_co(std::string& login, std::string& mdp, std::string& couleur,int i, char& veriff)
{
    char ch = '0';
    BITMAP* screen1;
    BITMAP* screen2;
    BITMAP* screen3;

    screen1 = load_bitmap("selec_compte.bmp",NULL);
    screen2 = load_bitmap("selec_compte_1.bmp",NULL);
    screen3 = load_bitmap("selec_compte_2.bmp",NULL);

    while(!key[KEY_ESC])
    {
        show_mouse(screen);

        if (317 < mouse_x && mouse_x < 1234 && 190 < mouse_y && mouse_y < 301)
        {
            blit(screen2, screen,0,0,0,0,screen2->w,screen2->h);
            if(mouse_b & 1)
            {
                ch = '1';
                break;
            }

        }
        else if (317 < mouse_x && mouse_x < 1234 && 511 < mouse_y && mouse_y < 620)
        {
            blit(screen3, screen,0,0,0,0,screen3->w,screen3->h);
            if(mouse_b & 1)
            {
                ch = '2';
                break;
            }

        }
        else
            blit(screen1,screen,0,0,0,0,screen1->w,screen1->h);
    }

    destroy_bitmap(screen1);
    destroy_bitmap(screen2);
    destroy_bitmap(screen3);

    if(ch == '1')
    {
        faireCompte(login, mdp, couleur, i);
        verif_compte(login, mdp, veriff);
    }
    else
    {
        faireCompte(login, mdp, couleur, i);
        creer_compte(login, mdp, couleur);
        veriff = '1';
    }
}

