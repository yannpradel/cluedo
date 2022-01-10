#include <Joueur.h>
#include <Compte.h>
#include <allegro.h>
#include <cstdlib>
#include <unistd.h>
#include <Calepin.h>
#include <fstream>
#include <winalleg.h>
#include <string>

void gotoXY(float x, float y);

Joueur::Joueur()
{
    m_estHypotheseFaite = false;
    m_nb_tours_joues = 0;
}


Joueur::~Joueur()
{
    //dtor
}

void Joueur::initialiser_tout_avant_deplacement(Compte cmpte)
{
    associer_compte(cmpte);
    afficher_compte();
}

void Joueur::associer_compte(Compte unCompte)
{
    m_compte = unCompte;
}

void Joueur::afficher_compte()
{
    std::cout << "On affiche le compte du joueur : " ;
    m_compte.afficher();
}

void Joueur::setCarte(Carte* uneCarte)
{
    m_carte=uneCarte;
    std::cout << "TEST: " <<  uneCarte->getNom() <<  std::endl;
    m_cartes.push_back(m_carte);
}

std::string Joueur::getLogin()
{
    return m_compte.getLog();
}

void Joueur::tirer_de()
{
    // std::cout << "Le joueur " << m_compte.getLog() << " a tire : ";
    m_de.deAleatoire();
    textprintf_ex(screen,font,250,3,makecol(255,255,0),makecol(0,0,0),"Il a tire : %d",m_de.getChiffre());
    m_nb_tours_joues++;
}

void Joueur::setCase(int x, int y)
{
    //system("CLS");
    int a=0;
    int touche;
    int scancode;
    char choix;
    char carac;
    gotoXY(0,25);
    int trouve;
    m_ancienneCase=m_case;

    for(int i=0; i<m_plateau.getCases().size(); i++)
    {
        if(m_plateau.getCases()[i].getX()==x && m_plateau.getCases()[i].getY()==y)
        {
            // else
            //   std::cout << "la case n'est pas une piece";
            //   std::cout << "x de la case" <<m_plateau.getCases()[i].getX() << "   ";
            //  std::cout << "y de la case" <<m_plateau.getCases()[i].getY() << "   " << std::endl;
            m_case.setX(x);
            m_case.setY(y);
            if (m_plateau.getCases()[i].est_salon()==true)
            {
                std::cout << "Voulez-vous faire une accusation. Répondez par O(oui) ou N(non) :" << std::endl;
                char choix;
                do
                {
                textprintf_ex(screen,font,700,650,makecol(255,255,0),makecol(0,0,0),"Voulez-vous faire une accusation. Répondez par O(oui) ou N(non) :");
                rect(screen,0+700,720,100+700,850,makecol(0,255,0));
                rect(screen,100+700,720,200+700,850,makecol(255,0,0));
                while(1)
                {

                   // std::cout << "on est dans al oyfkg";

                    if((mouse_x>=0+700 && mouse_x<=100+700) && (mouse_y>=720 && mouse_y<=850))
                    {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur oui";
                            choix='O';
                            break;
                        }

                    }

                    if((mouse_x>=100+700 && mouse_x<=200+700) && (mouse_y>=720 && mouse_y<=850))
                        {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur non";
                            choix='N';
                            break;
                        }

                    }
                }

                    if(choix=='O')
                    {
                        creerAccusation();
                        rect(screen,100,700,300,800,makecol(120,150,255));
                        m_estAccusationFaite = true;
                        m_de.setChiffre(0);
                    }
                    if(choix=='N')
                    {
                        m_de.setChiffre(0);
                    }
                }
                while(choix != 'O' && choix != 'N');
            }
            if(m_estAccusationFaite == false && m_plateau.getCases()[i].est_piece()==1)
            {
                std::cout << "Voulez-vous faire une hypothese. Répondez par O(oui) ou N(non) :" << std::endl;
                textprintf_ex(screen,font,700,650,makecol(255,255,0),makecol(0,0,0),"Voulez-vous faire une hypothese. Répondez par O(oui) ou N(non) :");
                rect(screen,0+700,720,100+700,850,makecol(0,255,0));
                rect(screen,100+700,720,200+700,850,makecol(255,0,0));
                while(1)
                {

                   // std::cout << "on est dans al oyfkg";

                    if((mouse_x>=0+700 && mouse_x<=100+700) && (mouse_y>=720 && mouse_y<=850))
                    {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur oui";
                            choix='O';
                            break;
                        }

                    }

                    if((mouse_x>=100+700 && mouse_x<=200+700) && (mouse_y>=720 && mouse_y<=850))
                        {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur non";
                            choix='N';
                            break;
                        }

                    }

                }
                if(choix=='O')
                {
                    rectfill(screen,0+700,650,800+700,900,makecol(0,0,0));
                    creerHypothese();
                    m_estHypotheseFaite = true;
                    m_de.setChiffre(0);
                }
                if(choix=='N')
                {
                    rectfill(screen,0+700,650,800+700,900,makecol(0,0,0));
                    m_de.setChiffre(0);
                }

            }
        }
    }
}

