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
 * Retourne l'extension du document déterminé à partir de son URL.
 *
 * @return Le pointeur sur l'extension du document
 */
string *Document::GetExtension() {
    // TODO : Récupérer l'extension de l'URL du document
    return new string(URL); // A remplacer...
}
