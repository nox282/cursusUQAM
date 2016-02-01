########################################################
########################################################
##                                                    ##
##                  Recipe Book                       ##
##                                                    ##
##    PAR : Nicolas HAMARD                            ##
##    CODE PERM. : HAMN25079209                       ##
##    COURS : INF3135                                 ##
##                                                    ##
########################################################
########################################################
##                                                    ##
##  INSTRUCTIONS :                                    ##
##    1.Pour compiler le programme :                  ##
##                                                    ##
##      Ce programme est fourni avec un makefile      ##
##      Pour compiler dans un executable,             ##
##      tapez simplement la commande en etant         ##
##      dans le meme dossier que les sources :        ##
##      `make'                                        ##
##                                                    ##
##      Si vous utilisez un autre compilateur que     ## 
##      gcc, ou, voulez ajouter des flags de          ##
##      compilation suplementaires, veuillez editer   ##
##      le fichier makefile.inc                       ##
##                                                    ##
##                                                    ##
##    2.Pour utiliser le programme :                  ##
##                                                    ##
##      Commande d'execution :                        ##
##      `./recipeBook fichier_d_entree'               ##
##                                                    ##
##      Le fichier d'entree doit etre formaté         ##
##      correctment :                                 ##
##          `recette [categorie1] [categorie2]\n'     ##
##      Le Programme peut lire n'importe quel nombre  ##
##      de recette et de categorie. Les lignes        ##
##      ne sont pas limitees non plus.                ##
##                                                    ##
##      Une fois le programe lance, vous avez la      ##
##      possibilite de rentrer deux type de           ##
##      recherches :                                  ## 
##          - categerorie                             ##
##          - categorie mot-cle                       ##
##      le programme vous signalera si une categorie  ##
##      entree n'existe pas, si la recherche n'a      ##
##      donnee aucun resultat, ou, si la recherche    ##
##      est invalide. Pour quitter le programme,      ##
##      appuyez sur entre lorsque le programe vous    ##
##      demande de rentrer une recherche              ##
##                                                    ##
##      Le programme retournera EXIT_SUCCESS s'il se  ##
##      termine sans erreur, EXIT_FAILURE dans le     ##
##      cas contraire.                                ##
##                                                    ##
##      Le dossier contient une liste de recette      ##
##      pretre a etre essayee : input.txt             ##
##                                                    ##
########################################################
########################################################
