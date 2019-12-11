/*************************************************************************
						   LogImpl  -  Place les lignes de logs dans des objets, 
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <LogImpl> (fichier LogImpl.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "LogImpl.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogImpl::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
LogImpl & LogImpl::operator = ( const LogImpl & unLogImpl )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
LogImpl::LogImpl ( const LogImpl & unLogImpl )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <LogImpl>" << endl;
#endif
} //----- Fin de LogImpl (constructeur de copie)

LogImpl::LogImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <LogImpl>" << endl;
#endif
} //----- Fin de LogImpl

LogImpl::~LogImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <LogImpl>" << endl;
#endif
} //----- Fin de ~LogImpl

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
