<?php
session_start(); 
?>
<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/app.css">
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
    <title>Administrador</title>
</head>

<body>

    <!--SIDEBAR -->
    <section id="sidebar">
    <a href="#" class="brand">
        <i class="bx bxs-smile"></i>
        <span class="text">shop</span>
    </a>

    <ul class="side-menu top">
        <li class="active">
            <a href="#" onclick="mostrarSeccion('general', this)">
                <i class="bx bxs-dashboard"></i>
                <span class="text"><strong>General</strong></span>
            </a>
        </li>

        <li>
            <a href="#" onclick="mostrarSeccion('clientes', this)">
                <i class="bx bxs-user"></i>
                <span class="text"><strong>Clientes</strong></span>
            </a>
        </li>
        <li>
            <a href="#" onclick="mostrarSeccion('pedidos', this)">
                <i class="bx bxs-cart"></i>
                <span class="text"><strong>Pedidos</strong></span>
            </a>
        </li>
        <li>
            <a href="#" onclick="mostrarSeccion('productos', this)">
                <i class="bx bxs-store"></i>
                <span class="text"><strong>ver producto</strong>s</span>
            </a>
        </li>
        <li>
            <a href="ingresar_producto.php" onclick="mostrarSeccion('productos', this)">
                <i class="bx bxs-add-to-queue"></i>
                <span class="text"><strong>agregar producto</strong></span>
            </a>
        </li>
        <li>
            <a href="#" onclick="mostrarSeccion('Administradores', this)">
                <i class="bx bxs-user-circle"></i>
                <span class="text"><strong>Administradores</strong></span>
            </a>
        </li>
    </ul>

    <ul class="side-menu">
        <li>
            <a href="CerrarSesion.php" class="logout">
                <i class="bx bxs-log-out-circle"></i>
                <span class="text"><strong>Cerrar Sesión</strong></span>
            </a>
        </li>
    </ul>
