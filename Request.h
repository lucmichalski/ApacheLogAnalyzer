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
//--------- Interface de la classe <Request> (fichier Request.h) ---------
#if !defined ( REQUEST_H )
#define REQUEST_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include "Document.h"

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//  La classe Request représente une requête passée et stockée dans le
//  fichier de log importé. Elle a pour rôle d'associer un document source
//  à un document destination pour une date donnée.
//------------------------------------------------------------------------

class Request {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
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

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur d'une requête HTTP.
     *
     * @param source Le pointeur du document source de la requête
     * @param destination Le pointeur du document destination de la requête
     * @param time La date de la requête
     */
    Request(const Document &source, const Document &destination, time_t time)
            : srcDocument(source), destDocument(destination), date(time) {}

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

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    const Document &srcDocument;
    const Document &destDocument;
    time_t date = 0;
};

#endif // REQUEST_H
