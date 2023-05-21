# PGN to latex 


Convertis un fichier PGN (Portable Game Notion) en fichier latex grâce à une interfae web.


# ATTENTION 

Le code doit se trouver dans le répertoire /var/www/html dans un dossier "Convert" et donc dans le path "/var/www/html/Convert" 

Le Code a besoin des permissions en écriture, lecture et exécution, la commande suivante peut résoudre le problème de permission (même si ce n'est pas recommandé)

``` bash 

chmod -R 777 /var/www/html/Convert

``` 

**"/var/www/html/Convert" doit être posséder par soit un utilisateur du groupe "www-data" ou votre utiliateur courant**

Le repertoire /var/www/html/Convert/converted doit aussi être créer 

Le repertoire devrai ressempler à ceci 

Convert
└── libpgnp
    ├── converted
    ├── pgnp
    │   ├── build
    │   │   ├── CMakeFiles
    │   │   │   ├── 3.22.1
    │   │   │   │   ├── CompilerIdC
    │   │   │   │   │   └── tmp
    │   │   │   │   └── CompilerIdCXX
    │   │   │   │       └── tmp
    │   │   │   ├── CMakeTmp
    │   │   │   └── pgnp.dir
    │   │   │       └── src
    │   │   ├── includes
    │   │   └── libs
    │   │       └── chess-move-interface
    │   │           ├── CMakeFiles
    │   │           │   └── ChessMoveInterface.dir
    │   │           │       └── src
    │   │           └── includes
    │   ├── libs
    │   │   └── chess-move-interface
    │   │       ├── src
    │   │       └── tests
    │   │           └── catch3
    │   ├── src
    │   └── tests
    │       ├── catch3
    │       └── pgn_files
    │           ├── combined
    │           ├── str
    │           └── valid
    └── tmp
