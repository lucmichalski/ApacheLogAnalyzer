/*************************************************************************
                  LogFactory - Fabrique de la classe Log
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#include "LogFactory.h"

/**
 * Parcours et analyse l'ensemble des lignes de log et créer progressivement
 * l'instance de la classe Log en créant également des instances de Request
 * et Document.
 */
Log *LogFactory::CreateLog(unordered_set<string *> *logLines) const {
    Log *log = new Log();
    for (const string *logLine : *logLines) {
        const RequestData requestData = analyzeLogLine(*logLine);
        const Document *srcDocument = log->getDocument(requestData.GetRefererUrl());
        if (srcDocument == nullptr) {
            srcDocument = new Document(requestData.GetRefererUrl());
            log->addDocument(srcDocument);
        }
        const Document *destDocument = log->getDocument(requestData.GetHttpRequestData().GetUrl());
        if (destDocument == nullptr) {
            destDocument = new Document(requestData.GetHttpRequestData().GetUrl());
            log->addDocument(destDocument);
        }
        const Request *request = log->getRequest(*srcDocument, *destDocument, requestData.GetDate());
        if (request == nullptr) {
            request = new Request(*srcDocument, *destDocument, requestData.GetDate());
            log->addRequest(request);
        }
    }
    return log;
}

/**
 * Créer une instance de la classe RequestData à partir des groupes générés par la Regex pour la lecture de ligne
 * du fichier de log importé.
 */
const RequestData LogFactory::analyzeLogLine(const string &logLine) const {
    RequestData requestData;
    // TODO : Regex
    return requestData;
}
