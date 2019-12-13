/*************************************************************************
            Log  -  Représente le fichier de log importé
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
//------------- Interface de la classe <Log> (fichier Log.h) -------------
#if !defined ( LOG_H )
#define LOG_H
//--------------------------------------------------- Interfaces utilisées
#include <unordered_set>
#include "Request.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//  Représente le fichier de log importé en étant associé à la liste des
//  requêtes Request et la liste des documents Document.
//------------------------------------------------------------------------

class Log {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /**
     * Retourne le pointeur sur l'ensemble des requêtes du log.
     *
     * @return Le pointeur sur l'ensemble des requêtes du log
     */
    const unordered_set<Request> *GetRequests() const {
        return requests;
    }

    /**
     * Retourne le pointeur sur l'ensemble des documents du log.
     *
     * @return Le pointeur sur l'ensemble des documents du log
     */
     const unordered_set<Document> *GetDocuments() const {
         return documents;
     }

//-------------------------------------------- Constructeurs - destructeur
    /**
     * Constructeur du log.
     * Initialise les ensembles de requêtes et de documents.
     */
    Log();

    /**
     * Constructeur par copie du log.
     * Copie en profondeur des ensembles de requêtes et de documents.
     *
     * @param log La référence au log à copier
     */
    Log(const Log &log);

    /**
     * Destructeur du log.
     * Détruit les ensembles de requêtes et de documents.
     */
    virtual ~Log();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    unordered_set<Request> *requests;
    unordered_set<Document> *documents;
};

#endif // LOG_H
