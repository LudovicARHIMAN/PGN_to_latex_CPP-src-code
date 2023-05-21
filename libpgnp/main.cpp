<?php
    // Vérifie si un fichier a été soumis
    if (isset($_FILES['pgn_file'])) {
        $file = $_FILES['pgn_file'];
        
        // Vérifie si le fichier a été téléchargé sans erreur
        if ($file['error'] === UPLOAD_ERR_OK) {
            $filename = $file['name'];
            $tmpFilePath = $file['tmp_name'];
            $name = pathinfo($filename, PATHINFO_FILENAME);
            
            // Définir le dossier de destination
            $destinationFolder = '/var/www/html/Convert/libpgnp/tmp/';
                        
            // full path des fichiers qui serra donné en argument au convertisseur
            
            $in_path = '/var/www/html/Convert/libpgnp/tmp/'.$name.".pgn"; // path du ficher pgn à convertir
            $out_path = "/var/www/html/Convert/libpgnp/converted/"."$name".".tex" ; // path du fichier convertis
            
            $out_name= $name.".tex"; 
            $fileUrl = 'http://192.168.1.140/Convert/libpgnp/converted/'.$out_name;
            
            // Déplacer le fichier téléchargé vers le dossier de destination
            $destinationPath = $destinationFolder . $filename;
            if (move_uploaded_file($tmpFilePath, $destinationPath)) {
                echo "Le fichier a été téléchargé avec succès.";
                
                
                // Appeler le convertisseur pour développer le fichier en LaTeX 
                exec("cd /var/www/html/Convert/libpgnp && ./main ".$in_path." ".$out_path); 
                // le convertisseur fonctione avec des arguments: le path du fichier à convertir, et le path du fichier de sortie
                
                
            
            } else {
                echo "Une erreur s'est produite lors du déplacement du fichier.";
            }
            

           
        }    
    }


    
    // Récupérer la liste des fichiers convertis
    $targetDirectory = '/var/www/html/Convert/libpgnp/converted';
    $files = scandir($targetDirectory);
    $files = array_diff($files, array('.', '..'));
    
    

    // permet d'effacer les fichiers une fois la convertion effectué
    function clean() {
        exec("rm -rf /var/www/html/Convert/libpgnp/converted/*  && rm -rf /var/www/html/Convert/libpgnp/tmp/*");
    }

       
    // regarde si le dosser destination est vide 
    function is_empty($targetDirectory) {
        if (count(glob("$empty/*")) === 0 ) {
            return FALSE;
        }
        else {
            return TRUE;
        }

    }

    



?>

<!DOCTYPE html>
<html>
<head>
    <title>Upload PGN</title>
    <script src="https://cdn.tailwindcss.com/"></script>
    <scipt src="type.js"></script>
</head>
<body class="bg-grey-200">

    <div class="flex justify-center items-center min-h-screen">
        <form action="" method="POST" enctype="multipart/form-data" class="max-w-md mx-auto p-6 bg-blue rounded-lg shadow-lg">
            <div class="mb-10">
                <label for="pgn_file" class="block text-gray-700 font-bold mb-2">Sélectionnez un fichier PGN :</label>
                <input type="file" name="pgn_file" accept=".pgn" class="border rounded py-2 px-3 bg-gray-100 w-full focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent">
                <div>
                    <?php
                        if (is_empty($empty)!=TRUE){
                        echo('<a id="downloadLink" href="#" onclick="downloadFile()">Télécharger le fichier latex </a>');
                        }
                        
                                               



                    ?>
                    
                    
                </div>
            
            </div>
            <div class="text-center">
                <input type="submit" value="Upload" class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:ring-2 focus:ring-blue-500 focus:ring-offset-2">
            </div>
        </form>
    </div>

    <script>
    // JavaScript code
    function downloadFile() {
        var fileUrl = '<?php echo $fileUrl; ?>'; // Replace with your PHP variable containing the file URL
        var fileName = '<?php echo $out_name; ?>'; // Replace with your PHP variable containing the desired file name

        var link = document.createElement('a');
        link.setAttribute('href', fileUrl);
        link.setAttribute('download', fileName);
        link.style.display = 'none';
        document.body.appendChild(link);
        link.click();
        document.body.removeChild(link);
    }
    </script>

    

</body>
</html>
