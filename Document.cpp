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
 * Analyse l'URL avec une Regex pour déterminer l'extension du document puis la retourne.
 *
 * @return La chaîne représentant l'extension du document
 */
string Document::GetExtension() {
    // TODO : Récupérer l'extension de l'URL du document
    return URL; // A remplacer...
}
