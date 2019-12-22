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
#include "DocumentHits.h"

/**
 * LogManager met à disposition un ensemble de services permettant de gérer tout l'aspect traitement
 * des logs importés de l'application (filtrage, tri par nombre de hits, etc).
 */
class LogManager {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend ostream &operator<<(ostream &os, const LogManager &logManager);

    /**
     * Créer une copie de l'instance de la classe Log spécifiée puis applique un filtrage sur
     * les requêtes en excluant les extensions des documents avant de retourner la copie.
     *
     * @param _log L'instance de la classe Log correspondant au fichier de log importé
     * @return La copie de l'instance de la classe Log spécifiée filtrée sur les extensions
     */
    const Log *FilterByExtensions(const Log &_log, const vector<string> &extensions) const;

    /**
     * Créer une copie de l'instance de la classe Log spécifiée puis applique un filtrage dessus
     * en excluant les requêtes dont l'heure enregistrée n'est pas incluse dans le créneau horaire
     * [hour, hour + 1[.
     *
     * @param _log L'instance de la classe Log correspondant au fichier de log importé
     * @param hour Le créneaux horaire sur lequel le filtrage doit se baser
     * @return La copie de l'instance de la classe Log spécifiée filtrée sur le créneau horaire
     * @throws exception Si le paramètre hour n'est pas inclus dans l'ensemble [0,23]
     */
    const Log *FilterByHour(const Log &_log, int hour) const;

    /**
     * Construit un vecteur d'association entre un document et son nombre de hits et le retourne.
     * Les pointeurs du vecteurs peuvent être modifiés pour pouvoir le trier par exemple mais aucun
     * d'entre eux ne devrait être retiré de la collection.
     *
     * @param log L'instance de la classe Log représentant le fichier de log importé
     * @return Un vecteur d'association entre un document et son nombre de hits
     */
    const vector<const DocumentHits *> *GetDocumentsHits(const Log &log) const;

    /**
     * Détruit le vecteur ainsi que les associations entre un document et son nombre de hits DocumentHits
     * contenus dans le vecteur.
     *
     * @param documentsHits Le vecteur d'associations entre un document et son nombre de hits
     */
    void DeleteDocumentsHits(const vector<const DocumentHits *> *documentsHits) const;

    /**
     * Tri le vecteur d'associations entre un document et son nombre de hits par ordre décroissant du nombre
     * de hits.
     *
     * @param documentsHits La vecteur d'associations entre un document et son nombre de hits
     * @return Le pointeur sur le vecteur passé en paramètre trié
     */
    const vector<const DocumentHits *> *SortByHits(const vector<const DocumentHits *> &documentsHits) const;

    /**
     * // TODO : Spécifications à détailler !
     *
     * @param log
     * @param request
     * @return
     */
    int CountTimelessRequestsEquals(const Log &log, const Request &request) const;
};

inline ostream &operator<<(ostream &os, const LogManager &logManager) {
    os << "LogManager{}";
    return os;
}


#endif //APACHELOGANALYZER_LOGMANAGER_H
