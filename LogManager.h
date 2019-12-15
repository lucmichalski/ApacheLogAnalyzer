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
#ifndef APACHELOGANALYZER_LOGMANAGER_H
#define APACHELOGANALYZER_LOGMANAGER_H

#include "Log.h"

/**
 * LogManager met à disposition un ensemble de services permettant de gérer tout l'aspect traitement
 * des logs importés de l'application (filtrage, tri par nombre de hits, etc).
 */
class LogManager {
public:
    const Log *filterByExtensions(const Log &_log);

    const Log *filterByHour(const Log &_log, int hour);
protected:
};


#endif //APACHELOGANALYZER_LOGMANAGER_H
