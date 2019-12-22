/*************************************************************************
			LogManager - Service sur le traitement d'un log
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
							- Milène DAUGAN
							- Loïc DUBOIS-TERMOZ
	e-mail               :
							- milene.daugan@insa-lyon.fr
							- loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#include "LogManager.h"

using namespace std;

/**
 * Créer une copie de l'instance de la classe Log spécifiée puis compare les extensions des documents source
 * et destination et de chaque requête avec les extensions passées en paramètre. La requête est retirée de
 * la copie de l'instance de la classe Log si l'une des extensions des documents correspond.
 */
const Log *LogManager::FilterByExtensions(const Log &_log, const vector<string> &extensions) const {
    // TODO : Clonage du Log + Filtrage sur les extensions listés
    return nullptr;
}

/**
 * Créer une copie de l'instance de la classe Log spécifiée puis vérifie la validité du paramètre hour.
 * Si le paramètre n'est pas compris dans l'interval [0,23], alors une exception est levée.
 * Sinon compare les heures des requêtes avec l'heure spécifiée. Si les heures ne sont pas égales, alors
 * la requête est retirée de la copie de l'instance de la classe Log.
 */
const Log *LogManager::FilterByHour(const Log &_log, int hour) const {
    // TODO : Clonage du Log + Filtrage sur l'heure spécifiée
    return nullptr;
}

/**
 * Initialise un vecteur de la taille du nombre de documents stockés dans l'instance de la classe Log puis
 * le remplit d'associations entre un document et son nombre de hits via les requêtes enregistrées.
 */
const vector<const DocumentHits *> *LogManager::GetDocumentsHits(const Log &log) const {
    // TODO : Construire un vecteur de taille le nombre de documents du Log puis le remplir
    vector<const DocumentHits *> *documentsHits = new vector<const DocumentHits *>(log.GetDocuments()->size());

    for (const Document *const document : *log.GetDocuments()) {
        int nbHits = 0;
        for (const Request *const request : *log.GetRequests()) {
            if (request->GetDestDocument() == *document) {
                ++nbHits;
            }
        }
        documentsHits->push_back(new DocumentHits(*document, nbHits));
    }
    return documentsHits;
}

/**
 * Détruit l'ensemble des instances de la classe DocumentHits avant de détuire le vecteur.
 */
void LogManager::DeleteDocumentsHits(const vector<const DocumentHits *> *documentsHits) const {
    // TODO : Destruction du vecteur ainsi que les DocumentHits contenus
}

/**
 * Pour chaque document, compte le nombre d'occurence du document en comparant les documents source
 * et destination de chaque requête avec ce premier. Le programme créer ensuite une instance de la classe
 * DocumentHits à partir du nombre de hits et du document et le stock dans le vecteur correspondant.
 * Une fois le traitement terminé, le vecteur est retourné.
 */
const vector<const DocumentHits *> *LogManager::SortByHits(const vector<const DocumentHits *> &documentsHits) const {
    // TODO : Tri du vecteur par ordre décroissant du nombre de hits (se baser sur la STL si possible)
    return nullptr;
}

/**
 * // TODO : Spécifications à détailler !
 */
int LogManager::CountTimelessRequestsEquals(const Log &log, const Request &request) const {
    // TODO : Déterminer la pondération de la requête à partir de l'instance de la classe Log spécifiée
    return 0;
}
