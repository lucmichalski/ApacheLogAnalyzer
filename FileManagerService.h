/*************************************************************************
						   FileManagerService  -  description
							 -------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/
//Interface de la classe <FileManagerService> (fichier FileManagerService.h)
#if ! defined ( FILEMANAGERSERVICE_H )
#define FILEMANAGERSERVICE_H
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileManagerService>
//
//------------------------------------------------------------------------

class FileManagerService
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	Log ImportLogFile(string fileName);

	File CreateDotFile(Collection<Document> documents,
		Collection<Request> requests);

//------------------------------------------------- Surcharge d'opérateurs
	FileManagerService & operator = ( 
		const FileManagerService & unFileManagerService );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	FileManagerService ( const FileManagerService & unFileManagerService );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	FileManagerService ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~FileManagerService ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//Autres définitions dépendantes de <FileManagerService>
#endif // FILEMANAGERSERVICE_H
