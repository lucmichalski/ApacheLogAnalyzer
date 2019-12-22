/*************************************************************************
ApplicationArguments - Arguments spécifiés à l'application lors de son lancement
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
							- Milène DAUGAN
							- Loïc DUBOIS-TERMOZ
	e-mail               :
							- milene.daugan@insa-lyon.fr
							- loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#ifndef APACHELOGANALYZER_APPLICATIONARGUMENTS_H
#define APACHELOGANALYZER_APPLICATIONARGUMENTS_H

#include <string>
#include <iostream>

/**
 * ApplicationArguments contient l'ensemble des données sur les arguments de l'application spécifiés au lancement
 * de celle-ci. Il s'agit d'un simple conteneur sans logique d'implémenter (responsabilité déléguée au reste
 * du programme).
 */
class ApplicationArguments {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const ApplicationArguments &applicationArguments);

    /**
     * @return La référence sur le nom du fichier de log à importer
     */
    const std::string &GetLogFileName() const {
        return logFileName;
    }

    /**
     * @return "true" si les extensions css, js et image doivent être exclus, "false" sinon
     */
    bool IsExcludeExtensions() const {
        return excludeExtensions;
    }

    /**
     * @return Un nombre entre 0 et 23 correspondant au créneau horaire sur lequel on souhaite conserver les
     *      logs, ou -1 si aucun filtrage ne doit être effectué
     */
    int GetFilterHour() const {
        return filterHour;
    }

    /**
     * @return Le nom du fichier .dot à générer. Si la chaîne est vide, alors aucun fichier ne sera généré
     */
    const std::string &GetDotFileName() const {
        return dotFileName;
    }

    /**
     * Constructeur des arguments de l'application.
     *
     * @param _logFileName Le nom du fichier de log à importer
     * @param _excludeExtensions "true" si les extensions css, image et js doivent être exclus, "false" sinon
     * @param _filterHour L'heure à utiliser pour le filtrage du log (entre 0 et 23), -1 si aucun filtrage
     * @param _dotFileName Le nom du fichier .dot (de l'application GraphViz) à générer, chaîne vide si aucun fichier
     *      à générer
     */
    ApplicationArguments(std::string _logFileName, bool _excludeExtensions, int _filterHour, std::string _dotFileName)
        : logFileName(move(_logFileName)), excludeExtensions(_excludeExtensions), filterHour(_filterHour),
          dotFileName(move(_dotFileName)) {}

    /**
     * Constructeur par copie.
     * Comportement par défaut.
     */
    ApplicationArguments(const ApplicationArguments &applicationArguments) = default;

    /**
     * Destructeur de l'instance.
     * Comportement par défaut.
     */
    virtual ~ApplicationArguments() = default;

protected:
    std::string logFileName;
    bool excludeExtensions = false;
    int filterHour = -1;
    std::string dotFileName;
};

inline std::ostream &operator<<(std::ostream &os, const ApplicationArguments &applicationArguments) {
    os << "ApplicationArguments{logFileName=" << applicationArguments.logFileName
       << ", excludeExtensions=" << std::boolalpha << applicationArguments.excludeExtensions
       << ", filterHour=" << applicationArguments.filterHour
       << ", dotFileName=" << applicationArguments.dotFileName
       << "}";
    return os;
}

#endif //APACHELOGANALYZER_APPLICATIONARGUMENTS_H
