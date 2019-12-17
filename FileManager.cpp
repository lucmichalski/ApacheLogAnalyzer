/**********void CreateDotFile(const string &dotFileName, const Log &log) const***************************************************************
   FileManager - Service sur le traitement des fichiers de l'application
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
							- Milène DAUGAN
							- Loïc DUBOIS-TERMOZ
	e-mail               :
							- milene.daugan@insa-lyon.fr
							- loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#include "FileManager.h"

/**
 * Ouvre le fichier en lecture et stock chaque ligne lue dans un ensemble non-ordonné puis le retourne
 * en fermant au préalable le fichier ouvert.
 */
Log *FileManager::ImportLogFile(const string &fileName) const {
	// TODO : Import du fichier de log sous la forme d'une instance de la classe Log
	unordered_set<const string *> *us = new unordered_set<const string *>;
	ifstream read(fileName.c_str());
	if (read) {
		us = extractLogLines(read);
		//Ci-dessous le code pour parcourir us
		unordered_set<const string*>::const_iterator itr;
		for(itr = us->begin();itr != us->end(); ++itr)
		{
			//cout << "log : " << (**itr) << ' ';
		}
		cout << endl;
	} else {
		cerr << "Erreur d'ouverture du fichier." << endl;
	}
	read.close();
	Log *test = new Log();
	test = LogFactory->CreateLog(us);
	return nullptr;
}

/**
 * Ouvre le fichier en écriture en écrasant tout son contenu puis :
 * - Ecrit la première ligne de début du digraph ;
 * - Ecrit la liste des documents utilisés représentés par des noeuds ;
 * - Ecrit la liste des requêtes pondérés par une quantité représentés par des associations entre deux noeuds ;
 * - Ecrit la dernière ligne de fin du digraph.
 * Et enfin ferme le fichier.
 */
void FileManager::CreateDotFile(const string &dotFileName, const Log &log) const {
	// TODO : Création du fichier .dot en fonction de l'instance de la classe Log spécifiée
	// SPECIFICATIONS A PRECISER !!! concernant la déléguation du traitement du Log pour le fichier .dot
}

/**
 * Lit le fichier et s'arrête à chaque caractère de fin de ligne pour stocker l'ensemble des caractères
 * lus dans une chaîne de caractère elle même stockée dans un ensemble non-ordonné.
 * Une fois la lecture terminée, l'ensemble est retourné.
 */
unordered_set<const string *> *FileManager::extractLogLines(ifstream &logFile) const {
	// TODO : Extraction des lignes de log du fichier à importer
	unordered_set<const string *> *us = new unordered_set<const string *>;

	string *line = new string();

	while (getline(logFile, *line)) {
		string * str = new string(*line);
		us->insert(str);//écrase les lines et ne garde que la dernière
	}

	return us;
}

/**
 * Détruit les ligne de log représentés par des chaînes de caractères puis supprime l'ensemble
 * non-ordonné.
 */
void FileManager::deleteLogLines(const unordered_set<const string *> *logLines) const {
	for (const string *logLine : *logLines) {
		delete logLine;
	}
	delete logLines;
}