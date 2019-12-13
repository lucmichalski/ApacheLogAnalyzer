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
     * Retourne le pointeur sur l'URL du document.
     *
     * @return Le pointeur sur l'URL du document
     */
    inline const string *GetURL() const {
        return URL;
    }

    /**
     * Retourne le pointeur sur l'extension du document.
     *
     * @return Le pointeur sur l'extension du document
     */
    string *GetExtension();

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur d'un document.
     *
     * @param url Le pointeur sur l'URL du document à créer
     */
    Document(string *url);

    /**
     * Constructeur par copie d'un document.
     *
     * @param document La référence du document à copier
     */
    Document(const Document &document);

    /**
     * Destructeur du document.
     * La string de l'attribut URL est également détruit.
     */
    virtual ~Document();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string *URL;
};

#endif // DOCUMENT_H
