<?php
session_start();
include("conexion.php");

if ($_SESSION['rol'] !== 'superadmin') {
    echo "No tienes permisos para asignar tareas.";
    exit;
}
$tarea = $_POST['tarea'];
$asignada_a = $_POST['admin'];
$superadmin = $_SESSION['nombre']; 

$query = "INSERT INTO tareas (tarea, asignada_a, superadmin) VALUES ('$tarea', '$asignada_a', '$superadmin')";
if (mysqli_query($link, $query)) {
    echo "Tarea asignada correctamente.";
} else {
    echo "Error al asignar tarea: " . mysqli_error($link);
}
mysqli_close($link);
?>
