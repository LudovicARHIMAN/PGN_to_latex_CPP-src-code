<!DOCTYPE html>
<html>
    <meta charset="utf-8" />
    <link rel="stylesheet" href="style.css">
<head>
    <title>Parseur PGN</title>
    
</head>
<body>

        

    <div class="main">

        <form action="" method="post" enctype="multipart/form-data">
            <h1>Parseur PGNP</h1>
            <label for="fichierPGN">Sélectionnez un fichier PGN :</label>
            <input type="file" name="fichierPGN" id="fichierPGN">
            <input type="submit" value="Envoyer">
            <input type="reset" value="Réinitialiser">
        </form>

    </div>


     
    <?php 
    
        if (($_FILES['fichierPGN']['name']!="")){
            // Where the file is going to be stored
                $target_dir = "/var/www/html/Convert/libpgnp/conv";
                $file = $_FILES['fichierPGN']['name'];
                $path = pathinfo($file);
                $filename = $path['filename'];
                $ext = $path['.pgn'];
                $temp_name = $_FILES['fichierPGN']['tmp_name'];
                $path_filename_ext = $target_dir.$filename.".".$ext;
        }
            // Check if file already exists
        if (file_exists($path_filename_ext)) {
            echo "Désolé, le fichier existe déjà.";
            }else{
            move_uploaded_file($temp_name,$path_filename_ext);
            echo "Fichier envoyé avec succès.";
            }
            

    
            
    
    
    
    ?>
            
    
    
    
    
    
    
    
    



</body>
</html>
