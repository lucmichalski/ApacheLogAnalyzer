/*************************************************************************
						   Request  -  description
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <Request> (fichier Request.h) ----------------
#if ! defined ( REQUEST_H )
#define REQUEST_H
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//
//------------------------------------------------------------------------

class Request : public Ancetre
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
	Request & operator = ( const Request & unRequest );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Request ( const Request & unRequest );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Request ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Request ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Request>
#endif // REQUEST_H
