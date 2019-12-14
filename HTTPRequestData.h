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

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur du HTTP request data
     *
     * @param theMethod La méthode HTTP de la requête
     * @param theURL L'URL du document ciblé
     * @param theVersion La version du protocole HTTP
     */
    inline HTTPRequestData(string theMethod, string theURL, string theVersion)
    : method(theMethod), URL(theURL), version(theVersion) {}

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
