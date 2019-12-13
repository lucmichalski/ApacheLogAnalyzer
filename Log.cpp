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
//----------- Réalisation de la classe <Log> (fichier Log.cpp) -----------

//---------------------------------------------------------------- INCLUDE
#include "Log.h"

//----------------------------------------------------------------- PUBLIC
/**
 * Initialise les ensembles de requêtes et de documents.
 */
Log::Log() {
    requests = new unordered_set<Request>();
    documents = new unordered_set<Document>();
}

/**
 * Copie les ensembles du log spécifié dans le log en création.
 *
 * @param log La référence au log à copier
 */
Log::Log(const Log &log) {
    requests = new unordered_set<Request>(*log.requests);
    documents = new unordered_set<Document>(*log.documents);
}

/**
 * Détruit le log en détruisant les ensembles de requêtes et de documents.
 */
Log::~Log() {
    delete requests;
    delete documents;
}