<?php
include("conexion.php");
session_start();

$_SESSION['login'] = false;

$correo = $_POST["admin_email"];
$clave = $_POST["admin_clave"];

$consulta = $link->prepare("SELECT * FROM administrar_usiarios WHERE email = ?");
$consulta->bind_param("s", $correo);
$consulta->execute();
$resultado = $consulta->get_result();
$usuario = $resultado->fetch_assoc();

if ($usuario) {
    if (password_verify($clave, $usuario['password'])) {
        $_SESSION['login'] = true;
        $_SESSION['nombre'] = $usuario['nombre'];
        $_SESSION['email'] = $usuario['email'];
        $_SESSION['rol'] = $usuario['rol']; 

        header('Location: administrador.php');
        exit;
    } else {
        echo "Contraseña incorrecta";
        echo "<br><a href='registrar_administrador.php'>Inténtalo de nuevo</a>";
    }
} else {
    echo "El usuario no existe";
    echo "<br><a href='registrar_administrador.php'>Inténtalo de nuevo</a>";
}

mysqli_close($link);
?>
