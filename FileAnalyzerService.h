/*************************************************************************
						   FileAnalyzerService  -  description
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <FileAnalyzerService> --------------
//-----------------(fichier FileAnalyzerService.h) ---------------------
#if ! defined ( FileAnalyzerService_H )
#define FileAnalyzerService_H
//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileAnalyzerService>
//
//------------------------------------------------------------------------

class FileAnalyzerService : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
Collection<string> splitFileToLines(File logFile);
void createDotFile(string dotFilePath);
//------------------------------------------------- Surcharge d'opérateurs
	FileAnalyzerService & operator = ( 
		const FileAnalyzerService & unFileAnalyzerService );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	FileAnalyzerService ( const FileAnalyzerService & unFileAnalyzerService );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	FileAnalyzerService ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~FileAnalyzerService ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//------------------ Autres définitions dépendantes de <FileAnalyzerService>
#endif // FileAnalyzerService_H
