/*************************************************************************
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
#ifndef APACHELOGANALYZER_FILEMANAGER_H
#define APACHELOGANALYZER_FILEMANAGER_H

#include "Log.h"
#include "LogFactory.h"

/**
 * FileManager met à disposition un ensemble de services permettant de gérer tout l'aspect
 * traitement de fichier de l'application (import du fichier de log, création du fichier .dot, etc).
 */
class FileManager {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const FileManager &fileManager);

	/**
	 * Récupère et importe l'ensemble des informations contenues dans le fichier de log spécifié.
	 *
	 * @param fileName Le nom du fichier de log à importer
	 * @return Les informations du fichier de log importé sous la forme d'une instance de la classe Log
	 * @throws exception S'il n'est pas possible de lire le fichier ou qu'il comporte des erreurs
	 *  (fichier introuvable, problème de permission, le format d'une ligne de log est incorrect, chemin incorrect)
	 *  // TODO : exceptions OK ?
	 */
	Log *ImportLogFile(const std::string &fileName) const;

	/**
	 * Créer le fichier .dot correspondant à l'instance de la classe Log spécifiée. Écrase le fichier existant.
	 *
	 * @param dotFileName Le nom du fichier .dot à créer
	 * @param log L'instance de la classe Log à utiliser pour la génération du fichier .dot
	 * // TODO : Param log à changer ? (déléguer la responsabilité de traiter le Log)
	 * @throws exception Si un problème de permissions ou de chemin incorrect est détecté
	 * // TODO : exceptions OK ?
	 */
	void CreateDotFile(const std::string &dotFileName, const Log &log) const;

	/**
	 * Constructeur par défaut de la classe.
	 * Comportement par défaut.
	 */
	FileManager() = default;

	/**
	 * Destructeur de la classe.
	 * Comportement par défaut.
	 */
	~FileManager() = default;

protected:
	/**
	 * Extrait les lignes du fichier de log à importer individuellement et les stock dans un ensemble non-ordonné.
	 *
	 * @param logFile Le fichier de log contenant les lignes à importer
	 * @return Un ensemble non-ordonné de lignes du fichier de log importé
	 * // TODO : Exception(s) levée(s) ?
	 */
	 std::unordered_set<std::string *> *extractLogLines(std::ifstream &logFile) const;

	/**
	 * Détruit l'ensemble ainsi que les chaînes qu'il contient.
	 *
	 * @param logLines L'ensemble de lignes de log à détruire
	 */
	void deleteLogLines(const std::unordered_set<const std::string *> *logLines) const;
};

inline std::ostream &operator<<(std::ostream &os, const FileManager &fileManager) {
    os << "FileManager{}";
    return os;
}

#endif //APACHELOGANALYZER_FILEMANAGER_H
