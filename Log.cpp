/*************************************************************************
            Log  -  Représente le fichier de log importé
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#include <sstream>
#include "Log.h"

using namespace std;

/**
 * Initialise les ensembles de requêtes et de documents.
 */
Log::Log() {
    requests = new unordered_set<const Request *>();
    documents = new unordered_set<const Document *>();
}

/**
 * Copie les ensembles du log spécifié dans le log en création.
 * Seuls les pointeurs des éléments des ensembles sont copiés.
 */
Log::Log(const Log &log) {
    documents = new unordered_set<const Document *>();
    for (const Document *document : *(log.documents)) {
        const Document *copyDocument = new Document(*document);
        documents->insert(copyDocument);
    }

    requests = new unordered_set<const Request *>();
    for (const Request *request : *(log.requests)) {
        const Document *copySrcDocument = getDocument(request->GetSrcDocument().GetURL());
        const Document *copyDestDocument = getDocument(request->GetDestDocument().GetURL());
        const Request *copyRequest = new Request(*copySrcDocument, *copyDestDocument, request->GetDate());
        requests->insert(copyRequest);
    }
}

/**
 * Détruit le log en détruisant les ensembles de requêtes et de documents ainsi que leur contenu
 */
Log::~Log() {
    for (const Request *request : *requests) {
        delete request;
    }
    delete requests;

    for (const Document *document : *documents) {
        delete document;
    }
    delete documents;
}

/**
 * Parcours l'ensemble des documents du Log pour trouver une correspondance avec l'URL spécifiée en paramètre.
 */
const Document *Log::getDocument(const string &URL) const {
    for (const Document *document : *documents) {
        if (document->GetURL() == URL) {
            return document;
        }
    }
    return nullptr;
}

/**
 * Parcours l'ensemble des requêtes du Log pour trouver une correspondance avec les paramètres spécifiés.
 */
const Request *Log::getRequest(const Document &srcDocument, const Document &destDocument, time_t date) const {
    for (const Request *request : *requests) {
        if (request->GetSrcDocument() == srcDocument
            && request->GetDestDocument() == destDocument
            && request->GetDate() == date) {
            return request;
        }
    }
    return nullptr;
}