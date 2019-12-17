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
#ifndef APACHELOGANALYZER_DOCUMENT_H
#define APACHELOGANALYZER_DOCUMENT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * La classe document permet de représenter un document par son URL correspondant
 * à son identifiant uniquement sur le Web.
 */
class Document {
public:
    /**
     * Opérateur d'égalité. Test si le document courant et le document passé en paramètre
     * sont égaux (comparaison des URLs).
     *
     * @param document Le second document de comparaison
     * @return "true" si les deux documents sont égaux, "false" sinon
     */
    bool operator==(const Document &document) const {
        return GetURL() == document.GetURL();
    }

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

    /**
     * Constructeur d'un document.
     *
     * @param url Le pointeur sur l'URL du document à créer
     */
    explicit Document(string _URL) : URL(move(_URL)) {}

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

protected:
    string URL;
};

#endif //APACHELOGANALYZER_DOCUMENT_H
