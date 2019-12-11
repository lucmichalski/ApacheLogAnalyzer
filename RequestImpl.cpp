/*************************************************************************
						   RequestImpl  -  Instancie des objets contenant l'adresse
							 source et destination de chaque ligne de log
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <RequestImpl> (fichier RequestImpl.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "RequestImpl.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RequestImpl::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
RequestImpl & RequestImpl::operator = ( const RequestImpl & unRequestImpl )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
RequestImpl::RequestImpl ( const RequestImpl & unRequestImpl )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <RequestImpl>" << endl;
#endif
} //----- Fin de RequestImpl (constructeur de copie)

RequestImpl::RequestImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <RequestImpl>" << endl;
#endif
} //----- Fin de RequestImpl

RequestImpl::~RequestImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <RequestImpl>" << endl;
#endif
} //----- Fin de ~RequestImpl

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
