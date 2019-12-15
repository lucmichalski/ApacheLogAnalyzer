/*************************************************************************
                    Controller - Contrôleur de l'application
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#ifndef APACHELOGANALYZER_CONTROLLER_H
#define APACHELOGANALYZER_CONTROLLER_H

#include "ApplicationArguments.h"
#include "LogManager.h"
#include "FileManager.h"
#include "Log.h"
#include "DocumentHits.h"

const int MAX_DOCUMENTS_SHOW = 10;

/**
 * Il s'agit de l'interface entre les informations saisies par l'utilisateur et le reste de l'application.
 * Son unique rôle est d'organiser les traitements à réaliser.
 */
class Controller {
public:
    /**
     * Constructeur du contrôleur de l'application.
     *
     * @param argv Liste des arguments saisies par l'utilisateur
     * @throws exception Suivant l'exception levée par les méthodes appelées
     */
    Controller(char **argv);

    /**
     * Destructeur du contrôleur.
     * Supprime également tous les attributs de la classe au préalable.
     */
    ~Controller();

protected:
    /**
     * Créer les arguments d'exécution de l'application en se basant sur les valeurs saisies
     * par l'utilisateur.
     * La méthode propagera une exception dans le cas où les saisies de l'utilisateur sont incorrectes.
     *
     * @param argv La liste des arguments spécifiés par l'utilisateur
     * @throws exception Si les saisies de l'utilisateur sont incorrectes.
     */
    void createApplicationArguments(char **argv);

    void registerLogFile();

    const Log *filterLog();

    // TODO : les deux méthodes ci-dessous sont à déplacer dans la classe LogManager

    const Log *filterByExtensions(const Log &_log);

    const Log *filterByHour(const Log &_log, int hour);

    void showTopDocuments(const vector<DocumentHits> &documentsHits, int max) const;

    void generateDotFile(const Log *_log) const;

    LogManager *logManager = nullptr;
    FileManager *fileManager = nullptr;
    ApplicationArguments *applicationArguments = nullptr;
    Log *log = nullptr;
};

#endif //APACHELOGANALYZER_CONTROLLER_H
