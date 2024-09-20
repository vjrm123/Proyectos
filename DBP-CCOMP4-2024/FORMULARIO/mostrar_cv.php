<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $nombre = htmlspecialchars($_POST['nombre']);
    $fecha_nacimiento = htmlspecialchars($_POST['fecha_nacimiento']);
    $ocupacion = htmlspecialchars($_POST['ocupacion']);
    $contacto = htmlspecialchars($_POST['contacto']);
    $nacionalidad = htmlspecialchars($_POST['nacionalidad']);
    $nivel_ingles = htmlspecialchars($_POST['nivel_ingles']);
    $lenguajes = implode(", ", $_POST['lenguajes']);
    $aptitudes = htmlspecialchars($_POST['aptitudes']);
    $habilidades = implode(", ", $_POST['habilidades']);
    $perfil = htmlspecialchars($_POST['perfil']);
    
    echo "
    <!DOCTYPE html>
    <html lang='es'>
    <head>
        <meta charset='UTF-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <title>CV de $nombre</title>
        <link rel='stylesheet' type='text/css' href='CSS/hoja_cv.css'>
    </head>
    <body>
        <div class='cv-container'>
            <h1>Currículum Vitae</h1>
            <div class='section'>
                <h2>Información Personal</h2>
                <p><strong>Nombre:</strong> $nombre</p>
                <p><strong>Fecha de Nacimiento:</strong> $fecha_nacimiento</p>
                <p><strong>Ocupación:</strong> $ocupacion</p>
                <p><strong>Contacto:</strong> $contacto</p>
                <p><strong>Nacionalidad:</strong> $nacionalidad</p>
                <p><strong>Nivel de Inglés:</strong> $nivel_ingles</p>
            </div>
            <div class='section'>
                <h2>Lenguajes de Programación</h2>
                <p>$lenguajes</p>
            </div>
            <div class='section'>
                <h2>Aptitudes</h2>
                <p>$aptitudes</p>
            </div>
            <div class='section'>
                <h2>Habilidades</h2>
                <p>$habilidades</p>
            </div>
            <div class='section'>
                <h2>Perfil</h2>
                <p class='profile-text'>$perfil</p>
            </div>
        </div>
    </body>
    </html>";
}
?>