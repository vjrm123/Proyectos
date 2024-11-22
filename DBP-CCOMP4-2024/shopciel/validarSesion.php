<?php
session_start();
$login=$_SESSION['login'];
if(!$login){ //Si login no es verdadero
	header('Location:cliente.php');
}
else{
	$ce=$_SESSION['correo'];
}
?>
