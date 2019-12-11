/*************************************************************************
						   Document  -  description
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <Document> (fichier Document.h) ----------------
#if ! defined ( DOCUMENT_H )
#define DOCUMENT_H
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Document>
//
//------------------------------------------------------------------------

class Document : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
	Document & operator = ( const Document & unDocument );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Document ( const Document & unDocument );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Document ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Document ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Document>
#endif // DOCUMENT_H
