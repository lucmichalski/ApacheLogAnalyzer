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

/**
 * Le rôle de la classe HTTPRequestData est en lien avec celui de la classe RequestData
 */
class HTTPRequestData {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const HTTPRequestData &httpRequestData);

    /**
     * @return La méthode HTTP de la requête
     */
    const std::string &GetMethod() const {
        return method;
    }

    /**
     * @return L'URL du document ciblé
     */
    const std::string &GetUrl() const {
        return URL;
    }

    /**
     * @return La version du protocole HTTP
     */
    const std::string &GetVersion() const {
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
    HTTPRequestData(std::string _method, std::string _URL, std::string _version)
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
    std::string method;
    std::string URL;
    std::string version;
};

inline std::ostream &operator<<(std::ostream &os, const HTTPRequestData &httpRequestData) {
    os << "HTTPRequestData{method=" << httpRequestData.method
       << ", URL=" << httpRequestData.URL
       << ", version=" << httpRequestData.version
       << "}";
    return os;
}

#endif //APACHELOGANALYZER_HTTPREQUESTDATA_H
