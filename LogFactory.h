/*************************************************************************
                  LogFactory - Fabrique de la classe Log
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#ifndef APACHELOGANALYZER_LOGFACTORY_H
#define APACHELOGANALYZER_LOGFACTORY_H

#include "Log.h"
#include "RequestData.h"
#include "Date.h"

/**
 * LogFactory a pour rôle d'instancier la classe Log ainsi que les classes associées (Document et Request)
 * en se basant sur les lignes des logs importées.
 */
class LogFactory {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const LogFactory &logFactory);

    /**
     * Créer un Log ainsi que les Request et Document associés et le retourne ensuite.
     * La suppression du log est à la charge de l'appelant.
     *
     * @param logLines Les lignes du fichier de log importé
     * @return Le Log créée
     */
    Log *CreateLog(std::unordered_set<std::string *> *logLines) const;

protected:
    /**
     * Analyse la ligne passée en paramètre et retourne le request data correspondant.
     *
     * @param logLine La ligne de log à analyser
     * @return Le request data correspondant aux données de la ligne de log
     */
    const RequestData *analyzeLogLine(const std::string &logLine) const;

    /**
     * Créer la date à partir de la chaîne de caractères spécifiées venant du fichier de log lu.
     *
     * @param date La date sous forme de chaîne de caractères avec comme format celui du fichier de log lu
     * @return La date correspondante sous la forme d'une instance de la classe Date
     */
    Date createDate(std::string &date) const;
};

inline std::ostream &operator<<(std::ostream &os, const LogFactory &logFactory) {
    os << "LogFactory{}";
    return os;
}

#endif //APACHELOGANALYZER_LOGFACTORY_H
