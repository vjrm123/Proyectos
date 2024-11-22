<?php
include("conexion.php");
session_start();
$_SESSION['login']=false;
$correo=$_POST["usuario"];
$clave=$_POST["clave"];
$consulta="SELECT * FROM cliente WHERE correo='$correo'";
$consulta=mysqli_query($link, $consulta);
$consulta=mysqli_fetch_array($consulta); 
if($consulta){
	if(password_verify($clave,$consulta['clave'])){
		$_SESSION['login']=true;
		$_SESSION['nombre']=$consulta['nombre_cliente'];
		$_SESSION['apellidos']=$consulta['apellido_cliente'];
		$_SESSION['dni']=$consulta['dni'];
		$_SESSION['telefono']=$consulta['telefono'];
		$_SESSION['direccion']=$consulta['direccion'];
		$_SESSION['fecha_nac']=$consulta['fecha_nacimiento'];
		$_SESSION['numero_tarjeta']=$consulta['numero_tarjeta'];
		$_SESSION['correo']=$consulta['correo'];
		header('Location:index.php');		
	}
	else{
		echo "Contraseña incorrecta";
		echo "<br><a href='cliente.php'>Intentalo de nuevo</a></div>";
	}
}
else{
	echo "El usuario no existe";
	echo "<br><a href='cliente.php'>Intentalo de nuevo</a></div>";
}
mysqli_close($link);
?>