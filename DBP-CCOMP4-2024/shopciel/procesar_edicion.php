<?php
include "conexion.php"; 
$cod=$_POST["cod"];
$marca=$_POST["marca"];
$talla=$_POST["talla"];
$color=$_POST["color"];
$categoria=$_POST["categoria"];
$nombreproducto=$_POST["nombreproducto"];
$precio=$_POST["precio"];
$stock=$_POST["stock"];
$resultado=mysqli_query($link,"UPDATE producto SET `codigo_marca`='$marca', `codigo_talla`='$talla', `codigo_color`='$color', `codigo_categoria`='$categoria', `nombre_producto`='$nombreproducto', `precio`='$precio', `stock`='$stock' WHERE codigo_producto='$cod'") or die ("Algo ha ido mal en la consulta a la base de datos");
if($resultado){
	header("Location:administrador.php");
}
else{
	echo "No se pudo editar el producto";
}
?>