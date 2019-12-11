/*************************************************************************
						   LogFactory.h  -  Classe virtuelle
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogFactory> (fichier LogFactory.h) --------
#if ! defined ( LOGFACTORY_H )
#define LOGFACTORY_H
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogFactory>
//Cette classe virtuelle permet de gérer les classes LogFactoryImpl, Log,
//Request, Document
//------------------------------------------------------------------------
class LogFactory :
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	virtual void Methode () const = 0;

//------------------------------------------------- Surcharge d'opérateurs
	LogFactory & operator = ( const LogFactory & unLogFactory );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	LogFactory ( const LogFactory & unLogFactory );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	LogFactory ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~LogFactory ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LogFactory>
#endif // LOGFACTORY_H
