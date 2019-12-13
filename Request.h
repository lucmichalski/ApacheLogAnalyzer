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
     * Retourne un pointeur sur le document source de la requête HTTP.
     *
     * @return Le pointeur sur le document source de la requête HTTP.
     */
    inline const Document *GetSrcDocument() const {
        return srcDocument;
    }

    /**
     * Retourne le pointeur sur le document destination de la requête HTTP.
     *
     * @return Le pointeur sur le document destination de la requête HTTP.
     */
    inline const Document *GetDestDocument() const {
        return destDocument;
    }

    /**
     * Retourne la date de la requête HTTP.
     *
     * @return La date de la requête HTTP.
     */
    inline const time_t &GetDate() const {
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
    Request(Document *source, Document *destination, time_t time);

    /**
     * Constructeur par copie d'une requête HTTP.
     * Les documents pointés sont également copiés.
     *
     * @param request Une référence à la requête à copier
     */
    Request(const Request &request);

    /**
     * Destructeur d'une requête HTTP.
     * Les documents pointés sont également détruits.
     */
    virtual ~Request();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Document *srcDocument;
    Document *destDocument;
    time_t date;
};

#endif // REQUEST_H
