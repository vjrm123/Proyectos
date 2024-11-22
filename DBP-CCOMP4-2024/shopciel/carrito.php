<?php 
include "productos_model.php";
include "validarSesion.php";
?>
<!doctype html>
<html class="no-js" lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SAMM Tienda de Ropa</title>
    <link rel="stylesheet" href="css/foundation.css">
    <link rel="icon" href="img/icono.ico">
</head>
<body>
<!-- Start Top Bar -->
<div class="top-bar" id="mainNavigation">
  <div class="top-bar-left">
    <ul class="menu vertical medium-horizontal">
      <img src="img/logo2.png" width="65px">
	  <section id="sombra">
	  </section>
    </ul>
  </div>
  <div class="top-bar-right">
    <ul class="menu vertical medium-horizontal">
        <a>
<form action="index.php" method="post">
<input type="text" name="buscar" placeholder="Buscar">
<input type="image" src="img/buscar.png" id="sombra" width="50px">
</form>
        </a>
      <a href="index.php"><img id="sombra" src="img/inicio.png" width="50px"></a>
    </ul>
  </div>
    <p style="font-family:tahoma">
      <?php echo "$_SESSION[nombre]";?>
</div>
<!-- End Top Bar -->
<div class="text-center">
  <p style="font-family:roman">
  </p>
  <hr>
</div>
<article class="grid-container">
  <div class="grid-x grid-margin-x small-up-2 medium-up-2 large-up-4">
<?php
$consulta="SELECT * FROM producto pr INNER JOIN carrito c ON pr.codigo_producto=c.codigo_producto INNER JOIN pedido p ON c.codigo_pedido=p.codigo_pedido INNER JOIN cliente cl ON cl.codigo_cliente=p.codigo_cliente WHERE cl.correo='$ce'";
$datos=mysqli_query($link, $consulta);
while($fila=mysqli_fetch_array($datos)){
?>
    <div class="cell">
      <img class="thumbnail" src="img/<?php echo $fila['codigo_producto'];?>.jpeg">
      <p style="font-family:tahoma">
      <?php echo $fila['nombre_producto'];?>
      <br>
      <?php echo 'S/. '; echo $fila['precio'];?>
      <br>
      <?php echo 'Cantidad: '; echo $fila['cantidad'];?>
      </p>
        <br>
        </div>
<?php }?>
  </div> 
    </article>
    <br>
    <img id="img-center" src="img/redes.png">
        <br>
    <hr>
    <footer>
    <p id="pie" style="font-family:tahoma">
    &copy; 2024, Nou Todos los derechos reservados
    </p>
    </footer>
    <script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
</body>
</html>