bool Joueur::getEstHypotheseFaite() const
{
    return m_estHypotheseFaite;
}

Hypothese Joueur::getHypothese() const
{
    return m_hypothese;
}

void Joueur::afficherLeCase()
{
    gotoXY((m_case.getX()*3)+1,m_case.getY()+1);
    m_case.afficherCase(m_compte.getCouleur(),'j');
}

void Joueur::afficherNumerosCase()
{
    std::cout << "X : " << m_case.getX() << " Y : " << m_case.getY();
}

void Joueur::recupererPlateau(PlateauJeu plateau)
{
    m_plateau=plateau;
}
///
 void Joueur::afficherCase()
{
    std::cout << "on affiche les cases du joueur ";
    m_compte.afficher();
    for (int i=0; i<m_plateau.getCases().size(); i++)
        m_plateau.getCases()[i].afficherCase(m_compte.getCouleur(),'j');
}

void Joueur::recup_pioche(Pioche P)
{
    m_p=P;
}

void Joueur::creerHypothese()
{

    int i;
    int lieu,sus,arme;
    int test=0;
    int test2=0;
    std::vector<Carte*> temp;
    temp = m_p.getCartes();
    Carte* carteTest;
    Carte carteTestLieu;
    std::string l,s,a;
    m_case.localiserJoueur();

    std::cout << "Le lieu est : " << std::endl;
    std::cout << "La Carte : " << m_case.getNomPiece() << std::endl;
    l=m_case.getNomPiece();
    textprintf_ex(screen,font,1300,630,makecol(255,255,120),makecol(0,0,0),"%s",l.c_str());



    ///blinder
    m_hypothese.recevoirCarte(l);

    textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Donnez un suspect en cliquant en haut a droite sur les noms verts");
    while(test==0)  ///700 et 17 en y a chaque nouveau
                {
                    i=mouse_y/17;
                    if((mouse_x>=700) && (mouse_y>=3 && mouse_y<=(17*6)+3))
                    {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur une carte, numero : " << i;
                            s=temp[i]->getNom();
                            carteTest=temp[i];
                            sus=i;
                            test=1;

                        }
                    }


                }
    std::cout << "La Carte : " << temp[sus]->getNom() << std::endl;

    m_hypothese.recevoirCarte(s);

    carteTest->afficherBitmap(0,0,950,620);

    test=0;

    textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Donnez une arme cliquant en haut a droite sur les noms verts          ");
    sleep(2);
    while(test2==0)  ///700 et 17 en y a chaque nouveau
                {
                    i=mouse_y/17;
                    if((mouse_x>=700) && (mouse_y>=(17*6)+6 && mouse_y<=(17*12)+6))
                    {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur une carte, numero : " << i;
                            s=temp[i]->getNom();
                            arme=i;
                            carteTest=temp[i];
                            test2=1;

                        }
                    }


                }
    std::cout << "La Carte : " << temp[arme]->getNom() << std::endl;

    carteTest->afficherBitmap(0,0,1100,620);
    m_hypothese.recevoirCarte(s);
    m_hypothese.afficherTout();


}

