#include <utility>

#include <utility>

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
// Interface de la classe <ApplicationArguments> (fichier ApplicationArguments.h)
#ifndef APACHELOGANALYZER_APPLICATIONARGUMENTS_H
#define APACHELOGANALYZER_APPLICATIONARGUMENTS_H
//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <ApplicationArguments>
//  ApplicationArguments contient l'ensemble des données sur les arguments
//  de l'application spécifiés au lancement de celle-ci. Il s'agit
//  d'un simple conteneur sans logique.
//------------------------------------------------------------------------

class ApplicationArguments {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    /**
     * @return La référence sur le nom du fichier de log à importer
     */
    const string &GetLogFileName() const {
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
    const string &GetDotFileName() const {
        return dotFileName;
    }

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur des arguments de l'application.
     *
     * @param theLogFileName Le nom du fichier de log à importer
     * @param isExcludeExtensions "true" si les extensions css, image et js doivent être exclus, "false" sinon
     * @param theFilterHour L'heure à utiliser pour le filtrage du log (entre 0 et 23), -1 si aucun filtrage
     * @param theDotFileName Le nom du fichier .dot (de l'application GraphViz) à générer, chaîne vide si aucun fichier
     *      à générer
     */
    ApplicationArguments(string theLogFileName, bool isExcludeExtensions, int theFilterHour, string theDotFileName)
            : logFileName(move(theLogFileName)), excludeExtensions(isExcludeExtensions), filterHour(theFilterHour),
              dotFileName(move(theDotFileName)) {}

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

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string logFileName;
    bool excludeExtensions = false;
    int filterHour = -1;
    string dotFileName;
};

#endif //APACHELOGANALYZER_APPLICATIONARGUMENTS_H
