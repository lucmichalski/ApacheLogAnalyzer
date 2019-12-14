/*************************************************************************
            RequestData - Représente les données d'une requête
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
//-- Interface de la classe <RequestVisitor> (fichier RequestVisitor.h) --
#ifndef APACHELOGANALYZER_REQUESTVISITOR_H
#define APACHELOGANALYZER_REQUESTVISITOR_H
//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <RequestVisitor>
//  En lien avec le rôle de la classe RequestData
//------------------------------------------------------------------------

class RequestVisitor {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    /**
     * @return Le nom d'utilisateur spécifique aux logs
     */
    const string &getUserLogName() const {
        return userLogName;
    }

    /**
     * @return Le nom d'utilisateur d'origine
      */
    const string &getUserName() const {
        return userName;
    }

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur du request visitor.
     *
     * @param theUserLogName Le nom d'utilisateur spécifique aux logs
     * @param theUserName Le nom d'utilisateur d'origine
     */
    inline RequestVisitor(string theUserLogName, string theUserName)
    : userLogName(theUserLogName), userName(theUserName) {}

    /**
     * Constructeur par copie du request visitor.
     * Aucune action spécifique effectuée.
     *
     * @param requestData La référence au request visitor à copier
     */
    RequestVisitor(const RequestVisitor &requestVisitor) = default;

    /**
     * Destructeur du request visitor.
     * Aucune action spécifique effectuée.
     */
    ~RequestVisitor() = default;

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
    string userLogName;
    string userName;
};

#endif //APACHELOGANALYZER_REQUESTVISITOR_H
