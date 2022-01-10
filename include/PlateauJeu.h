#ifndef PLATEAUJEU_H
#define PLATEAUJEU_H
#include <vector>



class UneCase;
class Joueur;



class PlateauJeu
{
    public:
        PlateauJeu();
        PlateauJeu(std::vector<Joueur*> toutlesJ);
        PlateauJeu(UneCase C);
        ~PlateauJeu();
        void ajouterCase(UneCase C);
        void afficherPlateau();
        std::vector<UneCase> getCases();
        void afficherJsurPlateau();
        void afficher_joueur();

        void save_plat();
        void load_plat();

    protected:

    private:
        std::vector<UneCase> m_cases;
        std::vector<Joueur*> m_joueurs;
       // std::vector<Piece> m_pieces;
};

#endif // PLATEAUJEU_H
