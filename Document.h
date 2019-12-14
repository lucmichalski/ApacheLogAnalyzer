/*************************************************************************
          Document - Représente un document identifié par une URL
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
//-------- Interface de la classe <Document> (fichier Document.h) --------
#if !defined ( DOCUMENT_H )
#define DOCUMENT_H
//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Document>
//  La classe document permet de représenter un document par son URL
//  correspondant à son identifiant uniquement sur le Web.
//------------------------------------------------------------------------

class Document {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /**
     * @return La référence sur l'URL du document
     */
    const string &GetURL() const {
        return URL;
    }

    /**
     * @return La chaîne représentant l'extension du document
     */
    string GetExtension();

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur d'un document.
     *
     * @param url Le pointeur sur l'URL du document à créer
     */
    explicit Document(string theURL) : URL(move(theURL)) {}

    /**
     * Constructeur par copie d'un document.
     * Comportement par défaut.
     *
     * @param document La référence du document à copier
     */
    Document(const Document &document) = default;

    /**
     * Destructeur du document.
     * Comportement par défaut.
     */
    virtual ~Document() = default;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string URL;
};

#endif // DOCUMENT_H
