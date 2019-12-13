/*************************************************************************
Request  -  Représente une requête HTTP enregistrée dans le fichier de log importé
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
//------- Réalisation de la classe <Request> (fichier Request.cpp) -------

//---------------------------------------------------------------- INCLUDE
#include "Request.h"

//----------------------------------------------------------------- PUBLIC
/**
 * Créer l'instance de la classe à partir du document source et destination
 * spécifié ainsi que la date (copie de surface).
 *
 * @param source Le pointeur du document source de la requête
 * @param destination Le pointeur du document destination de la requête
 * @param time La date de la requête
 */
Request::Request(Document *source, Document *destination, time_t time)
        : srcDocument(source), destDocument(destination), date(time) {}

/**
 * Copie la requête en copiant également les documents sources et destination.
 *
 * @param request Une référence à la requête à copier
 */
Request::Request(const Request &request) {
    srcDocument = new Document(*request.GetSrcDocument());
    destDocument = new Document(*request.GetDestDocument());
    date = request.date;
}

/**
 * Détruit la requête en détruisant les documents source et destination.
 */
Request::~Request() {
    delete srcDocument;
    delete destDocument;
}