void Joueur::creerAccusation()
{

    int i;
    int lieu,sus,arme;
    int test=0;
    int test2=0;
    std::vector<Carte*> temp;
    temp = m_p.getCartes();
    std::string l,s,a;
    Carte* carteTest;



    m_case.localiserJoueur();



    textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Donnez un suspect en cliquant en haut a droite sur les noms verts");
    while(test==0)  ///700 et 17 en y a chaque nouveau
                {
                    i=mouse_y/17;
                    if((mouse_x>=700) && (mouse_y>=3 && mouse_y<=(17*5)+6))
                    {
                        std::cout << "il est vers les cartes suspect carte : " << i << std::endl;

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqu� sur une carte, numero : " << i;
                            s=temp[i]->getNom();
                            carteTest=temp[i];
                            sus=i;
                            test=1;

                        }
                    }


                }
    std::cout << "La Carte : " << temp[sus]->getNom() << std::endl;

    m_hypothese.recevoirCarte(s);

    carteTest->afficherBitmap(0,0,950,620);

    test=0;

    textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Donnez une arme cliquant en haut a droite sur les noms verts          ");
    sleep(2);
    while(test2==0)  ///700 et 17 en y a chaque nouveau
                {
                    i=mouse_y/17;
                    if((mouse_x>=700) && (mouse_y>=(17*6)+6 && mouse_y<=(17*11)+9))
                    {
                        std::cout << "il est vers les cartes arme carte : " << i << std::endl;

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqu� sur une carte, numero : " << i;
                            s=temp[i]->getNom();
                            arme=i;
                            carteTest=temp[i];
                            test2=1;

                        }
                    }


                }
    a=temp[arme]->getNom();
    std::cout << "La Carte : " << temp[arme]->getNom() << std::endl;

    carteTest->afficherBitmap(0,0,1100,620);
    m_hypothese.recevoirCarte(a);
    int test3=0;

    textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Donnez un lieu en cliquant en haut a droite sur les noms verts");
    while(test3==0)  ///700 et 17 en y a chaque nouveau
                {
                    i=mouse_y/17;
                    if((mouse_x>=700) && (mouse_y>=(17*12)+9 && mouse_y<=(17*20)+6))
                    {
                        std::cout << "il est vers les cartes lieu carte : " << i << std::endl;

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqu� sur une carte, numero : " << i;
                            s=temp[i]->getNom();
                            carteTest=temp[i];
                            lieu=i;
                            test3=1;

                        }
                    }


                }
    std::cout << "La Carte : " << temp[lieu]->getNom() << std::endl;

    m_hypothese.recevoirCarte(s);

    carteTest->afficherBitmap(0,0,1250,620);

    m_hypothese.afficherTout();
}

