<?php 



if (isset($_FILES['file'])) {
    $file = $_FILES['file'];
    $temp_path = $file['tmp_name'];
    $target_path = '/var/www/html/Convert/libpgnp/Conv' . $file['name'];
    move_uploaded_file($temp_path, $target_path);
    echo 'File uploaded successfully!';
}



?> 