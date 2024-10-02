<?php
include 'conexion/connect.php'; 

$nombre = $_POST['nombre'];
$fecha_nacimiento = $_POST['fecha_nacimiento'];
$ocupacion = $_POST['ocupacion'];
$contacto = $_POST['contacto'];
$formaciones = $_POST['formacion'];
$habilidades = $_POST['habilidades'];
$nacionalidad = $_POST['nacionalidad'];
$nivel_ingles = $_POST['nivel_ingles'];
$idiomas = $_POST['idiomas'];
$lenguajes = $_POST['lenguajes'];
$aptitudes = $_POST['aptitudes'];
$experiencias_laborales = $_POST['experiencia_laboral'];
$perfil = $_POST['perfil'];


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    try {
        
        $conn->beginTransaction();

        $nombre = $_POST['nombre'];
        $fecha_nacimiento = $_POST['fecha_nacimiento'];
        $ocupacion = $_POST['ocupacion'];
        $contacto = $_POST['contacto'];
        $nacionalidad = $_POST['nacionalidad'];
        $nivel_ingles = $_POST['nivel_ingles'];
        $perfil = $_POST['perfil'];

        $sql = "INSERT INTO usuarios (nombre, fecha_nacimiento, ocupacion, contacto, nacionalidad, nivel_ingles, perfil) 
                VALUES (:nombre, :fecha_nacimiento, :ocupacion, :contacto, :nacionalidad, :nivel_ingles, :perfil)";
        $stmt = $conn->prepare($sql);
        $stmt->execute([
            ':nombre' => $nombre,
            ':fecha_nacimiento' => $fecha_nacimiento,
            ':ocupacion' => $ocupacion,
            ':contacto' => $contacto,
            ':nacionalidad' => $nacionalidad,
            ':nivel_ingles' => $nivel_ingles,
            ':perfil' => $perfil
        ]);

        $usuario_id = $conn->lastInsertId();

        foreach ($_POST['formacion'] as $formacion) {
            $sql = "INSERT INTO formaciones (usuario_id, descripcion) VALUES (:usuario_id, :descripcion)";
            $stmt = $conn->prepare($sql);
            $stmt->execute([
                ':usuario_id' => $usuario_id,
                ':descripcion' => $formacion
            ]);
        }

        foreach ($_POST['idiomas'] as $idioma) {
            $sql = "INSERT INTO idiomas (usuario_id, idioma, nivel) VALUES (:usuario_id, :idioma, :nivel)";
            $stmt = $conn->prepare($sql);
            $stmt->execute([
                ':usuario_id' => $usuario_id,
                ':idioma' => $idioma, 
                ':nivel' => 'N/A' 
            ]);
        }

        if (!empty($_POST['habilidades'])) {
            foreach ($_POST['habilidades'] as $habilidad) {
                $sql = "INSERT INTO habilidades (usuario_id, habilidad) VALUES (:usuario_id, :habilidad)";
                $stmt = $conn->prepare($sql);
                $stmt->execute([
                    ':usuario_id' => $usuario_id,
                    ':habilidad' => $habilidad
                ]);
            }
        }

        if (!empty($_POST['lenguajes'])) {
            foreach ($_POST['lenguajes'] as $lenguaje) {
                $sql = "INSERT INTO lenguajes_programacion (usuario_id, lenguaje) VALUES (:usuario_id, :lenguaje)";
                $stmt = $conn->prepare($sql);
                $stmt->execute([
                    ':usuario_id' => $usuario_id,
                    ':lenguaje' => $lenguaje
                ]);
            }
        }

        if (!empty($_POST['aptitudes'])) {
            foreach ($_POST['aptitudes'] as $aptitud) {
                $sql = "INSERT INTO aptitudes (usuario_id, aptitud) VALUES (:usuario_id, :aptitud)";
                $stmt = $conn->prepare($sql);
                $stmt->execute([
                    ':usuario_id' => $usuario_id,
                    ':aptitud' => $aptitud
                ]);
            }
        }

        foreach ($_POST['experiencia_laboral'] as $experiencia) {
            $sql = "INSERT INTO experiencias_laborales (usuario_id, descripcion) VALUES (:usuario_id, :descripcion)";
            $stmt = $conn->prepare($sql);
            $stmt->execute([
                ':usuario_id' => $usuario_id,
                ':descripcion' => $experiencia
            ]);
        }

        $conn->commit();

    } catch (Exception $e) {
        $conn->rollBack();
        echo "Error: " . $e->getMessage();
    }
}
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Currículum de <?php echo $nombre; ?></title>
    <link rel="stylesheet" href="CSS/style_cv.css"> 
</head>
<body>

    <div class="container">
        <div class="header">
            <img src="BD-CCOMP4.1/images.jpg" alt="perfil">
            <h1><?php echo $nombre; ?></h1>
        </div>

        <div class="content">
            <div class="left">
                <div class="section">
                    <h2>Contacto</h2>
                    <ul class="contact-info">
                        <li><?php echo $contacto; ?></li>
                        <li><?php echo $nacionalidad; ?></li>
                    </ul>
                </div>

                <div class="section">
                    <h2>Idiomas</h2>
                    <ul class="languages">
                        <?php foreach ($idiomas as $idioma): ?>
                            <li><?php echo $idioma; ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>

                <div class="section">
                    <h2>Aptitudes</h2>
                    <ul class="aptitudes">
                        <?php foreach ($aptitudes as $aptitud): ?>
                            <li><?php echo $aptitud; ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>

                <div class="section">
                    <h2>Habilidades</h2>
                    <ul class="skills">
                        <?php foreach ($habilidades as $habilidad): ?>
                            <li><?php echo $habilidad; ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>
                
                <div class="section">
                    <h2>Lenguajes de Programación</h2>
                    <ul class="skills">
                        <?php foreach ($lenguajes as $lenguaje): ?>
                            <li><?php echo ucfirst($lenguaje); ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>
            </div>

            <div class="right">
                <div class="section">
                    <h2>Perfil</h2>
                    <p><?php echo nl2br($perfil); ?></p>
                </div>

                <div class="section">
                    <h2>Experiencia Laboral</h2>
                    <ul>
                        <?php foreach ($experiencias_laborales as $experiencia): ?>
                            <li><?php echo $experiencia; ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>

                <div class="section">
                    <h2>Formación</h2>
                    <ul>
                        <?php foreach ($formaciones as $formacion): ?>
                            <li><?php echo $formacion; ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>
            </div>
        </div>

        <div class="footer">
            <p><?php echo $nombre; ?> - <?php echo $ocupacion; ?> | <?php echo $nacionalidad; ?></p>
        </div>
    </div>


</body>
</html>
