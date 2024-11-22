<?php 
include "productos_model.php";
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SAMM Tienda de Ropa</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
    <link rel="stylesheet" href="css/cliente.css">
</head>
<body>
<!-- Start Top Bar -->
<div class="top-bar" id="mainNavigation">
  <div class="top-bar-left">
    <ul class="menu vertical medium-horizontal">
      <a href="administrador.php">.</a>
    </ul>
  </div>
  <div class="top-bar-right">
    <ul class="menu vertical medium-horizontal">
    </ul>
  </div>
</div>
<!-- End Top Bar -->

<main>
    <?php
    if($_POST){
        if(insertar_cliente()){
            echo "Se registró correctamente";
        }else{
            echo " ";
        }
    }
    ?>
    <section id="formulario2" style="display: block;">
        <h2>Iniciar sesión</h2>
        <form name="contacto" method="post" action="IniciarSesion.php">
            <p>Correo:</p>
            <input type="email" name="usuario" placeholder="Ingrese su correo" required>
            <p>Contraseña:</p>
            <input type="password" name="clave" autocomplete="off" placeholder="Ingrese su contraseña" required>
            <input type="submit" name="enviar" class="btn" value="Iniciar Sesión">
        </form>    
        <p style="text-align: center;" class="texto-negro">
            ¿No tienes una cuenta? <a href="#" id="showRegister">Regístrate aquí </a>
            <a href="registrar_Admi.php"><i class="fas fa-smile"></i></a>
        </p>
    </section>
    <section id="formulario" style="display: none;">
        <h2>Regístrate</h2>
        <form action="cliente.php" method="post" name="miform2">
            <p>Código Postal:</p>
            <select name="codpostal" required>
                <option value="1">J.L.B. y Rivero</option>
                <option value="2">Paucarpata</option>
                <option value="3">Selva Alegre</option>
                <option value="4">Cerro Colorado</option>
                <option value="5">Cayma</option>
            </select>
            <p>Nombre:</p>
            <input type="text" name="nombre" placeholder="Ingrese su nombre" required>
            <p>Apellido:</p>
            <input type="text" name="apellido" placeholder="Ingrese su apellido" required>
            <p>DNI:</p>
            <input type="text" name="dni" pattern="[a-zA-Z0-9]+" placeholder="Ingrese su DNI" required>
            <p>Teléfono:</p>
            <input type="text" name="telefono" pattern="[a-zA-Z0-9]+" placeholder="Ingrese su teléfono" required>
            <p>Correo:</p>
            <input type="email" name="correo" placeholder="Ingrese su correo" required>
            <p>Clave:</p>
            <input type="password" name="clave" autocomplete="new-password" placeholder="Ingrese su clave" required>
            <p>Dirección:</p>
            <input type="text" name="direccion" placeholder="Ingrese su dirección" required>
            <p>Fecha de Nacimiento:</p>
            <input type="date" name="fecha" required>
            <p>Método de pago:</p>
            <input type="text" name="met" placeholder="Ingrese su método de pago" required>
            <p>Número de Tarjeta:</p>
            <input type="number" name="tarjeta" placeholder="Ingrese su número de tarjeta" required>
            <input type="submit" name="enviar" class="btn" value="Regístrate">
        </form>
        <p style="text-align: center;" class="texto-negro">
            ¿Ya tienes una cuenta? <a href="#" id="showLogin">Inicia sesión aquí</a>
        </p>
    </section>
</main>

<script src="js/cliente.js"></script>

</body>
</html>
