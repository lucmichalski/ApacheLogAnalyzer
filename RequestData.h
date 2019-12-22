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
#ifndef APACHELOGANALYZER_REQUESTDATA_H
#define APACHELOGANALYZER_REQUESTDATA_H

#include <string>
#include <ctime>
#include "RequestVisitor.h"
#include "HTTPRequestData.h"

/**
 * RequestData contient l'ensemble des données de la requête associée (adresse IP, date, document ciblé,
 * navigateur utilisé, ...).
 * Son rôle est d'organiser les données lu de la ligne de requête importé du fichier de log lu afin de simplifier
 * leur exploitation au sein de l'application.
 */
class RequestData {
    // TODO : rendre les mutateurs privés mais friend avec la méthode créant le RequestData
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const RequestData &requestData);

    /**
     * @return L'adresse IPv4 du client de la requête HTTP
     */
    const std::string &GetClientAddress() const {
        return clientAddress;
    }

    /**
     * Définit l'adresse IPv4 du client de la requête HTTP.
     *
     * @param _clientAddress L'adresse IPv4 du client de la requête HTTP
     */
    void SetClientAddress(std::string _clientAddress) {
        clientAddress = move(_clientAddress);
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
     * @param _date La date de la requête HTTP
     */
    void SetDate(time_t _date) {
        date = _date;
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
     * @param _returnCode Le code status de la requête HTTP
     */
    void SetReturnCode(int _returnCode) {
        returnCode = _returnCode;
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
     * @param _answerSize La taille de la réponse HTTP en octet
     */
    void SetAnswerSize(int _answerSize) {
        answerSize = _answerSize;
    }

    /**
     * @return L'URL du Referer de la requête HTTP
     */
    const std::string &GetRefererUrl() const {
        return refererURL;
    }

    /**
     * Définit l'URL du Referer de la requête HTTP.
     *
     * @param _refererUrl L'URL du Referer de la requête HTTP
     */
    void SetRefererUrl(std::string _refererUrl) {
        refererURL = move(_refererUrl);
    }

    /**
     * @return Identifiants du navigateur utilisé lors de l'exécution de la requête
     */
    const std::string &GetBrowserId() const {
        return browserId;
    }

    /**
     * Définit les identifiants du navigateur utilisé lors de l'exécution de la requête.
     *
     * @param _browserId Les identifiants du navigateur utilisé lors de l'exécution de la requête
     */
    void SetBrowserId(std::string _browserId) {
        browserId = move(_browserId);
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
     * @param _requestVisitor Les informations sur le visiteur ayant exécuté la requête
     */
    void SetRequestVisitor(RequestVisitor _requestVisitor) {
        requestVisitor = _requestVisitor;
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
     * @param _httpRequestData Les informations HTTP sur la requête
     */
    void SetHttpRequestData(HTTPRequestData _httpRequestData) {
        httpRequestData = _httpRequestData;
    }

    /**
     * Constructeur par défaut du request data.
     * Comportement par défaut.
     */
    RequestData() = default;

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

protected:
    std::string clientAddress;
    time_t date = 0;
    int returnCode = 0;
    int answerSize = 0;
    std::string refererURL;
    std::string browserId;
    RequestVisitor requestVisitor;
    HTTPRequestData httpRequestData;
};

inline std::ostream &operator<<(std::ostream &os, const RequestData &requestData) {
    os << "RequestData{clientAddress=" << requestData.clientAddress
       << ", date=" << requestData.date
       << ", returnCode=" << requestData.returnCode
       << ", answerSize=" << requestData.answerSize
       << ", refererURL=" << requestData.refererURL
       << ", browserId=" << requestData.browserId
       << ", requestVisitor=" << requestData.requestVisitor
       << ", httpRequestData=" << requestData.httpRequestData
       << "}";
    return os;
}

#endif //APACHELOGANALYZER_REQUESTDATA_H
