/*************************************************************************
						   FileAnalyzerServiceImpl  -  Parcours le fichier de log et
							 renvoie une collection de string contenant chaque ligne de log
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <FileAnalyzerServiceImpl>---------- 
//-------------------(fichier FileAnalyzerServiceImpl.cpp) --------------
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
//------------------------------------------------------ Include personnel
#include "FileAnalyzerServiceImpl.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
using namespace std;
//----------------------------------------------------- Méthodes publiques
// type FileAnalyzerServiceImpl::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
FileAnalyzerServiceImpl & FileAnalyzerServiceImpl::operator = ( 
	const FileAnalyzerServiceImpl & unFileAnalyzerServiceImpl )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
FileAnalyzerServiceImpl::FileAnalyzerServiceImpl ( 
	const FileAnalyzerServiceImpl & unFileAnalyzerServiceImpl )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <FileAnalyzerServiceImpl>" << endl;
#endif
} //----- Fin de FileAnalyzerServiceImpl (constructeur de copie)

FileAnalyzerServiceImpl::FileAnalyzerServiceImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <FileAnalyzerServiceImpl>" << endl;
#endif
} //----- Fin de FileAnalyzerServiceImpl

FileAnalyzerServiceImpl::~FileAnalyzerServiceImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <FileAnalyzerServiceImpl>" << endl;
#endif
} //----- Fin de ~FileAnalyzerServiceImpl

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