bool Joueur::montrerCarte(Hypothese H)
{
    //system("CLS");
    int x;
    int i;
    int test=0;
    char choix;
    char verif;
    std::cout << "Voici l'hypothese : " << std::endl;
    H.afficherTout();
    std::cout << "---------------------" << std::endl;
    afficherCartes();

    textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Avez vous une carte qui permet de réfuter l'hypothese ?");
    rect(screen,0+700,720,100+700,850,makecol(0,255,0));
    rect(screen,100+700,720,200+700,850,makecol(255,0,0));

    while(test==0)
    {



    if((mouse_x>=0+700 && mouse_x<=100+700) && (mouse_y>=720 && mouse_y<=850))
                    {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur oui";
                            choix='O';
                            test=1;
                        }

                    }

                    if((mouse_x>=100+700 && mouse_x<=200+700) && (mouse_y>=720 && mouse_y<=850))
                        {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur non";
                            choix='N';
                            sleep(1);
                            test=1;
                        }

                    }
    }

    test=0;

    if(choix == 'O')
    {

        textprintf_ex(screen,font,700,590,makecol(255,255,0),makecol(0,0,0),"Mettez l'une des cartes que vous voulez montrer (en cliquant dessus)");
        std::cout << " Mettez l'une des cartes que vous voulez montrer : " << std::endl;
        rect(screen,100+700,720,200+700,850,makecol(255,0,0));
        while(test==0)  ///700 et 100 en y a chaque nouveau premiere carte 700 400
                {
                    i=mouse_x/100;
                    i=i-7;


                    if((mouse_y>=400) && (mouse_y<=580) && (mouse_x>=700) && (mouse_x<=700+(m_cartes.size()*100)))
                    {
                        std::cout << m_cartes[i]->getNom() << std::endl;

                        if (mouse_b & 1 && (m_cartes[i]->getNom() == H.getNom_des_Cartes()[0] || m_cartes[i]->getNom() == H.getNom_des_Cartes()[1] || m_cartes[i]->getNom() == H.getNom_des_Cartes()[2]))
                        {
                            std::cout << "il a cliqué sur une carte, numero : " << i;

                            std::cout << m_cartes[i]->getNom() << std::endl;
                            x=i;
                            test=1;

                        }

                    }
                    if((mouse_x>=100+700 && mouse_x<=200+700) && (mouse_y>=720 && mouse_y<=850))
                        {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur non";
                            sleep(1);
                            return true;
                        }
                    }

                }


        while(m_cartes[x]->getNom() != H.getNom_des_Cartes()[0] && m_cartes[x]->getNom() != H.getNom_des_Cartes()[1] && m_cartes[x]->getNom() != H.getNom_des_Cartes()[2]);
        std::cout << "La carte que vous avez choisi est : " << m_cartes[x]->getNom() << std::endl;
        textprintf_ex(screen,font,680,60,makecol(0,255,255),makecol(150,155,150),"La carte choisi est : %s",m_cartes[x]->getNom().c_str());

        return false;
    }
    else if(choix == 'N')
    {
        return true;
    }

}

void Joueur::afficherCartes()
{
    afficherImagesCartes();
    for (int i=0; i<m_cartes.size(); i++)
    {
        std::cout << "voici la carte : " << i << " : " << m_cartes[i]->getNom() << std::endl;
    }
}

