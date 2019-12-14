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
//- Interface de la classe <HTTPRequestData> (fichier HTTPRequestData.h) -
#ifndef APACHELOGANALYZER_HTTPREQUESTDATA_H
#define APACHELOGANALYZER_HTTPREQUESTDATA_H
//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <RequestVisitor>
//  En lien avec le rôle de la classe RequestData
//------------------------------------------------------------------------

class HTTPRequestData {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    /**
     * @return La méthode HTTP de la requête
     */
    const string &GetMethod() const {
        return method;
    }

    /**
     * @return L'URL du document ciblé
     */
    const string &GetUrl() const {
        return URL;
    }

    /**
     * @return La version du protocole HTTP
     */
    const string &GetVersion() const {
        return version;
    }

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur par défaut du HTTP request data
     * Comportement par défaut.
     */
    HTTPRequestData() = default;

    /**
     * Constructeur du HTTP request data
     *
     * @param theMethod La méthode HTTP de la requête
     * @param theURL L'URL du document ciblé
     * @param theVersion La version du protocole HTTP
     */
    HTTPRequestData(string theMethod, string theURL, string theVersion)
            : method(move(theMethod)), URL(move(theURL)), version(move(theVersion)) {}

    /**
     * Constructeur par copie du HTTP request data.
     * Aucune action spécifique effectuée.
     *
     * @param requestData La référence à l'HTTP request data à copier
     */
    HTTPRequestData(const HTTPRequestData &httpRequestData) = default;

    /**
     * Destructeur du request HTTP request data.
     * Aucune action spécifique effectuée.
     */
    virtual ~HTTPRequestData() = default;

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
    string method;
    string URL;
    string version;
};

#endif //APACHELOGANALYZER_HTTPREQUESTDATA_H
