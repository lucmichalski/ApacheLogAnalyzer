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
#include "Controller.h"
#include <iostream>

using namespace std;

/**
 * Exécute différentes instructions du programme suivant les arguments spécifiés par l'utilisateur
 * au lancement de l'application.
 */
Controller::Controller(char **argv) {
    try {
        createApplicationArguments(argv);
        registerLogFile();
        const Log *_log = filterLog();
        if (applicationArguments->GetDotFileName().empty()) {
            // TODO : Création du tableau de documents hits
            const vector<DocumentHits> *documentsHits = nullptr;
            // TODO : Tri par ordre décroissant des hits du tableau
            showTopDocuments(*documentsHits, MAX_DOCUMENTS_SHOW);
            delete documentsHits;
        } else {
            generateDotFile(log);
        }
    } catch (const exception &e) {
        throw e;
    }
}

/**
 * Supprime tous les attributs de la classe (LogManager, FileManager, ApplicationArguments et Log).
 */
Controller::~Controller() {
    delete logManager;
    delete fileManager;
    delete applicationArguments;
    delete log;
}

void Controller::createApplicationArguments(char **argv) {
    // TODO : Vérification de la validité de la commande (levée d'exception si pertinent)
    // TODO : Instanciation de la classe ApplicationArguments (si commande valide)
}

void Controller::registerLogFile() {
    // TODO : Importation du fichier de log en unordened_set<string>
    // TODO : Instanciation de la classe Log
}

const Log *Controller::filterLog() {
    const Log *excludedExtensionsLog = nullptr;
    const Log *finalLog = nullptr;
    if (applicationArguments->IsExcludeExtensions()) {
        excludedExtensionsLog = filterByExtensions(*log);
    }
    if (applicationArguments->GetFilterHour() != -1) {
        if (excludedExtensionsLog) {
            finalLog = filterByHour(*excludedExtensionsLog, applicationArguments->GetFilterHour());
        } else {
            finalLog = filterByHour(*log, applicationArguments->GetFilterHour());
        }
        delete excludedExtensionsLog;
    } else if (excludedExtensionsLog) {
        finalLog = excludedExtensionsLog;
    } else {
        finalLog = log;
    }
    return finalLog;
}

const Log *Controller::filterByExtensions(const Log &_log) {
    // TODO : Lister les extensions à filtrer
    // TODO : Clonage du Log + Filtrage sur les extensions listés
    return nullptr;
}

const Log *Controller::filterByHour(const Log &_log, int hour) {
    // TODO : Clonage du Log + Filtrage sur l'heure spécifiée
    return nullptr;
}

void Controller::showTopDocuments(const vector<DocumentHits> &documentsHits, int max) const {
    // TODO : Affichage des n=max éléments dans l'ordre décroissant
    cerr << "Non implémenté" << endl;
}

void Controller::generateDotFile(const Log *_log) const {
    // TODO : Générer le fichier .dot à partir du log spécifié
    // Priorité : faible (spécifications à détailler)
}