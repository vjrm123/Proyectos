<?php
include "conexion.php";
function obtener_producto($nombre=FALSE){
  global $link;    
  if($nombre==FALSE){
    $result=mysqli_query($link, "SELECT p.codigo_producto, m.nombre_marca, t.nombre_talla, c.nombre_color, ct.nombre_categoria, p.nombre_producto, p.precio, p.stock FROM producto p INNER JOIN marca m ON m.codigo_marca = p.codigo_marca INNER JOIN talla t ON t.codigo_talla = p.codigo_talla INNER JOIN colores c ON c.codigo_color = p.codigo_color INNER JOIN categoria ct ON ct.codigo_categoria = p.codigo_categoria ORDER BY p.codigo_producto") or die ("Algo ha ido mal en la consulta a la base de datos");
  }else{
    $result=mysqli_query($link, "SELECT p.codigo_producto, m.nombre_marca, t.nombre_talla, c.nombre_color, ct.nombre_categoria, p.nombre_producto, p.precio, p.stock FROM producto p INNER JOIN marca m ON m.codigo_marca = p.codigo_marca INNER JOIN talla t ON t.codigo_talla = p.codigo_talla INNER JOIN colores c ON c.codigo_color = p.codigo_color INNER JOIN categoria ct ON ct.codigo_categoria = p.codigo_categoria WHERE p.nombre_producto LIKE '%$nombre%'") or die ("Algo ha ido mal en la consulta a la base de datos");
  }  
  return $result;
 }

function obtener_producto2($codigo){
  global $link;    
    $result=mysqli_query($link, "SELECT * FROM producto WHERE codigo_producto = '$codigo'") or die ("Algo ha ido mal en la consulta a la base de datos");
  return $result;
 }

function obtener_marca(){
  global $link;    
    $result=mysqli_query($link, "SELECT * FROM marca") or die ("Algo ha ido mal en la consulta a la base de datos");
  return $result;
 }

function obtener_talla(){
  global $link;    
    $result=mysqli_query($link, "SELECT * FROM talla ORDER BY codigo_talla ASC") or die ("Algo ha ido mal en la consulta a la base de datos");
  return $result;
 }

function obtener_color(){
  global $link;    
    $result=mysqli_query($link, "SELECT * FROM colores") or die ("Algo ha ido mal en la consulta a la base de datos");
  return $result;
 }

function obtener_categoria(){
  global $link;    
    $result=mysqli_query($link, "SELECT * FROM categoria") or die ("Algo ha ido mal en la consulta a la base de datos");
  return $result;
 }

function insertar_productos(){
  global $link;    
  $marca=$_POST["marca"];
  $talla=$_POST["talla"];
  $color=$_POST["color"];
  $categoria=$_POST["categoria"];
  $nombreproducto=$_POST["nombreproducto"];
  $precio=$_POST["precio"];
  $stock=$_POST["stock"];
  $descripcion=$_POST["descripcion"];
  if($nombreproducto != ""){
  $result=mysqli_query( $link, "INSERT INTO `producto` (`codigo_producto`, `codigo_marca`, `codigo_talla`, `codigo_color`, `codigo_categoria`, `nombre_producto`, `precio`, `stock`, `descripcion`) VALUES (NULL, '$marca', '$talla', '$color', '$categoria', '$nombreproducto', '$precio', '$stock', '$descripcion');" ) or die ( "Algo ha ido mal en la consulta a la base de datos");
  return true;
  }else{
      return false;
  }
 }

function insertar_cliente(){
  global $link;    
  $codpostal=$_POST["codpostal"];
  $nombre=$_POST["nombre"];
  $apellido=$_POST["apellido"];
  $dni=$_POST["dni"];
  $telefono=$_POST["telefono"];
  $correo=$_POST["correo"];
  $clave=$_POST["clave"];
  $claveHash=password_hash($clave, PASSWORD_BCRYPT);
  $direccion=$_POST["direccion"];
  $fechanacimiento=$_POST["fecha"];
  $metodo=$_POST["met"];
  $tarjeta=$_POST["tarjeta"];
  $consultacorreo="SELECT correo FROM cliente WHERE correo='$correo'";
  $consultacorreo=mysqli_query($link, $consultacorreo);
  $consultacorreo=mysqli_fetch_array($consultacorreo);
  if(!$consultacorreo){
	$consulta="INSERT INTO `cliente` (`codigo_cliente`, `codigo_postal`, `nombre_cliente`, `apellido_cliente`, `dni`, `telefono`, `correo`, `clave`, `direccion`, `fecha_nacimiento`, `numero_tarjeta`) VALUES (NULL, '$codpostal', '$nombre', '$apellido', '$dni', '$telefono', '$correo', '$claveHash', '$direccion', '$fechanacimiento', '$tarjeta')" or die ( "Algo ha ido mal en la consulta a la base de datos");
	$consulta=mysqli_query($link, $consulta);
	$consulta2="SELECT codigo_cliente FROM cliente WHERE correo='$correo'";
	$consulta2=mysqli_query($link, $consulta2);
	$consulta2=mysqli_fetch_array($consulta2);
	$consulta3="INSERT INTO `metodo_pago` (`codigo_pago`, `codigo_cliente`, `nombre_metodo`) VALUES (NULL,'$consulta2[codigo_cliente]', '$metodo');";
	$result=mysqli_query($link, $consulta3);
  return true;
  }
  else{
	  echo "Este correo ya esta registrado";
      return false;
  }
 }

function obtener_cliente($nombre=FALSE){
  global $link;    
  if($nombre==FALSE){ 
    $result=mysqli_query($link, "SELECT * FROM cliente") or die ("Algo ha ido mal en la consulta a la base de datos");
  }else{
    $result=mysqli_query($link, "SELECT * FROM cliente") or die ("Algo ha ido mal en la consulta a la base de datos");
  }  
  return $result;
 }

 function registrar_actividad($id_admin, $accion, $conn) {
  $sql = "INSERT INTO registro_actividades (id_admin, accion) VALUES (?, ?)";
  $stmt = $conn->prepare($sql);
  $stmt->bind_param("is", $id_admin, $accion);

  if ($stmt->execute()) {
      echo "Actividad registrada.";
  } else {
      echo "Error al registrar la actividad.";
  }
}

function insertar_admin() {
  global $link;

  $nombre = $_POST["nombre"];
  $email = $_POST["correo"];
  $password = $_POST["clave"];
  $rol = $_POST["rol"];
  $passwordHash = password_hash($password, PASSWORD_BCRYPT);

  // Validar datos
  if (empty($nombre) || empty($email) || empty($password) || empty($rol)) {
      echo "Todos los campos son obligatorios.";
      return false;
  }

  // Validar si el correo ya existe
  $consultaCorreo = "SELECT email FROM administrar_usiarios WHERE email = '$email'";
  $resultadoCorreo = mysqli_query($link, $consultaCorreo);

  if (!$resultadoCorreo) {
      die("Error en la consulta de correo: " . mysqli_error($link));
  }

  $correoExiste = mysqli_fetch_array($resultadoCorreo);

  if (!$correoExiste) {
      // Insertar administrador
      $consulta = "INSERT INTO administrar_usiarios (nombre, email, password, rol) 
                  VALUES ('$nombre', '$email', '$passwordHash', '$rol')";

      if (mysqli_query($link, $consulta)) {
          echo "Administrador insertado correctamente.";
          return true;
      } else {
          die("Error al insertar administrador: " . mysqli_error($link));
      }
  } else {
      echo "El correo electrónico ya está registrado.";
      return false;
  }
}


?>