/*************************************************************************
                    Main - Point d'entrée de l'application
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
                            - Milène DAUGAN
                            - Loïc DUBOIS-TERMOZ
	e-mail               :
                            - milene.daugan@insa-lyon.fr
                            - loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#include "Controller.h"

using namespace std;

/**
 * Point d'entrée de l'application.
 *
 * @param argc Le nombre d'arguments de la commande saisie par l'utilisateur (argument de commande inclu)
 * @param argv La liste des arguments spécifiés
 * @return Un code indiquant le bon déroulement de l'exécution de l'application ou non
 */
int main(int argc, char **argv) {
    Controller controller(argc, argv);
    return EXIT_SUCCESS;
}
/*
Pour tester (Milène)
./logAnalyser ../testA.log
*/