void Joueur::estDansPiece()
{
    int ecole;
    int eglise;
    int MaisonDeKenny;
    int CentreCommercial;
    int Lac;
    int posx = 60;
    int posy = 60;
    BITMAP *image=load_bitmap("fleche.bmp",NULL);
    m_plateau.afficherPlateau();
    if((m_case.getX()==17 && m_case.getY()==9) || (m_case.getX()==22 && m_case.getY()==13))
    {
        ///le joueur est dans l'église
        std::cout << "Vous êtes dans la maison de Kenny, 1 : En haut au milieu  2 : En bas a droite"  << std::endl;
        blit(image,screen,0,0,1000,600,image->w,image->h);

        textprintf_ex(screen,font,680,60,makecol(0,255,255),makecol(150,155,150),"Vous êtes dans la maison de Kenny (avec les fleches), 1 : En haut  2 : En bas a droite");
        while(1){
        if(mouse_x > 1016+posx && mouse_x < 1063+posx && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(17);
            m_case.setY(9);
            break;
        }

        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618+2*posy && mouse_y < 665+2*posy && (mouse_b && 1))
        {
            m_case.setX(22);
            m_case.setY(13);
            break;
        }
        }
    }

    if((m_case.getX()==7 && m_case.getY()==5) || (m_case.getX()==9 && m_case.getY()==8) || (m_case.getX()==14 && m_case.getY()==8)|| (m_case.getX()==16 && m_case.getY()==5))
    {
        ///le joueur est dans l'église

        std::cout << "Vous êtes dans le centre commercial, 1 : En haut a gauche \n 2 : En bas a gauche \n 3 : en bas encore a droite \n 4 : en haut a droite" << std::endl;
        textprintf_ex(screen,font,680,60,makecol(0,255,255),makecol(150,155,150),"Vous êtes dans le centre commercial (avec les fleches), 1 : En haut a gauche \n 2 : En bas a gauche \n 3 : en bas encore a droite \n 4 : en haut a droite");

        blit(image,screen,0,0,1000,600,image->w,image->h);
        //rect(screen,1016,618+2*posy,1063,665+2*posy,makecol(10,10,10)); ///en bas a gauche
        while(1){
        if(mouse_x > 1016 && mouse_x < 1063 && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(7);
            m_case.setY(5);
            break;
        }
        if(mouse_x > 1016 && mouse_x < 1063 && mouse_y > 618+2*posy && mouse_y < 665+2*posy && (mouse_b && 1))
        {
            m_case.setX(9);
            m_case.setY(8);
            break;
        }
        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618+2*posy && mouse_y < 665+2*posy && (mouse_b && 1))
        {
            m_case.setX(14);
            m_case.setY(8);
            break;
        }
        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(16);
            m_case.setY(5);
            break;
        }
        }
    }
if((m_case.getX()==16 && m_case.getY()==16) || (m_case.getX()==22 && m_case.getY()==13))
    {
        ///le joueur est dans l'église
        std::cout << "Vous êtes dans le lac, 1 : En haut au milieu \n 2 : En haut a droite" << std::endl;
        textprintf_ex(screen,font,680,60,makecol(0,255,255),makecol(150,155,150),"Vous êtes dans le lac (avec les fleches), 1 : En haut au milieu \n 2 : En haut a droite ");

        blit(image,screen,0,0,1000,600,image->w,image->h);
        while(1){
        if(mouse_x > 1016 && mouse_x < 1063 && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(16);
            m_case.setY(16);
            break;
        }

        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(20);
            m_case.setY(13);
            break;
        }
        }
    }

    if((m_case.getX()==6 && m_case.getY()==16) || (m_case.getX()==8 && m_case.getY()==12))
    {
        ///le joueur est dans l'�cole
        std::cout << "Vous �tes dans l'�cole, 1 : En bas \n 2 : A droite" << std::endl;
        textprintf_ex(screen,font,680,60,makecol(0,255,255),makecol(150,155,150),"Vous etes dans l'ecole (avec les fleches), 1 : En bas  2 : A droite");

        blit(image,screen,0,0,1000,600,image->w,image->h);
        while(1){
        if(mouse_x > 1016+posx && mouse_x < 1063+posx && mouse_y > 618+2*posy && mouse_y < 665+2*posy && (mouse_b && 1))
        {
            m_case.setX(6);
            m_case.setY(16);
            break;
        }
        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618+posy && mouse_y < 665+posy && (mouse_b && 1))
        {
            m_case.setX(8);
            m_case.setY(12);
            break;
        }
        }
    }
    ///if( m_x==15 && m_y==20 ||  m_x==11 && m_y==17 || m_x==12 && m_y==17)

    if((m_case.getX()==15 && m_case.getY()==20) || (m_case.getX()==11 && m_case.getY()==17) || (m_case.getX()==12 && m_case.getY()==17))
    {
        ///le joueur est dans l'�glise
        std::cout << "Vous �tes dans l'eglise, 1 : En haut a gauche \n 2 : En haut a droite \n 3 : A droite" << std::endl;
        textprintf_ex(screen,font,680,60,makecol(0,255,255),makecol(150,155,150),"Vous etes dans l'eglise, vous pouvez cliquer sur les fleches : En haut a gauche | En haut a droite | A droite");
        blit(image,screen,0,0,1000,600,image->w,image->h);
        while(1)
        {
        rect(screen,1016,618,1063,665,makecol(10,10,10)); ///en haut a gauche
        rect(screen,1016+posx,618,1063+posx,665,makecol(10,10,10)); ///en haut
        rect(screen,1016+2*posx,618,1063+2*posx,665,makecol(10,10,10)); ///en haut a droite
        rect(screen,1016+2*posx,618+posy,1063+2*posx,665+posy,makecol(10,10,10)); ///a droite
        rect(screen,1016+2*posx,618+2*posy,1063+2*posx,665+2*posy,makecol(10,10,10)); ///en bas a droite
        rect(screen,1016+posx,618+2*posy,1063+posx,665+2*posy,makecol(10,10,10)); ///en bas
        rect(screen,1016,618+2*posy,1063,665+2*posy,makecol(10,10,10)); ///en bas a gauche
        rect(screen,1016,618+posy,1063,665+posy,makecol(10,10,10)); ///a gauche
        std::cout << "x :" << mouse_x << " y :" << mouse_y << std::endl;
        if(mouse_x > 1016 && mouse_x < 1063 && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(11);
            m_case.setY(17);
            break;
        }
        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618 && mouse_y < 665 && (mouse_b && 1))
        {
            m_case.setX(12);
            m_case.setY(17);
            break;
        }
        if(mouse_x > 1016+2*posx && mouse_x < 1063+2*posx && mouse_y > 618+posy && mouse_y < 665+posy && (mouse_b && 1))
        {
            m_case.setX(15);
            m_case.setY(20);
            break;
        }
        }
    }

}

