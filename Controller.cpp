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
Controller::Controller(int argc, char **argv) {
    fileManager = new FileManager();
    cout << "fileManager=" << *fileManager << endl;
    logManager = new LogManager();
    cout << "logManager=" << *logManager << endl;
    try {
        createApplicationArguments(argc, argv);
        cout << "applicationArguments=" << *applicationArguments << endl;
        registerLogFile();
        cout << "log=" << *log << endl;
        const Log *filteredLog = filterLog();
        if (applicationArguments->GetDotFileName().empty()) {
            const vector<const DocumentHits *> *documentsHits = logManager->GetDocumentsHits(*filteredLog);

            cout << "docHits :" << logManager->GetDocumentsHits(*filteredLog) << endl;

            logManager->SortByHits(*documentsHits);
            showTopDocuments(*documentsHits, MAX_DOCUMENTS_SHOW);
            logManager->DeleteDocumentsHits(documentsHits);
        } else {
            generateDotFile(filteredLog);
        }
        delete filteredLog;
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
void Controller::createApplicationArguments(int argc, char **argv) {
    // TODO : Vérification de la validité de la commande (levée d'exception si pertinent)
    string testExtensionLogFile = argv[1];

    //instanciation sans options
    if (argc == 2 && testExtensionLogFile.find(".log") != string::npos) {
        string _logFileName = argv[1];
        bool _excludeExtensions = false;
        int _filterHour = -1;
        string _dotFileName = "";

        applicationArguments = new ApplicationArguments(_logFileName, _excludeExtensions, _filterHour, _dotFileName);
        // TODO : Instanciation de la classe ApplicationArguments (si commande valide)
    } else {
        cout << "Commande Erronée" << endl;
    }
}

/**
 * Importe les lignes du fichier de log puis instancie la classe LogFactory en passant au constructeur
 * l'ensemble des lignes du fichier de log lu pour récupérer ensuite l'instance de la classe Log. Cette dernière
 * sera stockée dans le contrôleur de l'application.
 */
void Controller::registerLogFile() {
    // TODO : Importation du fichier de log en unordened_set<string>
    // TODO : Instanciation de la classe Log
    const string _logFileName = applicationArguments->GetLogFileName();
    log = fileManager->ImportLogFile(_logFileName);
}

/**
 * Détermine quels types de filtrage doivent s'opérer sur l'instance de la classe Log se basant
 * sur les arguments d'exécution de l'application. Si au moins un filtrage a été exécuté, alors
 * une copie de la classe Log sera retournée, sinon l'instance de la classe Log du contrôleur
 * sera retournée.
 */
const Log *Controller::filterLog() const {
    const Log *excludedExtensionsLog = nullptr;
    const Log *finalLog = nullptr;
    if (applicationArguments->IsExcludeExtensions()) {
        vector<string> extensions(5);
        extensions.emplace_back(".css");
        extensions.emplace_back(".js");
        extensions.emplace_back(".png");
        extensions.emplace_back(".jpg");
        extensions.emplace_back(".gif");
        excludedExtensionsLog = logManager->FilterByExtensions(*log, extensions);
    }
    if (applicationArguments->GetFilterHour() != -1) {
        if (excludedExtensionsLog) {
            finalLog = logManager->FilterByHour(*excludedExtensionsLog, applicationArguments->GetFilterHour());
            delete excludedExtensionsLog;
        } else {
            finalLog = logManager->FilterByHour(*log, applicationArguments->GetFilterHour());
        }
    } else if (excludedExtensionsLog) {
        finalLog = excludedExtensionsLog;
    } else {
        finalLog = log;
    }
    return finalLog;
}

/**
 * Tri au préalable les associations entre un document et son nombre de hits par ordre décroissant du nombre
 * de hits. Ensuite, l'affichage se fait par lecture ordonnée des DocumentHits triés sur la sortie standard.
 */
void Controller::showTopDocuments(const vector<const DocumentHits *> &documentsHits, int max) const {
    // TODO : Affichage des n=max éléments dans l'ordre décroissant
    //faire logmanager

    cout << endl;
    cerr << "Non implémenté" << endl;
}

/**
 * // TODO : Spécifications à détailler
 */
void Controller::generateDotFile(const Log *_log) const {
    // TODO : Générer le fichier .dot à partir du log spécifié
    // Priorité : faible (spécifications à détailler)
}
