# PGN to latex 


Convertis un fichier PGN (Portable Game Notion) en fichier latex grâce à une interfae web.


# ATTENTION 

Le code suivant est en parti fonctionnel mais il presente des erreur les fichier .tex convertis ne passent pas la compilation car ils  presentent des érreurs 

<h3> Pre-requis </h3>

Le code doit se trouver dans le répertoire /var/www/html dans un dossier "Convert" et donc dans le path "/var/www/html/Convert" 

Le Code a besoin des permissions en écriture, lecture et exécution, la commande suivante peut résoudre le problème de permission (même si ce n'est pas recommandé)

``` bash 

chmod -R 777 /var/www/html/Convert

``` 

**"/var/www/html/Convert" doit être possédé par soit un utilisateur du groupe "www-data" ou votre utiliateur courant**

Le repertoire /var/www/html/Convert/converted doit aussi être créer 


<h3> Le repertoire devrai ressembler à ceci </h3>

```

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
```
