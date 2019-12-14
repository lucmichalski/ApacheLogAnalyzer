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
#ifndef APACHELOGANALYZER_HTTPREQUESTDATA_H
#define APACHELOGANALYZER_HTTPREQUESTDATA_H

#include <string>

using namespace std;

/**
 * Le rôle de la classe HTTPRequestData est en lien avec celui de la classe RequestData
 */
class HTTPRequestData {
public:
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

    /**
     * Constructeur par défaut du HTTP request data
     * Comportement par défaut.
     */
    HTTPRequestData() = default;

    /**
     * Constructeur du HTTP request data
     *
     * @param _method La méthode HTTP de la requête
     * @param _URL L'URL du document ciblé
     * @param _version La version du protocole HTTP
     */
    HTTPRequestData(string _method, string _URL, string _version)
            : method(move(_method)), URL(move(_URL)), version(move(_version)) {}

    /**
     * Constructeur par copie du HTTP request data.
     * Aucune action spécifique effectuée.
     *
     * @param httpRequestData La référence à l'HTTP request data à copier
     */
    HTTPRequestData(const HTTPRequestData &httpRequestData) = default;

    /**
     * Destructeur du request HTTP request data.
     * Aucune action spécifique effectuée.
     */
    virtual ~HTTPRequestData() = default;

protected:
    string method;
    string URL;
    string version;
};

#endif //APACHELOGANALYZER_HTTPREQUESTDATA_H
