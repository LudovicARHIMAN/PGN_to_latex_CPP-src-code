<?php
// Vérifie si un fichier a été soumis
if (isset($_FILES['pgn_file'])) {
    $file = $_FILES['pgn_file'];

    // Vérifie si le fichier a été téléchargé sans erreur
    if ($file['error'] === UPLOAD_ERR_OK) {
        $filename = $file['name'];
        $tmpFilePath = $file['tmp_name'];

        // Définir le dossier de destination
        $destinationFolder = '/var/www/html/Convert/pgn_files';

        // Déplacer le fichier téléchargé vers le dossier de destination
        $destinationPath = $destinationFolder . $filename;
        if (move_uploaded_file($tmpFilePath, $destinationPath)) {
            echo "Le fichier a été téléchargé avec succès.";

            // Appeler libpgn pour développer le fichier en LaTeX
            exec("libpgnp " . $destinationPath . " > " . $destinationFolder . "output.tex");

            echo "Le fichier a été développé en LaTeX avec succès.";
        } else {
            echo "Une erreur s'est produite lors du déplacement du fichier.";
        }
    } else {
        echo "Une erreur s'est produite lors du téléchargement du fichier.";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Upload PGN</title>
    <script src="https://cdn.tailwindcss.com/"></script>
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








