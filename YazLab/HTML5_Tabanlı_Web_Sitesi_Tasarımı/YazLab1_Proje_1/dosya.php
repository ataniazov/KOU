<?php
$target_dir = "slicebox/slider/";
$target_file = $target_dir . basename($_FILES["button_gonder"]["name"]);
$uploadOk = 1;
$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
// Check if image file is a actual image or fake image
if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["button_gonder"]["tmp_name"]);
    if($check !== false) {
        echo "Resim formatı- " . $check["mime"] . ".";
        $uploadOk = 1;
    } else {
        echo "Dosya resim dosyası değil.";
        $uploadOk = 0;
    }
}
?>