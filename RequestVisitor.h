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
#include <iostream>

/**
 * Le rôle de la classe RequestVisitor est en lien avec celui de la classe RequestData
 */
class RequestVisitor {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const RequestVisitor &requestVisitor);

    /**
     * @return Le nom d'utilisateur spécifique aux logs
     */
    const std::string &GetUserLogName() const {
        return userLogName;
    }

    /**
     * @return Le nom d'utilisateur d'origine
      */
    const std::string &GetUserName() const {
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
    RequestVisitor(std::string _userLogName, std::string _userName)
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
    std::string userLogName;
    std::string userName;
};

inline std::ostream &operator<<(std::ostream &os, const RequestVisitor &requestVisitor) {
    os << "RequestVisitor{userLogName=" << requestVisitor.userLogName
       << ", userName=" << requestVisitor.userName
       << "}";
    return os;
}

#endif //APACHELOGANALYZER_REQUESTVISITOR_H
