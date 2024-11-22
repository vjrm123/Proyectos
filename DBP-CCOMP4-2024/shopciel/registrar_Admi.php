
<?php 
include "conexion.php";
include "productos_model.php";
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registro de Administradores</title>
    <link rel="stylesheet" href="css/cliente.css">
</head>
<body>
<main>
<?php
if ($_POST) {
    if(insertar_admin()){
        echo "Se registró correctamente";
    }else{
        echo " ";
    }
}
?>
    <section id="formulario2" style="display: block;">
        <h2>Iniciar sesión como Administrador</h2>
        <form name="adminLogin" method="post" action="iniciarSesion_Admi.php">
            <p>Correo de administrador:</p>
            <input type="email" name="admin_email" placeholder="Ingrese su correo" required>
            <p>Contraseña:</p>
            <input type="password" name="admin_clave" autocomplete="off" placeholder="Ingrese su contraseña" required>
            <input type="submit" name="enviar" class="btn" value="Iniciar Sesión">
        </form>    
        <p style="text-align: center;" class="texto-negro">
            ¿No tienes una cuenta? <a href="#" id="showAdminRegister">Regístrate aquí como administrador</a>
        </p>
    </section>

    <section id="formulario" style="display: none;">
        <h2>Regístrate como Administrador</h2>
        <form action="registrar_Admi.php" method="POST" name="adminRegisterForm">
            <p>Nombre:</p>
            <input type="text" name="nombre" placeholder="Ingrese su nombre" required>
            <p>Correo:</p>
            <input type="email" name="correo" placeholder="Ingrese su correo" required>
            <p>Clave:</p>
            <input type="password" name="clave" autocomplete="new-password" placeholder="Ingrese su clave" required>
            <p>Rol:</p>
            <select name="rol" required>
                <option value="editor">Editor</option>
                <option value="soporte">Soporte</option>
                <option value="superadmin">Superadmin</option>
            </select>
            <input type="submit" name="enviar" class="btn" value="Regístrate">
        </form>
        <p style="text-align: center;" class="texto-negro">
            ¿Ya tienes una cuenta? <a href="#" id="showAdminLogin">Inicia sesión aquí</a>
        </p>
    </section>
</main>

<script>
document.getElementById('showAdminRegister').addEventListener('click', function(e) {
    e.preventDefault();
    document.getElementById('formulario').style.display = 'block';
    document.getElementById('formulario2').style.display = 'none';
});

document.getElementById('showAdminLogin').addEventListener('click', function(e) {
    e.preventDefault();
    document.getElementById('formulario').style.display = 'none';
    document.getElementById('formulario2').style.display = 'block';
});
</script>

</body>
</html>
