<?php
    // Vérifie si un fichier a été soumis
    if (isset($_FILES['pgn_file'])) {
        $file = $_FILES['pgn_file'];
        
        // Vérifie si le fichier a été téléchargé sans erreur
        if ($file['error'] === UPLOAD_ERR_OK) {
            $filename = $file['name'];
            $tmpFilePath = $file['tmp_name'];
            $name = pathinfo($filename, PATHINFO_FILENAME);
            
            
            
                        
            // path des fichiers qui serra donné en argument au convertisseur
            
            $in_path = "/var/www/html/Convert/libpgnp/tmp/"."$name".".pgn"; // path du ficher pgn à convertir
            $out_path = "/var/www/html/Convert/libpgnp/converted/"."$name".".tex" ; // path du fichier convertis
            
           


            // Définir le dossier de destination
            $destinationFolder = '/var/www/html/Convert/libpgnp/tmp/';

            // Déplacer le fichier téléchargé vers le dossier de destination
            $destinationPath = $destinationFolder . $filename;
            if (move_uploaded_file($tmpFilePath, $destinationPath)) {
                echo "Le fichier a été téléchargé avec succès.";
                

                // Appeler libpgn pour développer le fichier en LaTeX 
                //exec("libpgnp " . $destinationPath . " > " . $destinationFolder . "output.tex");
                
                //echo "Le fichier a été développé en LaTeX avec succès.";
            } else {
                echo "Une erreur s'est produite lors du déplacement du fichier.";
            }
        }    
    }



    // Télécharger les fichiers convertis 
    
    $targetDirectory = '/var/www/html/Convert/libpgnp/converted';

    // Get the list of files in the target directory
    $files = scandir($targetDirectory);

    // Exclure les dossiers  "." et ".." de la liste
    $files = array_diff($files, array('.', '..'));

    // affiche les fichier contenu dans le dossier 
    /*
    foreach ($files as $file) {
        echo $file . "<br>";
    }
    */
    /*

    $fileUrl = 'http://example.com/path/to/file.pdf';  // URL of the file you want to download
    $savePath = '/path/to/folder/file.pdf';  // Path to save the downloaded file

    // Download the file using cURL
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $fileUrl);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

    $fileData = curl_exec($ch);
    curl_close($ch);

    // Save the file to the specified location
    file_put_contents($savePath, $fileData);

    echo 'File downloaded and saved successfully.';
    */
    


?>

<!DOCTYPE html>
<html>
<head>
    <title>Upload PGN</title>
    <script src="https://cdn.tailwindcss.com/"></script>
    <scipt src="type.js"></script>
</head>
<body class="bg-grey-200"> <!-- Définit une couleur de fond gris clair -->
    <div class="flex justify-center items-center min-h-screen"> <!-- Crée un conteneur qui s'étend sur au moins la hauteur de l'écran -->
        <form action="" method="POST" enctype="multipart/form-data" class="max-w-md mx-auto p-6 bg-blue rounded-lg shadow-lg"> <!-- Formulaire avec des classes Tailwind CSS -->
            <div class="mb-10"> <!-- Ajoute une marge inférieure de 10 unités (taille configurable) entre les éléments du formulaire -->
                <label for="pgn_file" class="block text-gray-700 font-bold mb-2">Sélectionnez un fichier PGN :</label> <!-- Étiquette pour l'élément de fichier -->
                <input type="file" name="pgn_file" accept=".pgn" class="border rounded py-2 px-3 bg-gray-100 w-full focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"> <!-- Champ de fichier avec des classes Tailwind CSS -->
            </div>
            <div class="text-center"> <!-- Centre le bouton "Upload" horizontalement -->
                <input type="submit" value="Upload" class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:ring-2 focus:ring-blue-500 focus:ring-offset-2"> <!-- Bouton d'envoi avec des classes Tailwind CSS -->
            </div>
        </form>
    </div>
</body>
</html>
