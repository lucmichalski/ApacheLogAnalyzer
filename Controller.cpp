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
 * Instancie au préalable les classes LogManager et FileManager.
 * Exécute différentes instructions du programme suivant les arguments spécifiés par l'utilisateur
 * au lancement de l'application.
 */
Controller::Controller(char **argv) {
    // TODO : Instanciation de LogManager et FileManager
    try {
        createApplicationArguments(argv);
        registerLogFile();
        const Log *_log = filterLog();
        if (applicationArguments->GetDotFileName().empty()) {
            // TODO : Création du tableau de documents hits
            const vector<const DocumentHits * const> *documentsHits = nullptr;
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

/**
 * Vérifie la validité des arguments saisis par l'utilisateur et lève une exception si une erreur est détectée.
 * La vérification s'effectue par prédiction de la valeur du prochain argument de la commande à lire avant
 * de le lire. Si la valeur attendue est différente de celle prédite, alors une exception est levée.
 * La vérification s'effectue par gros grains, c'est à dire que seul un format général est vérifié,
 * les vérifications plus avancées (telles que la validité du chemin de fichier spécifié) seront faites par
 * le reste du programme.
 * La création de l'instance de la classe ApplicationArguments est couplée avec la vérification. Ainsi, si la
 * vérification échoue, l'instanciation de la classe échoue également.
 */
void Controller::createApplicationArguments(char **argv) {
    // TODO : Vérification de la validité de la commande (levée d'exception si pertinent)
    // TODO : Instanciation de la classe ApplicationArguments (si commande valide)
}

/**
 * Importe les lignes du fichier de log puis instancie la classe LogFactory en passant au constructeur
 * l'ensemble des lignes du fichier de log lu pour récupérer ensuite l'instance de la classe Log. Cette dernière
 * sera stockée dans le contrôleur de l'application.
 */
void Controller::registerLogFile() {
    // TODO : Importation du fichier de log en unordened_set<string>
    // TODO : Instanciation de la classe Log
}

/**
 * Détermine quels types de filtrage doivent s'opérer sur l'instance de la classe Log se basant
 * sur les arguments d'exécution de l'application. Si au moins un filtrage a été exécuté, alors
 * une copie de la classe Log sera retournée, sinon l'instance de la classe Log du contrôleur
 * sera retournée.
 */
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

/**
 * Tri au préalable les associations entre un document et son nombre de hits par ordre décroissant du nombre
 * de hits. Ensuite, l'affichage se fait par lecture ordonnée des DocumentHits triés sur la sortie standard.
 */
void Controller::showTopDocuments(const vector<const DocumentHits * const> &documentsHits, int max) const {
    // TODO : Affichage des n=max éléments dans l'ordre décroissant
    cerr << "Non implémenté" << endl;
}

/**
 * // TODO : Spécifications à détailler
 */
void Controller::generateDotFile(const Log *_log) const {
    // TODO : Générer le fichier .dot à partir du log spécifié
    // Priorité : faible (spécifications à détailler)
}