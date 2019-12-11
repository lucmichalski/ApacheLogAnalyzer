/*************************************************************************
						   DocumentImpl  -  Instancie des objets contenant toutes les
							 adresses du fichier de log
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par DAUGAN
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <DocumentImpl> (fichier DocumentImpl.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "DocumentImpl.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DocumentImpl::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
DocumentImpl & DocumentImpl::operator = ( const DocumentImpl & unDocumentImpl )
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
DocumentImpl::DocumentImpl ( const DocumentImpl & unDocumentImpl )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DocumentImpl>" << endl;
#endif
} //----- Fin de DocumentImpl (constructeur de copie)

DocumentImpl::DocumentImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DocumentImpl>" << endl;
#endif
} //----- Fin de DocumentImpl

DocumentImpl::~DocumentImpl ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DocumentImpl>" << endl;
#endif
} //----- Fin de ~DocumentImpl

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
