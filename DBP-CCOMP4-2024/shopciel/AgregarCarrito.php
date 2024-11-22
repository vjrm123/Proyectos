<?php
include "conexion.php";
include("validarSesion.php");
  global $link;    
  $identificacion="SELECT * FROM cliente c INNER JOIN metodo_pago m ON c.codigo_cliente=m.codigo_cliente WHERE correo='$ce'";
  $identificacion=mysqli_query($link, $identificacion);
  $identificacion=mysqli_fetch_array($identificacion);
  $consulta0="INSERT INTO pedido (codigo_pedido, codigo_cliente, codigo_pago, fecha_pedido, fecha_entrega, estado_pedido) VALUES (NULL,'$identificacion[codigo_cliente]', '$identificacion[codigo_pago]', CURRENT_DATE(), DATE_ADD(CURRENT_DATE(), INTERVAL 15 DAY),'en proceso')";
  $consulta0=mysqli_query($link, $consulta0);
  $consulta01="SELECT * FROM pedido p INNER JOIN cliente c ON p.codigo_cliente=c.codigo_cliente WHERE correo='$ce'";
  $consulta01=mysqli_query($link, $consulta01);
  $consulta01=mysqli_fetch_array($consulta01);
  $nombre_producto=$_POST["producto"];
  $talla=$_POST["talla"];
  $color=$_POST["color"];
  $cantidad=$_POST["cantidad"];
  $consulta02="SELECT * FROM producto WHERE nombre_producto='$nombre_producto'";
  $consulta02=mysqli_query($link, $consulta02);
  $consulta02=mysqli_fetch_array($consulta02);
  $result=mysqli_query($link, "INSERT INTO carrito (codigo_producto, codigo_pedido, cantidad) VALUES ('$consulta02[codigo_producto]', '$consulta01[codigo_pedido]', '$cantidad')");
  if($consulta0){
	  header('Location: carrito.php');
  }
  else{
	  echo "Error";
  }
echo "<br><a href='index.php'>Volver</a></div>";
?>