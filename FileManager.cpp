/*************************************************************************
						   FileManager  -  description
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <FileManager> (fichier FileManager.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;
//------------------------------------------------------ Include personnel
#include "FileManagerService.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FileManager::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
FileManager::Log ImportLogFile(fileName: string);
	
FileManager::File CreateDotFile(documents: Collection<Document>,
		requests: Collection<Request>);	

//------------------------------------------------- Surcharge d'opérateurs
FileManager & FileManager::operator = ( const FileManager & unFileManager )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
FileManager::FileManager ( const FileManager & unFileManager )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <FileManager>" << endl;
#endif
} //----- Fin de FileManager (constructeur de copie)

FileManager::FileManager ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <FileManager>" << endl;
#endif
} //----- Fin de FileManager

FileManager::~FileManager ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <FileManager>" << endl;
#endif
} //----- Fin de ~FileManager

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
UnorderedSet<string> extractLogLines(File logFile);
