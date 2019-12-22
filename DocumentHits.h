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

#include <sstream>
#include "Document.h"

/**
 * DocumentHits est une classe associant un document à son nombre de hits.
 */
class DocumentHits {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const DocumentHits &documentHits);

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

inline std::ostream &operator<<(std::ostream &os, const DocumentHits &documentHits) {
    os << "DocumentHits{document=" << documentHits.document << ", nbHits=" << documentHits.nbHits << "}";
    return os;
}

#endif //APACHELOGANALYZER_DOCUMENTHITS_H
