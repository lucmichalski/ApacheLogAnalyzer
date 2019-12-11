/*************************************************************************
						   LogAnalyzerService  -  description
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <LogAnalyzerService> ---------------
//------------------(fichier LogAnalyzerService.h) ---------------------
#if ! defined ( LOGANALYZERSERVICE_H )
#define LOGANALYZERSERVICE_H
//--------------------------------------------------- Interfaces utilisées
#include<iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum FileErrorType {EMPTY,MISSING,INVALID} FileErrorType;

//------------------------------------------------------------------------
// Rôle de la classe <LogAnalyzerService>
//
//------------------------------------------------------------------------

class LogAnalyzerService :
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

Collection<string> importLogFile(File logFile);
FileErrorType checkLogFileValidity(Collection<string>);

//------------------------------------------------- Surcharge d'opérateurs
	LogAnalyzerService & operator = ( 
		const LogAnalyzerService & unLogAnalyzerService );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	LogAnalyzerService ( 
		const LogAnalyzerService & unLogAnalyzerService );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	LogAnalyzerService ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~LogAnalyzerService ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LogAnalyzerService>
#endif // LOGANALYZERSERVICE_H
