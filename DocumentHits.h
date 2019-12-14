/*************************************************************************
    DocumentHits - Association entre un document et son nombre de hits
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
//---- Interface de la classe <DocumentHits> (fichier DocumentHits.h) ----
#ifndef APACHELOGANALYZER_DOCUMENTHITS_H
#define APACHELOGANALYZER_DOCUMENTHITS_H
//--------------------------------------------------- Interfaces utilisées
#include "Document.h"

//------------------------------------------------------------------------
// Rôle de la classe <DocumentHits>
//  DocumentHits est un conteneur associant un document à son nombre de
//  hits.
//------------------------------------------------------------------------

class DocumentHits {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    /**
     * @return La référence constante au document associé au nombre de hits
     */
    const Document &GetDocument() const {
        return document;
    }

    /**
     * @return Le nombre de hits associé au document
     */
    int GetNbHits() const {
        return nbHits;
    }

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur de l'association document - nombre de hits
     *
     * @param theDocument La référence au document à associer au nombre de hits
     * @param theNbHits Le nombre de hits du document associé
     */
    DocumentHits(const Document &theDocument, int theNbHits)
            : document(theDocument), nbHits(theNbHits) {}

    /**
     * Constructeur par copie.
     * Comportement par défaut.
     *
     * @param documentHits La référence au document hits à copier
     */
    DocumentHits(const DocumentHits &documentHits) = default;

    /**
     * Destructeur de l'instance de la classe.
     * Comportement par défaut.
     */
    virtual ~DocumentHits() = default;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    const Document &document;
    int nbHits = 0;
};

#endif //APACHELOGANALYZER_DOCUMENTHITS_H
