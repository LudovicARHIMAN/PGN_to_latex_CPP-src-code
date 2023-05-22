# PGN to latex ♟️


Convertit un fichier PGN (Portable Game Notion) en fichier latex grâce à une interfae web.


# ⚠️ ATTENTION 

Le code suivant est en partie fonctionnel, mais il présente des erreurs, les fichiers .tex convertis ne passent pas la compilation, car ils  présentent des erreurs comme des "}" en trop qui sont présentes parfois dans le code qui crée des erreurs dans la compilation. Les NAG, variations et commentaire ne sont pas pris en compte par le convertisseur 

L'interface web permet de télécharger les fichiers convertis avec un bouton qui reste afficher tout les temps cela est normal nous n'avons pour l'instant pas fixer ce problème 

<h3> Pre-requis </h3>

Le code doit se trouver dans le répertoire /var/www/html dans un dossier "Convert" et donc dans le path "/var/www/html/Convert" 

Le Code a besoin des permissions en écriture, lecture et exécution, la commande suivante peut résoudre le problème de permission (même si ce n'est pas recommandé)

``` bash 

chmod -R 777 /var/www/html/Convert

``` 

**"/var/www/html/Convert" doit être possédé par soit un utilisateur du groupe "www-data" ou votre utiliateur courant**

Le repertoire /var/www/html/Convert/converted doit aussi être créer 


<h3> Le repertoire devrais ressembler à ceci </h3>

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
