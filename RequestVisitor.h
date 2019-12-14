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
#ifndef APACHELOGANALYZER_REQUESTVISITOR_H
#define APACHELOGANALYZER_REQUESTVISITOR_H

#include <string>

using namespace std;

/**
 * Le rôle de la classe RequestVisitor est en lien avec celui de la classe RequestData
 */
class RequestVisitor {
public:
    /**
     * @return Le nom d'utilisateur spécifique aux logs
     */
    const string &GetUserLogName() const {
        return userLogName;
    }

    /**
     * @return Le nom d'utilisateur d'origine
      */
    const string &GetUserName() const {
        return userName;
    }

    /**
     * Constructeur par défaut du request visitor.
     * Comportement par défaut.
     */
    RequestVisitor() = default;

    /**
     * Constructeur du request visitor.
     *
     * @param _userLogName Le nom d'utilisateur spécifique aux logs
     * @param _userName Le nom d'utilisateur d'origine
     */
    RequestVisitor(string _userLogName, string _userName)
            : userLogName(move(_userLogName)), userName(move(_userName)) {}

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
    virtual ~RequestVisitor() = default;

protected:
    string userLogName;
    string userName;
};

#endif //APACHELOGANALYZER_REQUESTVISITOR_H
