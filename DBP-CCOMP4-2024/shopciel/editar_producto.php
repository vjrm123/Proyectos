<?php 
include "productos_model.php";
$cod=$_GET['cod'];
$producto="SELECT p.codigo_producto, m.nombre_marca, t.nombre_talla, c.nombre_color, ct.nombre_categoria, p.nombre_producto, p.precio, p.stock FROM producto p INNER JOIN marca m ON m.codigo_marca = p.codigo_marca INNER JOIN talla t ON t.codigo_talla = p.codigo_talla INNER JOIN colores c ON c.codigo_color = p.codigo_color INNER JOIN categoria ct ON ct.codigo_categoria = p.codigo_categoria WHERE codigo_producto='$cod'";
$resultado2=mysqli_query($link,$producto);
?>
<!doctype html>
<html class="no-js" lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Modificar producto</title>
    <link rel="stylesheet" href="css/foundation.css">
    <link rel="icon" href="img/icono.ico">
</head> 
<body>
<!-- Start Top Bar -->
<div class="title-bar" data-responsive-toggle="mainNavigation" data-hide-for="medium">
  <div class="title-bar-left">
    <button class="menu-icon" type="button" data-toggle="mainNavigation"></button>
    <div class="title-bar-title">Menu</div>
  </div>
  <div class="title-bar-right">
    Modificar producto
  </div>
</div>
<div class="top-bar" id="mainNavigation">
  <div class="top-bar-left">
    <ul class="menu vertical medium-horizontal">
      <img src="img/logo.png" width="65px">
    </ul>
  </div>
  <div class="top-bar-right">
    <ul class="menu vertical medium-horizontal">
       <a href="administrador.php"><img id="sombra" src="img/adm.png" width="120px"></a>
      <a href="index.php"><img id="sombra" src="img/inicio.png" width="50px"></a>
    </ul>
  </div>
</div>
    <div class="titulo">
    <h3>PANEL DE EDICION</h3>
    </div>
<!-- End Top Bar -->
<table id="tabla" border=2>
<tr>
<td id="negrita">Código Producto</td>
<td id="negrita">Marca</td>
<td id="negrita">Talla</td>
<td id="negrita">Color</td>
<td id="negrita">Categoría</td>
<td id="negrita">Producto</td>
<td id="negrita">Precio (S/.)</td>
<td id="negrita">Stock (und)</td>
</tr>
<form action="procesar_edicion.php" method="post">
<?php
while($row2=mysqli_fetch_array($resultado2)){?>
<tr>
<td><input type="hidden" name="cod" value="<?php echo $row2['codigo_producto'];?>"></td>
<td>
 <select name="marca" value="<?php echo $row['nombre_marca'];?>">
    <?php
    $resultado=obtener_marca();
    while($row=mysqli_fetch_array($resultado)){?> 
    <option value="<?php echo $row['codigo_marca'];?>"><?php echo $row['nombre_marca'];?></option>
    <?php }?>
    </select>
</td>
<td>
  <select name="talla" value="<?php echo $row['nombre_talla'];?>">
    <?php
    $resultado=obtener_talla();
    while($row=mysqli_fetch_array($resultado)){?> 
    <option value="<?php echo $row['codigo_talla'];?>"><?php echo $row['nombre_talla'];?></option>
    <?php }?>
    </select>
</td>
<td>
 <select name="color" value="<?php echo $row['nombre_color'];?>">
    <?php
    $resultado=obtener_color();
    while($row=mysqli_fetch_array($resultado)){?> 
    <option value="<?php echo $row['codigo_color'];?>"><?php echo $row['nombre_color'];?></option>
    <?php }?>
    </select>
</td>
<td>
 <select name="categoria" value="<?php echo $row['nombre_categoria'];?>">
    <?php
    $resultado=obtener_categoria();
    while($row=mysqli_fetch_array($resultado)){?> 
    <option value="<?php echo $row['codigo_categoria'];?>"><?php echo $row['nombre_categoria'];?></option>
    <?php }?>
    </select>
</td>
<td><input type="text" name="nombreproducto" value="<?php echo $row2['nombre_producto'];?>"></td>
<td><input type="number" step="0.01" name="precio" min="0" value="<?php echo $row2['precio'];?>"></td>
<td><input type="number" name="stock" min="0" value="<?php echo $row2['stock'];?>"></td>
<td><input type="submit" name="actualizar" value="Actualizar"></td>
</tr>  
<?php }?>
</form>
</table>
    <br>
    <script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
</body>
</html>