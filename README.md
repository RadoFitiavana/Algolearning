# Algolearning
Application desktop pour la plateforme linux

# Architeture de l'espace de travail
Algolearning:
    README.md
    .gitignore
    source:
        main.c controler.c model.c test.c tools.c
    header:
        view.h controler.h model.h tools.h
    exe:
        //Les executables

# Desing Pattern: 
MVC

# Choisir une tâche:
1- Model:
    Fichiers: source/model.c et head/model.h
    Les fonctions d'interaction avec les bases de données

2- View:
    Fichiers: source/main.c et source/view.h
    L'interface

3- Controler:
    Fichiers: source/controler.c et source/controler.h

# Instructions sur le mode de travail:
1- Cloner le depôt:
    git clone url_depôt

2- Créer une nouvelle branche pour votre travail:
    git branch new_branch_name //créer une nouvelle branche
    git checkout new_branch_name //basculer sur la nouvelle branche

3- Faire un push:
    3-1- D'abord fusioner votre travail dans la branche master:
        git checkout master //basculer sur la branche master
        gt merge new_branch_name //fusioner votre branche avec master
    3-2- Faire un push:
        git push

4- Ne modifier que les fichiers qui concernent vos tâches

5- Utiliser le fichier test.c pour tester vos fonctions


