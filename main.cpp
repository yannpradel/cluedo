#include <iostream>
#include <fstream>
#include <time.h>
#include <Accusation.h>
#include <Carte.h>
#include <Jeu.h>
#include <Joueur.h>
#include <PlateauJeu.h>
#include <UneCase.h>
#include <allegro.h>
#include <winalleg.h>
#include <cstdlib>
#include <unistd.h>
#include <Pioche.h>
#include <Enveloppe.h>
#include <string>

///675 992 le plateau de jeu
void faireContour();
void fairePlateau(PlateauJeu& plato);
void initialiser_allegro(int x, int y);
void gotoXY(float x, float y);
void creationJoueur(std::vector<Joueur*> mesJoueurs, int a);
int creerMenu();
void faireCompte(std::string &login,std::string &mdp,std::string &couleur,int nbj);
int creerNbrJoueur();
void verif_compte(std::string& login, std::string& mdp, char& res);
void choix_co(std::string& login, std::string& mdp, std::string& couleur, int i, char& veriff);
void music_fond(SAMPLE* music);
void music_jeu(SAMPLE* music);


int main()
{
    int x=1;
    std::vector<BITMAP*> mesCartes;

    initialiser_allegro(1600,900);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    SAMPLE* music;

    music = load_sample("musicSP.wav"); ///on met une musique

    set_volume(80,30);
    play_sample(music,255,128,1000,1);

    menu:

    int code = creerMenu();

if(code == 1)
{
    do{
    rectfill(screen,0,0,1600,900,makecol(10,10,10));


    BITMAP *cartman=load_bitmap("cartman.bmp",NULL);
   // blit(cartman,screen,0,0,0,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(cartman);

    BITMAP *garisson=load_bitmap("garisson.bmp",NULL);
   // blit(garisson,screen,0,0,100,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(garisson);

    BITMAP *stan=load_bitmap("stan.bmp",NULL);
   // blit(stan,screen,0,0,200,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(stan);

    BITMAP *kyle=load_bitmap("kyle.bmp",NULL);
   // blit(kyle,screen,0,0,300,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(kyle);

    BITMAP *chef=load_bitmap("chef.bmp",NULL);
  //  blit(chef,screen,0,0,400,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(chef);

    BITMAP *mccay=load_bitmap("mccay.bmp",NULL);
   // blit(mccay,screen,0,0,500,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(mccay);

    /////////////////////////////////////////////////

    BITMAP *baton=load_bitmap("baton.bmp",NULL);
  //  blit(baton,screen,0,0,600,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(baton);

    BITMAP *shuriken=load_bitmap("shuriken.bmp",NULL);
  //  blit(shuriken,screen,0,0,700,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(shuriken);

    BITMAP *epee=load_bitmap("epee.bmp",NULL);
  //  blit(epee,screen,0,0,800,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(epee);

    BITMAP *hache=load_bitmap("hache.bmp",NULL);
  //  blit(hache,screen,0,0,900,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(hache);

    BITMAP *arc=load_bitmap("arc.bmp",NULL);
 //   blit(arc,screen,0,0,1000,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(arc);

    BITMAP *flechette=load_bitmap("flechette.bmp",NULL);
  //  blit(flechette,screen,0,0,1100,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(flechette);

    BITMAP *ecole=load_bitmap("ecole.bmp",NULL);
  //  blit(ecole,screen,0,0,1200,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(ecole);

    BITMAP *mKenny=load_bitmap("mKenny.bmp",NULL);
   // blit(mKenny,screen,0,0,1300,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(mKenny);

    BITMAP *eglise=load_bitmap("eglise.bmp",NULL);
   // blit(eglise,screen,0,0,1400,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(eglise);

    BITMAP *centre=load_bitmap("centre.bmp",NULL);
 //   blit(centre,screen,0,0,1500,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(centre);

    BITMAP *resto=load_bitmap("resto.bmp",NULL);
   // blit(resto,screen,0,0,0,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(resto);

    BITMAP *foret=load_bitmap("foret.bmp",NULL);
  //  blit(foret,screen,0,0,100,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(foret);

    BITMAP *lac=load_bitmap("lac.bmp",NULL);
  //  blit(lac,screen,0,0,200,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(lac);

    BITMAP *commi=load_bitmap("commi.bmp",NULL);
  //  blit(commi,screen,0,0,300,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(commi);

    BITMAP *canada=load_bitmap("canada.bmp",NULL);
  //  blit(canada,screen,0,0,400,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(canada);


    }while(x!=1);

    srand(time(NULL));

    Pioche a; ///on crée deux pioches une qu'on va distribuer aux joueur l'autre pour afficher sur le plateau
    Pioche b;

    a.init(mesCartes);
    b.init(mesCartes);

    int c = rand()%6;// indice carte suspect
    int d = rand()%(11-6+1)+6;//indice carte arme
    int e = rand()%(20-11+1)+11;//indice carte lieu

    Enveloppe v(a.getCartes()[c], a.getCartes()[d], a.getCartes()[e]); //creation de l'enveloppe
    std::cout << "Il s'agit de l'envellope : ";
    v.afficherEnv();

    a.initPioche(c, d, e);

    int nb_joueurs;

    std::string log,mdp;
    std::vector<Joueur*> mesJoueurs; ///creation du vecteur de joueur tout les joueurs vont etre stockés

    b.afficher();

    nb_joueurs = creerNbrJoueur();

///-------------------------------------------------------------------------

    for(int i=0; i<nb_joueurs; i++)
    {
        char veriff = '0';
        std::string login, mdp, couleur;
        do
        {
            choix_co(login, mdp, couleur, i+1, veriff);
        }
        while(veriff =='0');

        Joueur* j = new Joueur();
        Compte compte1(login,mdp,couleur);
        compte1.init_compte(login, mdp);
        mesJoueurs.push_back(j);
        j->associer_compte(compte1);
        std::cout << "login : " << login << " mdp : " << mdp << "couleur : " << couleur;
        std::cout << std::endl;
    }

    a.distribution_Carte(mesJoueurs); ///

    PlateauJeu lePlateau(mesJoueurs); ///on cr�e le plateau en donnant un vecteur de sur joueurs
    fairePlateau(lePlateau); ///on cr�e le plateau avec les gotoligcol "sous_prog_principal"
    lePlateau.afficherPlateau(); ///on affiche tout le plateau
    Jeu leJeu;
    leJeu.initialiser_joueur(nb_joueurs,mesJoueurs);



    for (int i=0; i<mesJoueurs.size(); i++) ///chaque joueur recuperer le plateau (peut etre inutile mais on garde) et on met sa place de d�part
    {
        mesJoueurs[i]->recupererPlateau(lePlateau);
        mesJoueurs[i]->recup_pioche(b);
        std::cout << "Le joueur " << i+1 << " a le plateau" << std::endl;
    }

        mesJoueurs[0]->setCase(7,24); ///1er joueur
        mesJoueurs[1]->setCase(23,19);

        if(nb_joueurs>2)
            mesJoueurs[2]->setCase(0,17);
        if(nb_joueurs>3)
            mesJoueurs[3]->setCase(23,6);
        if(nb_joueurs>4)
            mesJoueurs[4]->setCase(14,0);
        if(nb_joueurs>5)
            mesJoueurs[5]->setCase(9,0); ///6eme joueur

            lePlateau.afficher_joueur();
            sleep(1);
            system("CLS");
            faireContour();


    for (int i=0; i<mesJoueurs.size(); i++)
    {
        gotoXY(15*i+i,30+i);
        std::cout << "joueur : " << i+1 << std::endl;
        mesJoueurs[i]->afficherNumerosCase();
    }

    system("CLS");
    ///un tour de jeu :
    bool jeuTermine = false;
    stop_sample(music);
    music = load_sample("musicJeu.wav");
    set_volume(50,30);
    play_sample(music,255,128,1000,1);

BITMAP *bouton=load_bitmap("bouton_save.bmp",NULL);
//--------------------------------------------------------------------------
    int test = 0;
    De de_part;
    de_part.init_vec_de();
    while(!jeuTermine)
    {
        test++;
        for(int i=0; i<mesJoueurs.size(); i++)
        {
            gotoXY(0,0);
            mesJoueurs[i]->afficherDebut(i);
            rectfill(screen,575,0,1600,900,makecol(10,10,10));
            BITMAP *calepin=load_bitmap("calepin.bmp",NULL);
            blit(calepin,screen,0,0,1050,1,SCREEN_W,SCREEN_H);
            std::cout << "Le joueur " << i+1 << " va jouer" << std::endl;
            mesJoueurs[i]->estDansPiece();
            mesJoueurs[i]->getCalepin().afficherTout();
            ///le joueur s'est teleporté ou non

            mesJoueurs[i]->tirer_de();
            lePlateau.afficherPlateau();
            de_part.anim(mesJoueurs[i]->getDe().getChiffre());
            textprintf_ex(screen,font,180,3,makecol(255,255,0),makecol(0,0,0),"%s est en train de jouer",mesJoueurs[i]->getLogin().c_str());
            b.afficher();
            mesJoueurs[i]->faireLeTour(lePlateau);
            system("CLS");

            if(mesJoueurs[i]->getEstAccusationFaite() == true)
            {
                if(v.verifierAccusation(mesJoueurs[i]->getHypothese())== true)
                {
                    BITMAP *image=load_bitmap("Gagne.bmp",NULL);
                    blit(image,screen,0,0,0,0,image->w,image->h);
                    std::cout << "Bravo au joueur " << i+1 << ", vous avez elucide le crime " << std::endl;
                    jeuTermine = true;
                    allegro_exit();
                    break;
                }
                else
                {
                    mesJoueurs.erase(mesJoueurs.begin()+ i,mesJoueurs.begin()+i+1);
                    rectfill(screen,0,0,1600,900,makecol(10,10,10));
                    BITMAP *image=load_bitmap("Perdu.bmp",NULL);
                    blit(image,screen,0,0,0,0,image->w,image->h);
                    sleep(5);
                    rectfill(screen,575,0,1600,900,makecol(10,10,10));
                    std::cout << "Désolee joueur " << i+1 << ", vous avez perdu, vous etes elimines " << std::endl;
                }

            }

            else if(mesJoueurs[i]->getEstHypotheseFaite()==true)
            {
                int j = i;
                while(true)
                {
                    if(j==0)
                    {
                        j = mesJoueurs.size()-1;
                    }
                    else
                    {
                        j--;
                    }

                    if(j == i)
                    {
                        break;
                    }
                    system("CLS");
                    mesJoueurs[j]->afficherImageHypothese(j+1);
                    lePlateau.afficherPlateau();

                    std::cout << "Le joueur " << j+1 << " est en train d'analyser l'hypothese" <<std::endl;
                    std::cout << "Montrez la carte si vous la possédez au joueur " << i+1 << " Merci !" <<std::endl;

                    if(!(mesJoueurs[j]->montrerCarte(mesJoueurs[i]->getHypothese())))
                    {
                        break;
                    }
                    std::cout << "Le joueur " << j+1 << " n'a pas refute l'hypothese" << std::endl;
                }
                sleep(4);
            }

            system("CLS");

            lePlateau.afficherPlateau();
            textprintf_ex(screen,font,3,3,makecol(0,255,255),makecol(0,0,0),"Veuillez remplir le calepin et cliquer sur le rectangle rouge quand c'est termine");
            blit(calepin,screen,0,0,1050,1,SCREEN_W,SCREEN_H);
            mesJoueurs[i]->getCalepin().afficherTout();
            mesJoueurs[i]->afficherImagesCartes();
            mesJoueurs[i]->remplirCalpin();
            }

            for(int i = 0; i<nb_joueurs; i++)
            {
                mesJoueurs[i]->save(i, nb_joueurs);
            }
    }
}

else if(code == 2)
{
    do{
    rectfill(screen,0,0,1600,900,makecol(10,10,10));



    BITMAP *cartman=load_bitmap("cartman.bmp",NULL);
   // blit(cartman,screen,0,0,0,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(cartman);

    BITMAP *garisson=load_bitmap("garisson.bmp",NULL);
   // blit(garisson,screen,0,0,100,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(garisson);

    BITMAP *stan=load_bitmap("stan.bmp",NULL);
   // blit(stan,screen,0,0,200,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(stan);

    BITMAP *kyle=load_bitmap("kyle.bmp",NULL);
   // blit(kyle,screen,0,0,300,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(kyle);

    BITMAP *chef=load_bitmap("chef.bmp",NULL);
  //  blit(chef,screen,0,0,400,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(chef);

    BITMAP *mccay=load_bitmap("mccay.bmp",NULL);
   // blit(mccay,screen,0,0,500,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(mccay);
    /////////////////////////////////////////////////
    BITMAP *baton=load_bitmap("baton.bmp",NULL);
  //  blit(baton,screen,0,0,600,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(baton);

    BITMAP *shuriken=load_bitmap("shuriken.bmp",NULL);
  //  blit(shuriken,screen,0,0,700,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(shuriken);

    BITMAP *epee=load_bitmap("epee.bmp",NULL);
  //  blit(epee,screen,0,0,800,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(epee);

    BITMAP *hache=load_bitmap("hache.bmp",NULL);
  //  blit(hache,screen,0,0,900,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(hache);

    BITMAP *arc=load_bitmap("arc.bmp",NULL);
 //   blit(arc,screen,0,0,1000,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(arc);

    BITMAP *flechette=load_bitmap("flechette.bmp",NULL);
  //  blit(flechette,screen,0,0,1100,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(flechette);

    BITMAP *ecole=load_bitmap("ecole.bmp",NULL);
  //  blit(ecole,screen,0,0,1200,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(ecole);

    BITMAP *mKenny=load_bitmap("mKenny.bmp",NULL);
   // blit(mKenny,screen,0,0,1300,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(mKenny);

    BITMAP *eglise=load_bitmap("eglise.bmp",NULL);
   // blit(eglise,screen,0,0,1400,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(eglise);

    BITMAP *centre=load_bitmap("centre.bmp",NULL);
 //   blit(centre,screen,0,0,1500,600,SCREEN_W,SCREEN_H);
    mesCartes.push_back(centre);

    BITMAP *resto=load_bitmap("resto.bmp",NULL);
   // blit(resto,screen,0,0,0,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(resto);

    BITMAP *foret=load_bitmap("foret.bmp",NULL);
  //  blit(foret,screen,0,0,100,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(foret);

    BITMAP *lac=load_bitmap("lac.bmp",NULL);
  //  blit(lac,screen,0,0,200,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(lac);

    BITMAP *commi=load_bitmap("commi.bmp",NULL);
  //  blit(commi,screen,0,0,300,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(commi);

    BITMAP *canada=load_bitmap("canada.bmp",NULL);
  //  blit(canada,screen,0,0,400,400,SCREEN_W,SCREEN_H);
    mesCartes.push_back(canada);


    }while(x!=1);

    srand(time(NULL));

    Pioche b;

    b.init(mesCartes);

    Enveloppe v;
    v.charger_env(v);

    int nb_joueurs;

    std::string log,mdp,log2,mdp2,log3,mdp3;
    std::vector<Joueur*> mesJoueurs;

    b.afficher();

    nb_joueurs = load_nbrj();

    for(int i = 0; i<nb_joueurs; i++)
    {
        std::cout << "prouttt " << i << std::endl;
        Joueur* j = new Joueur();
        mesJoueurs.push_back(j);
    }

    for(int i = 0; i<nb_joueurs; i++)
    {
        std::cout << "prout " << i << std::endl;
        mesJoueurs[i]->load(i, nb_joueurs, mesCartes);
    }

    for(int i = 0; i<nb_joueurs; i++)
    {
        std::cout << "hmmmt" << std::endl;
        mesJoueurs[i]->afficherCartes();
        std::cout << std::endl;
    }

    PlateauJeu lePlateau(mesJoueurs); ///on cr�e le plateau en donnant un vecteur de sur joueurs
    fairePlateau(lePlateau); ///on cr�e le plateau avec les gotoligcol "sous_prog_principal"
    lePlateau.afficherPlateau(); ///on affiche tout le plateau
    Jeu leJeu;
    leJeu.initialiser_joueur(nb_joueurs,mesJoueurs);

    for (int i=0; i<mesJoueurs.size(); i++) ///chaque joueur recuperer le plateau (peut etre inutile mais on garde) et on met sa place de d�part
    {
        mesJoueurs[i]->recupererPlateau(lePlateau);
        mesJoueurs[i]->recup_pioche(b);
        std::cout << "Le joueur " << i+1 << " a le plateau" << std::endl;
    }

    lePlateau.afficher_joueur();
    sleep(1);
    system("CLS");
    faireContour();


    for (int i=0; i<mesJoueurs.size(); i++)
    {
        gotoXY(15*i+i,30+i);
        std::cout << "joueur : " << i+1 << std::endl;
        mesJoueurs[i]->afficherNumerosCase();
    }

    system("CLS");
    ///un tour de jeu :
    bool jeuTermine = false;

    De de_part;
    de_part.init_vec_de();
    while(!jeuTermine)
    {
        for(int i=0; i<mesJoueurs.size(); i++)
        {
            gotoXY(0,0);
            mesJoueurs[i]->afficherDebut(i);
            rectfill(screen,575,0,1600,900,makecol(10,10,10));
            BITMAP *calepin=load_bitmap("calepin.bmp",NULL);
            blit(calepin,screen,0,0,1050,1,SCREEN_W,SCREEN_H);
            std::cout << "Le joueur " << i+1 << " va jouer" << std::endl;
            mesJoueurs[i]->estDansPiece();
            mesJoueurs[i]->getCalepin().afficherTout();
            ///le joueur s'est teleporté ou non

            mesJoueurs[i]->tirer_de();
            lePlateau.afficherPlateau();
            de_part.anim(mesJoueurs[i]->getDe().getChiffre());
            textprintf_ex(screen,font,180,3,makecol(255,255,0),makecol(0,0,0),"%s est en train de jouer",mesJoueurs[i]->getLogin().c_str());
            b.afficher();
            mesJoueurs[i]->faireLeTour(lePlateau);
            system("CLS");

            if(mesJoueurs[i]->getEstAccusationFaite() == true)
            {
                if(v.verifierAccusation(mesJoueurs[i]->getHypothese())== true)
                {
                    BITMAP *image=load_bitmap("Gagne.bmp",NULL);
                    blit(image,screen,0,0,0,0,image->w,image->h);
                    std::cout << "Bravo au joueur " << i+1 << ", vous avez elucide le crime " << std::endl;
                    jeuTermine = true;
                    allegro_exit();
                    break;
                }
                else
                {
                    mesJoueurs.erase(mesJoueurs.begin()+ i,mesJoueurs.begin()+i+1);
                    rectfill(screen,0,0,1600,900,makecol(10,10,10));
                    BITMAP *image=load_bitmap("Perdu.bmp",NULL);
                    blit(image,screen,0,0,0,0,image->w,image->h);
                    sleep(5);
                    rectfill(screen,575,0,1600,900,makecol(10,10,10));
                    std::cout << "Désolee joueur " << i+1 << ", vous avez perdu, vous etes elimines " << std::endl;
                }

            }
            else if(mesJoueurs[i]->getEstHypotheseFaite()==true)
            {
                int j = i;
                while(true)
                {
                    if(j==0)
                    {
                        j = mesJoueurs.size()-1;
                    }
                    else
                    {
                        j--;
                    }

                    if(j == i)
                    {
                        break;
                    }
                    system("CLS");
                    mesJoueurs[j]->afficherImageHypothese(j+1);
                    lePlateau.afficherPlateau();

                    std::cout << "Le joueur " << j+1 << " est en train d'analyser l'hypothese" <<std::endl;
                    std::cout << "Montrez la carte si vous la possédez au joueur " << i+1 << " Merci !" <<std::endl;

                    if(!(mesJoueurs[j]->montrerCarte(mesJoueurs[i]->getHypothese())))
                    {
                        break;
                    }
                    std::cout << "Le joueur " << j+1 << " n'a pas refute l'hypothese" << std::endl;
                }
                sleep(4);
            }

            system("CLS");

            lePlateau.afficherPlateau();
            textprintf_ex(screen,font,3,3,makecol(0,255,255),makecol(0,0,0),"Veuillez remplir le calepin et cliquer sur le rectangle rouge quand c'est termine");
            blit(calepin,screen,0,0,1050,1,SCREEN_W,SCREEN_H);
            mesJoueurs[i]->getCalepin().afficherTout();
            mesJoueurs[i]->afficherImagesCartes();
            mesJoueurs[i]->remplirCalpin();
        }
    }
}

else if(code == 3)
{
    rectfill(screen,0,0,1600,900,makecol(10,10,10));
    BITMAP *Regle2=load_bitmap("RegleJeu1.bmp",NULL);
    blit(Regle2,screen,0,0,0,0,Regle2->w,Regle2->h);
    while(!key[KEY_ESC])
    {
        if(key[KEY_RIGHT])
        {
            BITMAP *Regle=load_bitmap("RegleJeu2.bmp",NULL);
            blit(Regle,screen,0,0,0,0,Regle->w,Regle->h);
        }
            else if (key[KEY_LEFT])
        {
            BITMAP *Regle2=load_bitmap("RegleJeu1.bmp",NULL);
            blit(Regle2,screen,0,0,0,0,Regle2->w,Regle2->h);
        }

        else if (key[KEY_ENTER])
        {
            goto menu;
        }
    }
}

if(code == 4)
{
 allegro_exit();
}

return 0;
}
END_OF_MAIN();
