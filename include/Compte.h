#ifndef COMPTE_H
#define COMPTE_H
#include <iostream>


class Joueur;
class Compte
{
    public:
        Compte() = default;
        Compte(std::string login,std::string motdepasse,std::string couleur);
        ~Compte();
        void afficher();
        void save();
        void load(std::string log);
        void init_compte(std::string& log, std::string& pass);

        ///getter
        std::string getLog(){return m_login;}
        std::string getPass(){return m_password;}
        std::string getNiveau(){return m_niveau;}
        int getCompteur(){return m_compteurPartie;}
        int getComptGagnee(){return m_compteurPartieGagnees;}
        int getCouleur(){return m_couleur;}

        ///setter
        void setLog(std::string _log){m_login = _log;}
        void setPass(std::string _pass){m_password = _pass;}
        void setNiveau(std::string _niveau){m_niveau = _niveau;}
        void setCompteur(int _cmpt){m_compteurPartie = _cmpt;}
        void setCompteurGagnee(int _cmptG){m_compteurPartieGagnees = _cmptG;}
        void setCouleur(int _couleur){m_couleur = _couleur;}

    protected:

    private:
        std::string m_login;
        std::string m_password;
        std::string m_niveau;
        int m_compteurPartie;
        int m_compteurPartieGagnees;
        int m_couleur;
};

#endif // COMPTE_H
