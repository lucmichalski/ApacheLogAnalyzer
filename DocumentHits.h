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
#ifndef APACHELOGANALYZER_DOCUMENTHITS_H
#define APACHELOGANALYZER_DOCUMENTHITS_H

#include "Document.h"

/**
 * DocumentHits est une classe associant un document à son nombre de hits.
 */
class DocumentHits {
public:
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

    /**
     * Constructeur de l'association document - nombre de hits
     *
     * @param _document La référence au document à associer au nombre de hits
     * @param _nbHits Le nombre de hits du document associé
     */
    DocumentHits(const Document &_document, int _nbHits)
            : document(_document), nbHits(_nbHits) {}

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

protected:
    const Document &document;
    int nbHits = 0;
};

#endif //APACHELOGANALYZER_DOCUMENTHITS_H
