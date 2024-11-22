<?php
include("conexion.php");
session_start();

$id = $_POST['id'];
$nuevo_estado = $_POST['estado'];

$query = "UPDATE tareas SET estado='$nuevo_estado' WHERE id='$id'";
if (mysqli_query($link, $query)) {
    echo "Tarea actualizada correctamente.";
} else {
    echo "Error al actualizar tarea: " . mysqli_error($link);
}
mysqli_close($link);
header("Location: administrador.php"); 
?>