</section>


    <!--SIDEBAR END-->

    <!--Contenu-->
    <section id="content">
        <!--navbar-->
        <nav>
            <i class="bx bx-menu"></i>
            <a href="#" class="nav-link">Categorías</a>
            <form action="administrador.php" method="post">
                <div class="form-input">
                    
                    <input  type="search" name="buscar" placeholder="Buscar...">
                    <button type="submit" class="search-btn"><i class="bx bx-search"></i> </button>
                    
                </div>
            </form>
            <input type="checkbox" id="swith-mode" hidden>
            <label for="swith-mode" class="swith-mode"></label>
            <a href="#" class="notification">
                <i class="bx bxs-bell"></i>
                <span class="num">3</span>
            </a>
            <a href="#" class="profile">
                <img src="img/profil.png" alt="Foto de perfil">
            </a>
        </nav>
        <!--navbar end-->

        <!--Main-->
        <main>
            <!-- Sección General -->
            <div id="general" class="seccion">
                <div class="head-title">
                    <div class="left">
                        <h1>General</h1>
                        <ul class="breadcrumb">
                            <li><a href="#">General</a></li>
                            <li><i class="bx bx-chevron-right"></i></li>
                            <li><a class="active" href="#">Inicio</a></li>
                        </ul>
                    </div>
                    <a href="#" class="btn-download">
                        <i class="bx bxs-cloud-download"></i>
                        <span class="text">HISTORIAL</span>
                    </a>
                </div>

                <ul class="box-info">
                        <?php
                        include 'conexion.php';
                        $recibido = "CALL obtener_cantidad_pedidos()";
                        $resultado = $link->query($recibido);
                        $cantidad_pedidos = 0;
                        if ($resultado) {
                            $nose = $resultado->fetch_assoc();
                            $cantidad_pedidos = $nose['total_pedidos']; 
                        }
                        $link->close();
                        ?>

                        <li>
                            <i class="bx bxs-calendar-check"></i>
                            <span class="text">
                                <h3><?php echo $cantidad_pedidos; ?></h3>
                                <p>Nuevos Pedidos</p>
                            </span>
                        </li>
                        <?php
                        include 'conexion.php';
                        $recibido = "CALL obtener_cantidad_clientes()";
                        $resultado = $link->query($recibido);
                        $cantidad_clientes = 0;
                        if ($resultado) {
                            $nose = $resultado->fetch_assoc();
                            $cantidad_clientes = $nose['cantidad_clientes']; 
                        }
                        $link->close();
                        ?>
                    <li>
                        <i class="bx bxs-group"></i>
                        <span class="text">
                            <h3><?php echo $cantidad_clientes; ?></h3>
                            <p>Clientes</p>
                        </span>
                    </li>
                    <?php
                        include 'conexion.php';
                        $recibido = "CALL TotalVentasDelMesActual()";
                        $resultado = $link->query($recibido);
                        $cantidad_pedidos = 0;
                        if ($resultado) {
                            $nose = $resultado->fetch_assoc();
                            $cantidad_ventas = $nose['total_ventas']; 
                        }
                        $link->close();
                        ?>
                    <li>
                        <i class="bx bxs-dollar-circle"></i>
                        <span class="text">
                            <h3>$ <?php echo $cantidad_ventas; ?></h3>
                            <p>Total Ventas</p>
                        </span>
                    </li>
                </ul>

                <div class="table-data">
                    <div class="order">
                        <div class="head">
                            <h3>Pedidos recientes</h3>
                            <i class="bx bx-search"></i>
                            <i class="bx bx-filter"></i>
                        </div>
                        <table>
                            <thead>
                                <tr>
                                    <th>Nombre Cliente</th>
                                    <th>Fecha Pedido</th>
                                    <th>Estado</th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                include 'conexion.php';
                                $query = "CALL obtener_pedidos_recientes";
                                $resultado = $link->query($query);

                                if ($resultado && $resultado->num_rows > 0) {
                                    while ($row = $resultado->fetch_assoc()) {
                                        $estado = $row['estado_pedido'];
                                        $clase_estado = match ($estado) {
                                            'enviado' => 'completed',
                                            'en proceso' => 'process',
                                            default => 'pending',
                                        };
                                        ?>
                                        <tr>
                                            <td><?php echo htmlspecialchars($row['nombre_cliente']); ?></td>
                                            <td><?php echo htmlspecialchars($row['fecha_pedido']); ?></td>
                                            <td><span class="status <?php echo $clase_estado; ?>"><?php echo ucfirst(htmlspecialchars($estado)); ?></span></td>
                                        </tr>
                                        <?php
                                    }
                                } else {
                                    echo "<tr><td colspan='3'>No hay pedidos recientes</td></tr>";
                                }
                                $link->close(); 
                                ?>
                            </tbody>
                        </table>
                    </div>
                

                    <div class="todo">
                        <div class="head">
                            <h3>Lista de tareas</h3>
                            <i class="bx bx-plus" onclick="mostrarFormulario()"></i>
                            <i class="bx bx-filter"></i>
                        </div>
                        <ul class="todo-list">
                            <?php
                            include("conexion.php");
                            $email = $_SESSION['email']; 
                            $query = "SELECT * FROM tareas WHERE asignada_a='$email'";
                            $resultado = mysqli_query($link, $query);

                            while ($row = mysqli_fetch_assoc($resultado)) {
                                $estado = $row['estado'] === 'completada' ? 'completed' : 'not-completed';
                                echo "<li class='$estado'>
                                        <p>{$row['tarea']} <br> 
                                        <small>Asignada por: {$row['superadmin']}</small>
                                        </p>
                                        <form action='actualizar_tarea.php' method='post' style='display: inline;'>
                                            <input type='hidden' name='id' value='{$row['id']}'>
                                            <button type='submit' name='estado' value='completada'>Marcar como completada</button>
                                        </form>
                                        <i class='bx bx-dots-vertical-rounded'></i>
                                    </li>";
                            }
                            ?>
                        </ul>
                        <div class="formulario-tareas" id="formulario-tareas" style="display: none;">
                            <h3>Asignar Tarea</h3>
                            <form action="asignarTarea_Admi.php" method="post">
                                <label for="tarea">Descripción de la tarea:</label>
                                <textarea name="tarea" id="tarea" required></textarea>
                                <br>
                                <label for="admin">Asignar a:</label>
                                <select name="admin" id="admin" required>
                                    <?php
                                    $resultado = mysqli_query($link, "SELECT nombre, email FROM administrar_usiarios WHERE rol='editor'");
                                    while ($row = mysqli_fetch_assoc($resultado)) {
                                        echo "<option value='{$row['email']}'>{$row['nombre']} ({$row['email']})</option>";
                                    }
                                    ?>
                                </select>
                                <br>
                                <button type="submit">Asignar Tarea</button>
                            </form>
                        </div>
                        <div class="seguimiento-tareas">
                            <h3>Seguimiento de Tareas</h3>
                            <table>
                                <thead>
                                    <tr>
                                        <th>Tarea</th>
                                        <th>Asignada a</th>
                                        <th>Estado</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    $query = "SELECT t.tarea, t.estado, u.nombre AS asignada_a FROM tareas t INNER JOIN administrar_usiarios u ON t.asignada_a = u.email";
                                    $resultado = mysqli_query($link, $query);
                                    while ($row = mysqli_fetch_assoc($resultado)) {
                                        $estado = $row['estado'] === 'completada' ? 'Completada' : 'Pendiente';
                                        echo "<tr>
                                                <td>{$row['tarea']}</td>
                                                <td>{$row['asignada_a']}</td>
                                                <td>$estado</td>
                                                </tr>";
                                    }
                                    ?>
                                </tbody>
                            </table>
                        </div>

                    </div>

            </div>
            </div>

            <!-- Sección Productos -->
            <div id="productos" class="seccion">
                <div class="table-data">
                    <div class="order">
                        <div class="head">
                            <h3>Productos</h3>
                            <i class="bx bx-search"></i>
                            <i class="bx bx-filter"></i>
                        </div>
                        <table>
                            <thead>
                                <tr>
                                    <th>Producto</th>
                                    <th>Marca</th>
                                    <th>Talla</th>
                                    <th>Color</th>
                                    <th>Precio</th>
                                    <th>Stock</th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                include 'conexion.php';
                                $buscars = $_POST ? $_POST["buscar"] : null;
                                $Nou = $link->prepare("CALL obtener_producto(?)");
                                $Nou->bind_param("s", $buscars);  
                                $Nou->execute();
                                $resultados = $Nou->get_result();
                                while ($row = mysqli_fetch_array($resultados)) { ?>
                                <tr>
                                    <td><?php echo $row['nombre_producto']; ?></td>
                                    <td><?php echo $row['nombre_marca']; ?></td>
                                    <td><?php echo $row['nombre_talla']; ?></td>
                                    <td><?php echo $row['nombre_color']; ?></td>
                                    <td>S/. <?php echo $row['precio']; ?></td>
                                    <td><?php echo $row['stock']; ?> unidades</td>
                                    <td>
                                        <a href="editar_producto.php?cod=<?php echo $row['codigo_producto'];?>">
                                            <i class='bx bx-edit' style="font-size: 24px; color: #4CAF50;"></i>
                                        </a>
                                        <a href="borrar_producto.php?codigo=<?php echo $row['codigo_producto'];?>">
                                            <i class='bx bx-trash' style="font-size: 24px; color: #f44336;"></i>
                                        </a>
                                    </td>

                                </tr>
                                <?php } $link->close(); ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
            <div id="clientes" class="seccion">
                <div class="table-data">
                    <div class="order">
                        <div class="head">
                            <h3>Clientes</h3>
                            <i class="bx bx-search"></i>
                            <i class="bx bx-filter"></i>
                        </div>
                        <table>
                            <thead>
                                <tr>
                                    <th>Código</th>
                                    <th>Nombre</th>
                                    <th>Apellido</th>
                                    <th>DNI</th>
                                    <th>Código Postal</th>
                                    <th>direccion</th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                include 'conexion.php'; 
                                $stmt = $link->prepare("CALL obtener_clientes()");
                                $stmt->execute();
                                $resultado = $stmt->get_result();
                                while ($row = $resultado->fetch_assoc()) { ?>
                                    <tr>
                                        <td><?php echo $row['codigo_cliente']; ?></td>
                                        <td><?php echo $row['nombre_cliente']; ?></td>
                                        <td><?php echo $row['apellido_cliente']; ?></td>
                                        <td><?php echo $row['dni']; ?></td>
                                        <td><?php echo $row['codigo_postal']; ?></td>
                                        <td><?php echo $row['direccion']; ?></td>
                                    </tr>
                                <?php } 
                                $stmt->close();
                                $link->close();
                                ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
            <div id="Administradores" class="seccion">
                <div class="table-data">
                    <div class="order">
                        <div class="head">
                            <h3>Clientes</h3>
                            <i class="bx bx-search"></i>
                            <i class="bx bx-filter"></i>
                        </div>
                        <table>
                            <thead>
                                <tr>
                                    <th>Nombre</th>
                                    <th>Correo</th>
                                    <th>Rol</th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                include 'conexion.php'; 
                                $stmt = $link->prepare("CALL SeleccionarAdministradores()");
                                $stmt->execute();
                                $resultado = $stmt->get_result();
                                while ($row = $resultado->fetch_assoc()) { ?>
                                    <tr>
                                        <td><?php echo $row['nombre']; ?></td>
                                        <td><?php echo $row['email']; ?></td>
                                        <td><?php echo $row['rol']; ?></td>
                                    </tr>
                                <?php } 
                                $stmt->close();
                                $link->close();
                                ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
            <div id="pedidos" class="seccion">
                <div class="table-data">
                    <div class="order">
                        <div class="head">
                            <h3>Pedidos</h3>
                            <i class="bx bx-search"></i>
                            <i class="bx bx-filter"></i>
                        </div>
                        <table>
                            <thead>
                                <tr>
                                    <th>Cliente</th>
                                    <th>Producto</th>
                                    <th>cantidad</th>
                                    <th>precio_unitario</th>
                                    <th>precio_total</th>
                                    <th>Fecha pedido</th>
                                    <th>Estado</th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                include 'conexion.php'; 
                                $stmt = $link->prepare("CALL SeleccionarPedidos()"); 
                                $stmt->execute();
                                $resultado = $stmt->get_result();
                                while ($row = $resultado->fetch_assoc()) { ?>
                                    <tr>
                                        <td><?php echo $row['nombre_cliente']; ?></td>
                                        <td><?php echo $row['producto']; ?></td>
                                        <td><?php echo $row['cantidad']; ?></td>
                                        <td><?php echo $row['precio_unitario']; ?></td>
                                        <td><?php echo $row['total']; ?></td>
                                        <td><?php echo $row['fecha_pedido']; ?></td>
                                        <td><?php echo $row['estado']; ?></td>
                                    </tr>
                                <?php } 
                                $stmt->close();
                                $link->close();
                                ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>

            

        </main>
    </section>

    <!--JavaScript para cambiar de sección-->
    <script src="js/admi.js"></script>
    <script>
                        function mostrarFormulario() {
                            const formulario = document.getElementById("formulario-tareas");
                            formulario.style.display = formulario.style.display === "none" ? "block" : "none";
                        }
                    </script>

</body>

</html>
