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
    explicit Controller(char **argv);

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

    /**
     * Enregistre le fichier de log associé au nom du fichier spécifié dans les arguments d'exécution
     * de l'application en important son contenu.
     * @throws exception Si une exception durant le traitement du fichier est levée
     */
    void registerLogFile();

    /**
     * Filtre le contenu du Log à partir d'une copie de ce dernier en fonction des arguments d'exécution
     * de l'application.
     * Deux types de filtrage sont possibles :
     * - Filtrage par extensions : exclusion des documents (et requêtes associées) ayant comme
     * extensions .css, .js et les extensions d'image (.jpg, .png et .gif)
     * - Filtrage par créneau horaire : exclusion des requêtes
     *
     * @return Une éventuelle copie de l'instance de Log initiale si un filtrage a été effectué,
     *  l'instance initiale sinon
     */
    const Log *filterLog() const;

    /**
     * Affichage des n=max documents ayant le plus de hits par ordre décroissant.
     *
     * @param documentsHits Les associations entre un document et son nombre de hits.
     * @param max Le nombre maximum de documents à afficher
     */
    void showTopDocuments(const vector<const DocumentHits *> &documentsHits, int max) const;

    /**
     * Génération du fichier .dot à partir des informations du fichier de log importé.
     *
     * @param _log L'instance de la classe Log correspondant au fichier de log importé
     */
    void generateDotFile(const Log *_log) const;

    LogManager *logManager = nullptr;
    FileManager *fileManager = nullptr;
    ApplicationArguments *applicationArguments = nullptr;
    Log *log = nullptr;
};

#endif //APACHELOGANALYZER_CONTROLLER_H