void Joueur::faireLeTour(PlateauJeu lePlateau)
{
    gotoXY(0,5);
    int touche;
    std::cout << "tu peux faire " << m_de.getChiffre() << " deplacement" << std::endl;
    char carac;
    int fin;
    int poscarac;
    int i=0;
    afficherCartes();
    m_estHypotheseFaite = false;
    while(i<m_de.getChiffre() && !m_estHypotheseFaite)
    {
        if (keypressed())
        {
            touche=readkey();


            carac=(char)touche;


            if(key[KEY_UP])
            {
                setCase(getCase().getX(),getCase().getY()-1);
                afficherLeCase();
                clearCase();
                i++;
                std::cout << "il reste " << i << " deplacement(s)" << std::endl;
            }

            if(key[KEY_RIGHT])
            {
                setCase(getCase().getX()+1,getCase().getY());
                afficherLeCase();
                clearCase();
                i++;
                std::cout << "il reste " << i << " deplacement(s)" << std::endl;
            }

            if(key[KEY_LEFT])
            {
                setCase(getCase().getX()-1,getCase().getY());
                afficherLeCase();
                clearCase();
                i++;
                std::cout << "il reste " << i << " deplacement(s)" << std::endl;
            }

            if(key[KEY_DOWN])
            {
                setCase(getCase().getX(),getCase().getY()+1);
                //lePlateau.afficherPlateau();
                afficherLeCase();
                clearCase();
                i++;
                std::cout << "il reste " << i << " deplacement(s)" << std::endl;
            }

            if (carac=='\r')
                fin=1;

        }
    }
    std::cout << "le tour est fini" << std::endl;
}

UneCase Joueur::getCase()
{
    return m_case;
}


bool Joueur::getEstAccusationFaite() const
{
    return m_estAccusationFaite;
}

void Joueur::afficherImagesCartes()
{
    for (int i=0; i<m_cartes.size(); i++)
    {
        m_cartes[i]->afficherBitmap(0,0,700+100*i,400);
    }
}

