<?php
include "conexion.php";
session_start(); 
if (!isset($_SESSION['rol']) || $_SESSION['rol'] !=='superadmin') {
    echo "No tienes permisos para eliminar";
    exit; 
}
$codigo=$_GET['codigo'];
$eliminar="DELETE FROM producto WHERE codigo_producto='$codigo'";
$resultado=mysqli_query($link, $eliminar);
if($resultado){
	header("Location:administrador.php");
}
else{
	echo "No se pudo eliminar el producto";
}
?>