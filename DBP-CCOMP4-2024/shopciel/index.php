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
      <a href="mujer.php"><img id="sombra" src="img/mujer2.png" width="40px"></a>
      <a href="hombre.php"><img id="sombra" src="img/hombre2.png" width="40px"></a>
      <a href="administrador.php">.</a>
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
      <a href="carrito.php"><img id="sombra" src="img/carrito.png" width="50px"></a>
      <a href="CerrarSesion.php"><img id="sombra" src="img/cerrar.png" width="113px"></a>
      </ul>
  </div>
    <p style="font-family:tahoma">
      <?php echo "$_SESSION[nombre]";?>
</div>
<!-- End Top Bar -->
<div class="orbit" role="region" aria-label="Favorite Space Pictures" data-orbit data-options="animInFromLeft:fade-in; animInFromRight:fade-in; animOutToLeft:fade-out; animOutToRight:fade-out;">
  <ul class="orbit-container">
    <button class="orbit-previous"><span class="show-for-sr">Previous Slide</span>&#9664;&#xFE0E;</button>
    <button class="orbit-next"><span class="show-for-sr">Next Slide</span>&#9654;&#xFE0E;</button>
    <li class="is-active orbit-slide">
      <img class="orbit-image" src="img/fondo4.png" alt="Space">
    </li>
    <li class="orbit-slide">
      <img class="orbit-image" src="img/fondo3.png" alt="Space">
    </li>
    <li class="orbit-slide">
      <img class="orbit-image" src="img/fondo2.png" alt="Space">
    </li>
    <li class="orbit-slide">
      <img class="orbit-image" src="img/fondo1.png" alt="Space">
    </li>
  </ul>
  <nav class="orbit-bullets">
    <button class="is-active" data-slide="0"><span class="show-for-sr">First slide details.</span><span class="show-for-sr">Current Slide</span></button>
    <button data-slide="1"><span class="show-for-sr">Second slide details.</span></button>
    <button data-slide="2"><span class="show-for-sr">Third slide details.</span></button>
    <button data-slide="3"><span class="show-for-sr">Fourth slide details.</span></button>
  </nav>
</div>
<input type="checkbox" id="cerrar">
    <label for="cerrar" id="btn-cerrar">Cerrar</label>
        <div class="modal">
			<div class="contenido">
				<img src="img/anuncio2.webp">
			</div>
		</div>
<br>
<div class="text-center">
  <p style="font-family:roman">
  ¡Nuestros Productos!
  </p>
  <hr>
</div>
<article class="grid-container">
  <div class="grid-x grid-margin-x small-up-2 medium-up-2 large-up-4">
  <?php
  //PROCEDURE
  $buscar = $_POST ? $_POST["buscar"] : null;
  $Nou = $link->prepare("CALL obtener_producto(?)");
  $Nou->bind_param("s", $buscar);  
  $Nou->execute();
  $resultado = $Nou->get_result();
while($row = mysqli_fetch_array($resultado)) { ?>
    <div class="cell">
      <img class="thumbnail" src="img/<?php echo $row['codigo_producto'];?>.jpeg">
      <p style="font-family:tahoma">
      <?php echo $row['nombre_producto']; ?>
        <br>
      <?php echo 'S/. '; echo $row['precio']; ?>
      </p>
      <a href="detalle1.php?codigo=<?php echo $row['codigo_producto'];?>"><img id="extra" src="img/comprar.png"></a>
      <br><br>
    </div>
<?php }
$Nou->close();
?>

  </div>
<br>    
    </article>
    <img id="img-center" src="img/redes.png">
    <br>
    <hr>
    <footer>
    <p id="pie" style="font-family:tahoma">
    &copy; 2024, Shopciel Todos los derechos reservados
    </p>
    </footer>
    <script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
</body>
</html>