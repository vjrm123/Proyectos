<?php 
include "productos_model.php";
session_start();

if (!isset($_SESSION['rol']) || $_SESSION['rol'] !=='superadmin') {
    echo "No tienes permisos para agregar productos.";
    exit;
}
?>
<!doctype html>
<html class="no-js" lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ingresar producto</title>
    <link rel="stylesheet" href="css/foundation.css">
</head> 
<body>
<!-- Start Top Bar -->
<div class="top-bar" id="mainNavigation">
  <div class="top-bar-left">
    <ul class="menu vertical medium-horizontal">
      
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
    <h3>INGRESAR PRODUCTO</h3>
    </div>
<?php
if($_POST){
    if(insertar_productos()){
   	 echo "Se inserto correctamente";
    }else{
   	 echo "Hubo un error";
    }
}
?>
<!-- End Top Bar -->
<form action="ingresar_producto.php" method="post" name="miform">
    Marca:
    <select name="marca">
        <?php
        $resultado=obtener_marca();
        while($row=mysqli_fetch_array($resultado)){?> 
        <option value="<?php echo $row['codigo_marca'];?>"><?php echo $row['nombre_marca'];?></option>
        <?php }?>
    </select>
    <br>
    Talla:
    <select name="talla">
        <?php
        $resultado=obtener_talla();
        while($row=mysqli_fetch_array($resultado)){?> 
        <option value="<?php echo $row['codigo_talla'];?>"><?php echo $row['nombre_talla'];?></option>
        <?php }?>
    </select>
    <br>
    Color:
    <select name="color">
        <?php
        $resultado=obtener_color();
        while($row=mysqli_fetch_array($resultado)){?> 
        <option value="<?php echo $row['codigo_color'];?>"><?php echo $row['nombre_color'];?></option>
        <?php }?>
    </select>
    <br>
    Categoría:
    <select name="categoria">
        <?php
        $resultado=obtener_categoria();
        while($row=mysqli_fetch_array($resultado)){?> 
        <option value="<?php echo $row['codigo_categoria'];?>"><?php echo $row['nombre_categoria'];?></option>
        <?php }?>
    </select>
    <br>
    Nombre del producto:
    <input type="text" name="nombreproducto">
    <br>
    Precio:
    <input type="number" name="precio">
    <br>
    Stock:
    <input type="number" name="stock">
    <br>
    Descripción:
    <textarea name="descripcion"></textarea>
    <input type="submit" name="enviar" value="Enviar">
</form>
    <script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
</body>
</html>
