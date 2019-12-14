/*************************************************************************
            RequestData - Représente les données d'une requête
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
//----- Interface de la classe <RequestData> (fichier RequestData.h) -----
#ifndef APACHELOGANALYZER_REQUESTDATA_H
#define APACHELOGANALYZER_REQUESTDATA_H
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
#include "RequestVisitor.h"
#include "HTTPRequestData.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <RequestData>
//  RequestData contient l'ensemble des données de la requête associée
//  (adresse IP, date, document ciblé, navigateur utilisé, ...).
//  Son rôle est d'organiser les données lu de la ligne de requête importé
//  du fichier de log lu afin de simplifier leur exploitation au sein
//  de l'application.
//------------------------------------------------------------------------

class RequestData {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    // TODO : rendre les mutateurs privés mais friend avec la méthode créant le RequestData
    /**
     * @return L'adresse IPv4 du client de la requête HTTP
     */
    const string &GetClientAddress() const {
        return clientAddress;
    }

    /**
     * Définit l'adresse IPv4 du client de la requête HTTP.
     *
     * @param theClientAddress L'adresse IPv4 du client de la requête HTTP
     */
    void SetClientAddress(string theClientAddress) {
        clientAddress = move(theClientAddress);
    }

    /**
     * @return La date de la requête HTTP
     */
    time_t GetDate() const {
        return date;
    }

    /**
     * Définit la date de la requête HTTP.
     *
     * @param theDate La date de la requête HTTP
     */
    void SetDate(time_t theDate) {
        date = theDate;
    }

    /**
     * @return Le code status de la requête HTTP
     */
    int GetReturnCode() const {
        return returnCode;
    }

    /**
     * Définit le code status de la requête HTTP.
     *
     * @param theReturnCode Le code status de la requête HTTP
     */
    void SetReturnCode(int theReturnCode) {
        returnCode = theReturnCode;
    }

    /**
     * @return La taille de la réponse HTTP en octet
     */
    int GetAnswerSize() const {
        return answerSize;
    }

    /**
     * Définit la taille de la réponse HTTP en octet.
     *
     * @param theAnswerSize La taille de la réponse HTTP en octet
     */
    void SetAnswerSize(int theAnswerSize) {
        answerSize = theAnswerSize;
    }

    /**
     * @return L'URL du Referer de la requête HTTP
     */
    const string &GetRefererUrl() const {
        return refererURL;
    }

    /**
     * Définit l'URL du Referer de la requête HTTP.
     *
     * @param theRefererUrl L'URL du Referer de la requête HTTP
     */
    void SetRefererUrl(string theRefererUrl) {
        refererURL = move(theRefererUrl);
    }

    /**
     * @return Identifiants du navigateur utilisé lors de l'exécution de la requête
     */
    const string &GetBrowserId() const {
        return browserId;
    }

    /**
     * Définit les identifiants du navigateur utilisé lors de l'exécution de la requête.
     *
     * @param theBrowserId Les identifiants du navigateur utilisé lors de l'exécution de la requête
     */
    void SetBrowserId(string theBrowserId) {
        browserId = move(theBrowserId);
    }

    /**
     * @return Les informations sur le visiteur ayant exécuté la requête
     */
    const RequestVisitor &GetRequestVisitor() const {
        return requestVisitor;
    }

    /**
     * Définit les informations sur le visiteur ayant exécuté la requête.
     *
     * @param theRequestVisitor Les informations sur le visiteur ayant exécuté la requête
     */
    void SetRequestVisitor(RequestVisitor theRequestVisitor) {
        requestVisitor = theRequestVisitor;
    }

    /**
     * @return Les informations HTTP sur la requête
     */
    const HTTPRequestData &GetHttpRequestData() const {
        return httpRequestData;
    }

    /**
     * Définit les informations HTTP sur la requête.
     *
     * @param theHttpRequestData Les informations HTTP sur la requête
     */
    void SetHttpRequestData(HTTPRequestData theHttpRequestData) {
        httpRequestData = theHttpRequestData;
    }

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur par copie du request data.
     * Aucune action spécifique effectuée.
     *
     * @param requestData La référence au request data à copier
     */
    RequestData(const RequestData &requestData) = default;

    /**
     * Destructeur du request data.
     * Aucune action spécifique effectuée.
     */
    virtual ~RequestData() = default;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string clientAddress;
    time_t date = 0;
    int returnCode = 0;
    int answerSize = 0;
    string refererURL;
    string browserId;
    RequestVisitor requestVisitor;
    HTTPRequestData httpRequestData;
};

#endif //APACHELOGANALYZER_REQUESTDATA_H
