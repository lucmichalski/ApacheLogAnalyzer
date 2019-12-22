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
#include <regex>
#include <stdexcept>

using namespace std;

/**
 * Parcours et analyse l'ensemble des lignes de log et créer progressivement
 * l'instance de la classe Log en créant également des instances de Request
 * et Document.
 */
Log *LogFactory::CreateLog(unordered_set<string *> *logLines) const {
    Log *log = new Log();
    // Parcours de l'ensemble des lignes du fichier de log lu
    for (const string *logLine : *logLines) {
        // Récupération des données de la ligne
        const RequestData *requestData = analyzeLogLine(*logLine);

        // On ne créer un document uniquement s'il n'existe pas déjà
        const Document *srcDocument = log->getDocument(requestData->GetRefererUrl());
        if (srcDocument == nullptr) {
            srcDocument = new Document(requestData->GetRefererUrl());
            log->addDocument(srcDocument);
        }
        const Document *destDocument = log->getDocument(requestData->GetHttpRequestData().GetUrl());
        if (destDocument == nullptr) {
            destDocument = new Document(requestData->GetHttpRequestData().GetUrl());
            log->addDocument(destDocument);
        }

        // Idem pour les requêtes
        const Request *request = log->getRequest(*srcDocument, *destDocument, requestData->GetDate());
        if (request == nullptr) {
            request = new Request(*srcDocument, *destDocument, requestData->GetDate());
            log->addRequest(request);
        }
        delete requestData;
    }
    return log;
}

/**
 * Créer une instance de la classe RequestData à partir des groupes générés par la Regex pour la lecture de ligne
 * du fichier de log importé.
 */
const RequestData *LogFactory::analyzeLogLine(const string &logLine) const {
    regex rgx(
        R"lit(^(\d{1,3}(?:.\d{1,3}){3})\s(\S*)\s(\S*)\s\[(.*)\]\s"(\S*)\s(\S*)\s(\S*)"\s(\d*)\s(\d*)\s"(\S*)"\s"(.*)")lit");
    smatch matches;
    if (regex_search(logLine, matches, rgx)) {
        RequestData *requestData = new RequestData();
        string clientAddrress = matches[0].str();
        string userLogName = matches[1].str();
        string userName = matches[2].str();
        string dateStr = matches[3].str();
        string method = matches[4].str();
        string URL = matches[5].str();
        string version = matches[6].str();
        string returnCode = matches[7].str();
        string answerSize = matches[8].str();
        string refererURL = matches[9].str();
        string browserId = matches[10].str();

        RequestVisitor requestVisitor(userLogName, userName);
        HTTPRequestData httpRequestData(method, URL, version);
        Date date = createDate(dateStr);

        requestData->setClientAddress(clientAddrress);
        requestData->setRequestVisitor(requestVisitor);
        requestData->setDate(date);
        requestData->setReturnCode(stoi(returnCode));
        requestData->setAnswerSize(stoi(answerSize));
        requestData->setRefererUrl(refererURL);
        requestData->setBrowserId(browserId);
        return requestData;
    } else {
        throw runtime_error("Lecture du fichier impossible : format des lignes incorrect.");
    }
}

Date LogFactory::createDate(std::string &dateStr) const {
    string monthsStr[12] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    regex rgx(R"(^(\d{2})\/(\S{3})\/(\d{4})\:(\d{2})\:(\d{2})\:(\d{2})\s(\S\d{4})$)");
    smatch matches;

    if (regex_search(dateStr, matches, rgx)) {
        string rgxYear = matches[2].str();
        string rgxMonth = matches[1].str();
        string rgxDay = matches[0].str();
        string rgxHour = matches[3].str();
        string rgxMinute = matches[4].str();
        string rgxSecond = matches[5].str();
        string rgxTimeSlot = matches[6].str();
        int i;
        for (i = 0; i < 12; ++i) {
            if (monthsStr[i] == matches[1].str()) {
                break;
            }
        }
        int year = stoi(rgxYear);
        int month = i;
        int day = stoi(rgxDay);
        int hour = stoi(rgxHour);
        int minute = stoi(rgxMinute);
        int second = stoi(rgxSecond);
        int timeSlot = stoi(rgxTimeSlot);
        return {year, month, day, hour, minute, second, timeSlot};
    } else {
        throw runtime_error("Lecture du fichier impossible : format des lignes incorrect.");
    }
}