void Joueur::remplirCalpin()
{
    int suspect;
    int lieu;
    int test=0;
    rect(screen,100+700,720,200+700,850,makecol(255,0,0));

    while (test==0)
    {
        if((mouse_x>=100+700 && mouse_x<=200+700) && (mouse_y>=720 && mouse_y<=850))
                        {

                        if (mouse_b & 1)
                        {
                            std::cout << "il a cliqué sur non";

                            test=1;
                        }

                    }
    //std::cout << "vous avez 10 secondes pour remplir le calpin" << std::endl;
    if(mouse_x>1155 && mouse_x<1283 && mouse_y < 385)
    {

        suspect=(mouse_y)/23;
        suspect=suspect-3;


        if(mouse_b && 1)
        {
            m_calepin.croixSurCalepin(suspect);
        }
    }
    if(mouse_x>1400 && mouse_x<1500 && mouse_y < 385)
    {
        lieu=(mouse_y)/23;
        lieu=lieu-3+13;
        std::cout << lieu;


        if(mouse_b && 1)
        {
            m_calepin.croixSurCalepin(lieu);
        }
    }


    }


}

void Joueur::clearCase()
{
   m_ancienneCase.afficherCase(makecol(150,150,150),'v');
}

void Joueur::afficherDebut(int i)
{
    BITMAP *tour=load_bitmap("TourJoueur.bmp",NULL);
    blit(tour,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    textprintf_ex(screen,font,680,30,makecol(255,255,0),makecol(150,105,150),"C'est au joueur %d de jouer",i+1);

    sleep(3);
    rectfill(screen,0,0,1600,900,makecol(10,10,10));
}

void Joueur::afficherImageHypothese(int i)
{
    BITMAP *tour=load_bitmap("Hypothese.bmp",NULL);
    blit(tour,screen,0,400,0,0,SCREEN_W,SCREEN_H);
    textprintf_ex(screen,font,680,30,makecol(0,255,255),makecol(150,155,150),"C'est au joueur %d de refuter (ou non) l'hypothese",i);

    sleep(3);

}

void Joueur::save(int i, int nbr_j)
{
    std::string nom = "save_J";
    nom += (i + 49);
    nom += ".txt";
    std::ofstream flux(nom.c_str());   //ofstream : ecriture

    if(flux)
    {
        if(i==0)
            flux << nbr_j << std::endl;

        flux << m_case.getX() << " " << m_case.getY() << " " << m_case.getPiece() << std::endl;  //ecrit les coords de la case et son type
        for(int i = 0; i<m_cases.size(); i++)   //ecrit le vecteur de cases dans fichier
            flux << m_cases[i].getX() << " " <<m_cases[i].getY() << " " << m_cases[i].getPiece() << std::endl;

        flux << m_cartes.size() << std::endl;   //ecrit le nbr de carte du vecteur

        for(int i = 0; i<m_cartes.size(); i++)  //ecrit vecteur de pointeurs de cartes dans fichier
            flux << m_cartes[i]->getNom() << std::endl << m_cartes[i]->getType() << std::endl;

        m_compte.save();
        //flux << m_compte.getLog() << " " << m_compte.getPass() << " " << m_compte.getNiveau() << " " << m_compte.getCompteur() << " " << m_compte.getComptGagnee() << " " << m_compte.getCouleur() << std::endl;

        flux << m_nb_tours_joues;
    }
    else
    {
        std::cout << "ERREUR : " << nom << std::endl;
    }
}

void Joueur::load(int i, int nbr_j, std::vector<BITMAP*> mesCartes)
{
    std::string nom = "save_J";
    nom += (i + 49);
    nom += ".txt";
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture

    if(fichier)
    {
        if(i==0)
        {
            int a;  //var poubelle : enleve le nbre de joueurs
            fichier >> a;
        }
        std::cout << "pipiiiiiiiiiiiii" << std::endl;

        //charge la case d'ou etait le joueur
        int aa, bb, cc;
        fichier >> aa >> bb >> cc;
        m_case.setX(aa);
        m_case.setY(bb);
        m_case.setPiece(cc);

        std::cout << "pipiiiiiiiiiiiii" << std::endl;

        //charge les cartes du joueur
        int nbr_cartes;
        fichier >> nbr_cartes;
        std::string poub;
        getline(fichier, poub); //prend une ligne vide??

        std::cout << "pipiiiiiiiiiiiii" << std::endl;

        for(int i = 0; i<nbr_cartes; i++)
        {
            std::cout << "ccc" << i << std::endl;
            std::string nomm, tempo;
            char type;
            getline(fichier, nomm);
            getline(fichier, tempo);
            type = tempo.at(0); //prend le 1er caractere de la string

            std::cout << "ddd" << i << std::endl;
            Carte* crd = new Carte();
            m_cartes.push_back(crd);
            m_cartes[i]->setNom(nomm);
            m_cartes[i]->setType(type);

            if(nomm == "Mr. Mackey")
                m_cartes[i]->setBtm(mesCartes[5]);
            else if(nomm == "Cartman")
                m_cartes[i]->setBtm(mesCartes[0]);
            else if(nomm == "Kyle")
                m_cartes[i]->setBtm(mesCartes[3]);
            else if(nomm == "Stan")
                m_cartes[i]->setBtm(mesCartes[2]);
            else if(nomm == "Mr. Garison")
                m_cartes[i]->setBtm(mesCartes[1]);
            else if(nomm == "Chef")
                m_cartes[i]->setBtm(mesCartes[4]);
            else if(nomm == "Le baton de la verite")
                m_cartes[i]->setBtm(mesCartes[6]);
            else if(nomm == "Shuriken")
                m_cartes[i]->setBtm(mesCartes[7]);
            else if(nomm == "Epee en bois")
                m_cartes[i]->setBtm(mesCartes[8]);
            else if(nomm == "Hache")
                m_cartes[i]->setBtm(mesCartes[9]);
            else if(nomm == "Arc")
                m_cartes[i]->setBtm(mesCartes[10]);
            else if(nomm == "Flechette")
                m_cartes[i]->setBtm(mesCartes[11]);
            else if(nomm == "L'ecole")
                m_cartes[i]->setBtm(mesCartes[12]);
            else if(nomm == "Maison de Kenny")
                m_cartes[i]->setBtm(mesCartes[13]);
            else if(nomm == "L'eglise")
                m_cartes[i]->setBtm(mesCartes[14]);
            else if(nomm == "Le centre commercial")
                m_cartes[i]->setBtm(mesCartes[15]);
            else if(nomm == "Le restaurant chinois")
                m_cartes[i]->setBtm(mesCartes[16]);
            else if(nomm == "La foret")
                m_cartes[i]->setBtm(mesCartes[17]);
            else if(nomm == "Le lac")
                m_cartes[i]->setBtm(mesCartes[18]);
            else if(nomm == "Le comissariat")
                m_cartes[i]->setBtm(mesCartes[19]);
            else
                m_cartes[i]->setBtm(mesCartes[20]);
        }

        std::cout << "pipiiiiiiiiiiiii" << std::endl;

        //charge les infos du compte
        std::string log, pass, niv;
        int compt, comptG, couleur;

        fichier >> log;
        fichier >> pass;
        /*
        fichier >> niv;
        fichier >> compt;
        fichier >> comptG;
        fichier >> couleur;
*/
        m_compte.setLog(log);
        m_compte.setPass(pass);

        m_compte.load(log);
        /*
        m_compte.setNiveau(niv);
        m_compte.setCompteur(compt);
        m_compte.setCompteurGagnee(comptG);
        m_compte.setCouleur(couleur);
*/
        std::cout << "pipiiiiiiiiiiiii" << std::endl;

        //charge le nombre de tour joue
        int n;
        fichier >> n;
        m_nb_tours_joues = n;

        std::cout << "pipiiiiiiiiiiiii" << std::endl;

    }
    else
    {
        std::cout << "ERREUR : Impossible d'ourvrir le fichier" << std::endl;
    }
}

