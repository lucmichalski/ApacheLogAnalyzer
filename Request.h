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
#ifndef APACHELOGANALYZER_REQUEST_H
#define APACHELOGANALYZER_REQUEST_H

#include <ctime>
#include <sstream>
#include "Document.h"

/**
 * La classe Request représente une requête passée et stockée dans le fichier de log importé.
 * Elle a pour rôle d'associer un document source à un document destination pour une date donnée.
 */
class Request {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const Request &request);

    /**
     * @return La référence sur le document source de la requête HTTP.
     */
    const Document &GetSrcDocument() const {
        return srcDocument;
    }

    /**
     * @return La référence sur le document destination de la requête HTTP.
     */
    const Document &GetDestDocument() const {
        return destDocument;
    }

    /**
     * Retourne la date de la requête HTTP.
     *
     * @return La date de la requête HTTP.
     */
    const time_t GetDate() const {
        return date;
    }

    /**
     * Constructeur d'une requête HTTP.
     *
     * @param _srcDocument Le pointeur du document source de la requête
     * @param _destDocument Le pointeur du document destination de la requête
     * @param _date La date de la requête
     */
    Request(const Document &_srcDocument, const Document &_destDocument, time_t _date)
            : srcDocument(_srcDocument), destDocument(_destDocument), date(_date) {}

    /**
     * Constructeur par copie d'une requête HTTP.
     * Comportement par défaut.
     *
     * @param request Une référence à la requête à copier
     */
    Request(const Request &request) = default;

    /**
     * Destructeur d'une requête HTTP.
     * Comportement par défaut.
     */
    virtual ~Request() = default;

protected:
    const Document &srcDocument;
    const Document &destDocument;
    time_t date = 0;
};

inline std::ostream &operator<<(std::ostream &os, const Request &request) {
    os << "Request{srcDocument=" << request.srcDocument
       << ", destDocument=" << request.destDocument
       << ", date=" << request.date
       << "}";
    return os;
}

#endif //APACHELOGANALYZER_REQUEST_H
