#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include <UneCase.h>
#include <Carte.h>
#include <Compte.h>
#include <De.h>
#include <PlateauJeu.h>
#include <Hypothese.h>
#include <Pioche.h>
#include <Calepin.h>


//class Carte;
class Compte;
class UneCase;
class Pioche;



class Joueur
{
public:
    Joueur();
    ~Joueur();
    void associer_compte(Compte unCompte);
    void recup_pioche(Pioche laPioche);
    void afficher_compte();
    std::string getLogin();
    void tirer_de();
    void creerHypothese();
    bool validerHypothese(Hypothese H);
    void recupCase();
    void avancerHaut();
    void recupererPlateau(PlateauJeu lePlateau);
    void afficherCase();
    void afficherLeCase();
    void afficherNumerosCase();
    void faireLeTour(PlateauJeu lePlateau);
    void initialiser_tout_avant_deplacement(Compte cmpte);
    void afficherCartes();
    bool montrerCarte(Hypothese H);
    void creerAccusation();
    void estDansPiece();
    void afficherImagesCartes();
    void remplirCalpin();

    Calepin getCalepin(){return m_calepin;}

    void clearCase();
    void afficherDebut(int i);
    void afficherImageHypothese(int i);

    ///getter
    UneCase getCase();
    bool getEstHypotheseFaite() const;
    bool getEstAccusationFaite() const;
    Hypothese getHypothese() const;
    De getDe(){return m_de;}


    ///setter
    void setCase(int x, int y);
    void setCarte(Carte* uneCarte);
    void setCompte();

    ///ss-prgm de sauvegarde/chargement
    void save(int i, int nbr_j);
    void load(int i, int nbr_j, std::vector<BITMAP*> mesCartes);

protected:

private:
    UneCase m_case;
    PlateauJeu m_plateau;
    Carte* m_carte;
    std::vector<UneCase> m_cases;
    std::vector<Carte*> m_cartes;
    Pioche m_p;
    Compte m_compte;
    De m_de;
    Hypothese m_hypothese;
    int m_nb_tours_joues;
    bool m_estHypotheseFaite=false;
    bool m_estAccusationFaite=false;
    Calepin m_calepin;
    UneCase m_ancienneCase;

};
int load_nbrj();


#endif // JOUEUR_H
