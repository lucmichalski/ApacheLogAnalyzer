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
//------ Réalisation de la classe <Document> (fichier Document.cpp) ------

//---------------------------------------------------------------- INCLUDE
#include "Document.h"

//----------------------------------------------------------------- PUBLIC
/**
 * Créer une extension
 *
 * @return Le pointeur sur l'extension du document
 */
string *Document::GetExtension() {
    // TODO : Récupérer l'extension de l'URL du document
    return new string(*URL); // A remplacer....
}

/**
 * Créer l'instance de la classe Document à partir du pointeur sur
 * la string de l'URL associée (copie de surface).
 *
 * @param url Le pointeur sur une string de l'URL du document à instancier
 */
Document::Document(string *url) : URL(url) {}

/**
 * Copie le document dans une nouvelle instance avec une copie en profondeur
 * de l'attribut URL.
 *
 * @param document Une référence au document à copier
 */
Document::Document(const Document &document) {
    URL = new string(*document.GetURL());
}

/**
 * Détruit l'instance en détruisant l'attribut URL.
 */
Document::~Document() {
    delete URL;
}
