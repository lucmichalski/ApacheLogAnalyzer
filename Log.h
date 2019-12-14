/*************************************************************************
                Log - Représente le fichier de log importé
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
     * @return Le pointeur sur l'ensemble des requêtes du log
     */
    const unordered_set<const Request *> *GetRequests() const {
        return requests;
    }

    /**
     * @return Le pointeur sur l'ensemble des documents du log
     */
    const unordered_set<const Document *> *GetDocuments() const {
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
    friend class LogFactory;
//----------------------------------------------------- Méthodes protégées
    /**
     * Ajoute une requête au Log.
     *
     * @param request La référence à la requête à ajouter
     */
    void addRequest(const Request *request) {
        requests->insert(request);
    }

    /**
     * Ajoute un document au Log.
     *
     * @param document La référence au document à ajouter
     */
    void addDocument(const Document *document) {
        documents->insert(document);
    }

    /**
     * Cherche et retourne le pointeur du document associé à l'URL passé en paramètre s'il existe, nullptr sinon.
     *
     * @param URL La référence à l'URL du document à rechercher
     * @return Le pointeur du document associé à l'URL s'il existe, nullptr sinon
     */
    const Document *getDocument(const string &URL) const;

//----------------------------------------------------- Attributs protégés
    unordered_set<const Request *> *requests = nullptr;
    unordered_set<const Document *> *documents = nullptr;
};

#endif // LOG_H
