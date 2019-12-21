/*************************************************************************
				Log - Représente le fichier de log importé
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
							- Milène DAUGAN
							- Loïc DUBOIS-TERMOZ
	e-mail               :
							- milene.daugan@insa-lyon.fr
							- loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#ifndef APACHELOGANALYZER_LOG_H
#define APACHELOGANALYZER_LOG_H

#include <unordered_set>
#include "Request.h"

using namespace std;

/**
 * La classe Log représente le fichier de log importé en étant associé à la liste des
 * requêtes Request et la liste des documents Document.
 */
class Log {
public:
	/**
	 * @return Le pointeur sur l'ensemble des requêtes du log
	 */
	const unordered_set<const Request *> *GetRequests() const {
		return requests;
	}

	/**
	 * @return Le pointeur sur l'ensemble des documents du log
	 */
	const unordered_set<const Document *> *GetDocuments() const {
		return documents;
	}

	/**
	 * Constructeur du log.
	 * Initialise les ensembles de requêtes et de documents.
	 */
	Log();

	/**
	 * Constructeur par copie du log.
	 * Copie en profondeur des ensembles de requêtes et de documents.
	 *
	 * @param log La référence au log à copier
	 */
	Log(const Log &log);

	/**
	 * Destructeur du log.
	 * Détruit les ensembles de requêtes et de documents.
	 */
	virtual ~Log();

protected:
	friend class LogFactory;

	/**
	 * Ajoute une requête au Log.
	 *
	 * @param request La référence à la requête à ajouter
	 */
	void addRequest(const Request *request) {
		requests->insert(request);
	}

	/**
	 * Ajoute un document au Log.
	 *
	 * @param document La référence au document à ajouter
	 */
	void addDocument(const Document *document) {
		documents->insert(document);
	}

	/**
	 * Cherche et retourne le pointeur du document associé à l'URL passé en paramètre s'il existe, nullptr sinon.
	 *
	 * @param URL La référence à l'URL du document à rechercher
	 * @return Le pointeur du document associé à l'URL s'il existe, nullptr sinon
	 */
	const Document *getDocument(const string &URL) const;

	/**
	 * Cherche et retourne le pointeur sur la requête associée aux paramètres spécifiés si elle existe, nullptr sinon
	 *
	 * @param srcDocument Le document source de la requête
	 * @param destDocument Le document destination de la requête
	 * @param date La date de la requête
	 * @return Le pointeur sur la requête si elle existe, nullptr sinon
	 */
	const Request *getRequest(const Document &srcDocument, const Document &destDocument, time_t date) const;

	// TODO : Pointeur constant

	unordered_set<const Request *> *requests = nullptr;
	unordered_set<const Document *> *documents = nullptr;
};

#endif //APACHELOGANALYZER_LOG_H
