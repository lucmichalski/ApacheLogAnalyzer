/*************************************************************************
						   LogAnalyzerServiceImpl  -  Importe le fichier de log et teste
							 sa validité.
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <LogAnalyzerServiceImpl> ------------
////-------------- (fichier LogAnalyzerServiceImpl.cpp) -------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "LogAnalyzerServiceImpl.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogAnalyzerServiceImpl::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
LogAnalyzerServiceImpl & LogAnalyzerServiceImpl::operator = (
	 const LogAnalyzerServiceImpl & unLogAnalyzerServiceImpl )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
LogAnalyzerServiceImpl::LogAnalyzerServiceImpl ( 
	const LogAnalyzerServiceImpl & unLogAnalyzerServiceImpl )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <LogAnalyzerServiceImpl>" << endl;
#endif
} //----- Fin de LogAnalyzerServiceImpl (constructeur de copie)

LogAnalyzerServiceImpl::LogAnalyzerServiceImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <LogAnalyzerServiceImpl>" << endl;
#endif
} //----- Fin de LogAnalyzerServiceImpl

LogAnalyzerServiceImpl::~LogAnalyzerServiceImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <LogAnalyzerServiceImpl>" << endl;
#endif
} //----- Fin de ~LogAnalyzerServiceImpl

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
