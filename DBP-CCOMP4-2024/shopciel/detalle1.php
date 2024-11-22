<?php 
include "productos_model.php";
include "validarSesion.php";
?>
<?php
$id = $_GET["codigo"];
$resultado = obtener_producto2($id);
$producto = mysqli_fetch_array($resultado);
?>
<!doctype html>
<html class="no-js" lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Productos</title>
    <link rel="stylesheet" href="css/foundation.css">
    <link rel="icon" href="img/icono.ico">
</head>
<body>
<!-- Start Top Bar -->
    <div class="top-bar">
        <div class="top-bar-left">
            <ul class="dropdown menu" data-dropdown-menu>
                <img src="img/logo2.png" width="65px">
                <a href="index.php"><img id="sombra" src="img/inicio.png" width="50px"></a>
                <a href="carrito.php"><img id="sombra" src="img/carrito.png" width="50px"></a>
                <a href="administrador.php">.</a>
            </ul>
        </div>
        <div class="top-bar-right">
            <ul class="menu">
                <a>
                <form action="index.php" method="post">
                    <input type="text" name="buscar" placeholder="Buscar">
                    <input type="image" src="img/buscar.png" id="sombra" width="50px">
                </form>
                </a>
            </ul>
        </div>
        <p style="font-family:tahoma">
        <?php echo "$_SESSION[nombre]"; ?>
    </div>
<!-- End Top Bar -->
    <br>
    <article class="grid-container">
        <div class="grid-x grid-margin-x">
            <div class="medium-6 cell">
                <!-- Aquí se muestra la imagen principal del producto o una imagen por defecto -->
                <img class="thumbnail" src="img/<?php echo file_exists("img/".$producto['codigo_producto'].".jpeg") ? $producto['codigo_producto'].".jpeg" : "default.jpg"; ?>" alt="Producto">
                
                <div class="grid-x grid-padding-x small-up-4">
                    <div class="cell">
                        <img class="thumbnail" src="img/<?php echo file_exists("img/".$producto['codigo_producto'].".1.jpeg") ? $producto['codigo_producto'].".1.jpeg" : "default.jpg"; ?>" alt="Producto">
                    </div>
                    <div class="cell">
                        <img class="thumbnail" src="img/<?php echo file_exists("img/".$producto['codigo_producto'].".2.jpeg") ? $producto['codigo_producto'].".2.jpeg" : "default.jpg"; ?>" alt="Producto">
                    </div>
                    <div class="cell">
                        <img class="thumbnail" src="img/<?php echo file_exists("img/".$producto['codigo_producto'].".3.jpeg") ? $producto['codigo_producto'].".3.jpeg" : "default.jpg"; ?>" alt="Producto">
                    </div>
                </div>
            </div>
            <div class="medium-6 large-5 cell large-offset-1">
                <h3><?php echo $producto['nombre_producto']; ?></h3>
                <p><?php echo $producto['descripcion']; ?></p>
                <form action="AgregarCarrito.php" method="post" name="formulario_agregar">
                    <input type="hidden" name="producto" value="<?php echo $producto['nombre_producto']; ?>" id="sombra">
                    <label>Talla
                        <select name="talla">
                        <?php
                        $resultado = obtener_talla();
                        while ($row = mysqli_fetch_array($resultado)) { ?> 
                        <option value="<?php echo $row['codigo_talla']; ?>"><?php echo $row['nombre_talla']; ?></option>
                        <?php } ?>
                        </select>
                    </label>
                    <label>Color
                        <select name="color">
                        <?php
                        $resultado = obtener_color();
                        while ($row = mysqli_fetch_array($resultado)) { ?> 
                        <option value="<?php echo $row['codigo_color']; ?>"><?php echo $row['nombre_color']; ?></option>
                        <?php } ?>
                        </select>
                    </label>
                    <div class="grid-x">
                        <div class="small-3 cell">
                            <label for="middle-label" class="middle">Cantidad</label>
                            <br>
                        </div>
                        <div class="small-9 cell">
                            <input type="number" name="cantidad" id="middle-label" placeholder="Escribir...">
                        </div>
                    </div>
                    <input type="image" id="compras" src="img/alcarrito.png" width="250px">
                </form>
            </div>
        </div>
        <hr>
        <span>
            <p id="pie" style="font-family:tahoma">
            &copy; 2024, Shopciel Todos los derechos reservados 
            </p>        
        </span>
    </article>
    <script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
</body>
</html>
