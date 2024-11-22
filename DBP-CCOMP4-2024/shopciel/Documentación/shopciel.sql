-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 19-11-2024 a las 16:10:41
-- Versión del servidor: 10.4.32-MariaDB
-- Versión de PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `ropa_samm`
--

DELIMITER $$
--
-- Procedimientos
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `obtener_cantidad_clientes` ()   BEGIN
    SELECT COUNT(*) AS cantidad_clientes
    FROM cliente;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `obtener_cantidad_pedidos` ()   BEGIN
    SELECT COUNT(*) AS total_pedidos
    FROM pedido;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `obtener_clientes` ()   BEGIN
    SELECT * FROM cliente;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `obtener_pedidos_recientes` ()   BEGIN
    SELECT 
        o.fecha_pedido AS fecha_pedido,
        c.nombre_cliente,
        c.apellido_cliente,
        o.estado_pedido
    FROM pedido o
    JOIN cliente c ON o.codigo_cliente = c.codigo_cliente
    ORDER BY o.fecha_pedido DESC;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `obtener_producto` (IN `nombre_producto` VARCHAR(255))   BEGIN
    IF nombre_producto IS NULL OR nombre_producto = '' THEN
        SELECT p.codigo_producto, m.nombre_marca, t.nombre_talla, c.nombre_color, ct.nombre_categoria, 
               p.nombre_producto, p.precio, p.stock 
        FROM producto p 
        INNER JOIN marca m ON m.codigo_marca = p.codigo_marca 
        INNER JOIN talla t ON t.codigo_talla = p.codigo_talla 
        INNER JOIN colores c ON c.codigo_color = p.codigo_color 
        INNER JOIN categoria ct ON ct.codigo_categoria = p.codigo_categoria 
        ORDER BY p.codigo_producto;
    ELSE
        SELECT p.codigo_producto, m.nombre_marca, t.nombre_talla, c.nombre_color, ct.nombre_categoria, 
               p.nombre_producto, p.precio, p.stock 
        FROM producto p 
        INNER JOIN marca m ON m.codigo_marca = p.codigo_marca 
        INNER JOIN talla t ON t.codigo_talla = p.codigo_talla 
        INNER JOIN colores c ON c.codigo_color = p.codigo_color 
        INNER JOIN categoria ct ON ct.codigo_categoria = p.codigo_categoria 
        WHERE p.nombre_producto LIKE CONCAT('%', nombre_producto, '%')
        ORDER BY p.codigo_producto;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `obtener_todas_las_categorias` ()   BEGIN
    SELECT nombre_categoria FROM categoria;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `SeleccionarAdministradores` ()   BEGIN
    SELECT nombre, email, rol 
    FROM administrar_usiarios;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `SeleccionarPedidos` ()   BEGIN
    SELECT 
        u.nombre_cliente AS nombre_cliente,            
        p.nombre_producto AS producto,                
        c.cantidad AS cantidad,                   
        p.precio AS precio_unitario,          
        (c.cantidad * p.precio) AS total,          
        pd.fecha_pedido AS fecha_pedido,            
        pd.estado_pedido AS estado                   
    FROM carrito c      
    JOIN producto p ON c.codigo_producto = p.codigo_producto    
    JOIN pedido pd ON c.codigo_pedido = pd.codigo_pedido   
    JOIN cliente u ON pd.codigo_cliente = u.codigo_cliente
    ORDER BY pd.fecha_pedido DESC;                   
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `TotalVentasDelMesActual` ()   BEGIN
    SELECT 
        SUM(c.cantidad * p.precio) AS total_ventas
    FROM carrito c
    JOIN producto p ON c.codigo_producto = p.codigo_producto
    JOIN pedido pd ON c.codigo_pedido = pd.codigo_pedido
    WHERE MONTH(pd.fecha_pedido) = MONTH(CURDATE())        
      AND YEAR(pd.fecha_pedido) = YEAR(CURDATE());              
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `administrar_usiarios`
--

CREATE TABLE `administrar_usiarios` (
  `id_admin` int(11) NOT NULL,
  `nombre` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `password` varchar(255) NOT NULL,
  `rol` enum('superadmin','editor','soporte') DEFAULT 'editor',
  `fecha_creacion` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `administrar_usiarios`
--

INSERT INTO `administrar_usiarios` (`id_admin`, `nombre`, `email`, `password`, `rol`, `fecha_creacion`) VALUES
(1, 'victor', 'victor.ramos.mamani@ucsp.edu.pe', '1234', 'superadmin', '2024-11-12 21:07:33'),
(2, 'victor juan', 'ramos@gmail.com', '$2y$10$xDQ.K9uDyGKnXb101UJVyuSaiTHJDPSKwlHfPKQykJJKsXiZ7hq0C', 'superadmin', '2024-11-18 20:02:06'),
(3, 'juan de la vida', 'nose@gmail.com', '$2y$10$lZIKd7gTCWWs0uAeBpPDNOPXG1IvDnYZoeeR24BZzSlX9osOPl2Aq', 'editor', '2024-11-18 23:22:28');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `carrito`
--

CREATE TABLE `carrito` (
  `codigo_producto` int(5) NOT NULL,
  `codigo_pedido` int(5) NOT NULL,
  `cantidad` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `carrito`
--

INSERT INTO `carrito` (`codigo_producto`, `codigo_pedido`, `cantidad`) VALUES
(4, 72, 0),
(5, 72, 0),
(6, 70, 4),
(6, 72, 1),
(9, 72, 0),
(10, 71, 1),
(11, 72, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `categoria`
--

CREATE TABLE `categoria` (
  `codigo_categoria` int(5) NOT NULL,
  `nombre_categoria` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `categoria`
--

INSERT INTO `categoria` (`codigo_categoria`, `nombre_categoria`) VALUES
(1, 'Femenino'),
(2, 'Masculino');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cliente`
--

CREATE TABLE `cliente` (
  `codigo_cliente` int(5) NOT NULL,
  `codigo_postal` int(5) NOT NULL,
  `nombre_cliente` varchar(40) NOT NULL,
  `apellido_cliente` varchar(40) NOT NULL,
  `dni` varchar(10) NOT NULL,
  `telefono` varchar(20) NOT NULL,
  `correo` varchar(60) NOT NULL,
  `clave` varchar(60) NOT NULL,
  `direccion` varchar(100) NOT NULL,
  `fecha_nacimiento` date NOT NULL,
  `numero_tarjeta` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `cliente`
--

INSERT INTO `cliente` (`codigo_cliente`, `codigo_postal`, `nombre_cliente`, `apellido_cliente`, `dni`, `telefono`, `correo`, `clave`, `direccion`, `fecha_nacimiento`, `numero_tarjeta`) VALUES
(7, 1, 'Valentina', 'Bustamante', '12345678', '961723627', 'valen@gmail.com', '$2y$10$2oyBPVDRA8xCL9RKGMoCOOO3QekU6IDySEXmAIWZOSiYa3h1ApxU.', 'Calle Melocoton 8', '2021-11-03', 12345),
(8, 3, 'Adriana', 'Olivares', '23458724', '236432898', 'adri@gmail.com', '$2y$10$NgLy9vSK1AaDGD8rzPpUYey5zmgLQmuAKgGBbCxZv0Tw1mLqs9EFe', 'Los Panales 876', '2021-11-17', 345627),
(9, 2, 'HOLA', 'RA', '32', '223', 'victor.ramos.mamani@ucsp.edu.pe', '$2y$10$UzettIRQw6pM9WNeTJxDMuXbK9onbSIUUVNCIh/O6VAX/NAMt9Sre', 'NOSE', '2024-11-27', 2344212);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `colores`
--

CREATE TABLE `colores` (
  `codigo_color` int(5) NOT NULL,
  `nombre_color` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `colores`
--

INSERT INTO `colores` (`codigo_color`, `nombre_color`) VALUES
(1, 'Negro'),
(2, 'Azul'),
(3, 'Blanco');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `destino`
--

CREATE TABLE `destino` (
  `codigo_postal` int(5) NOT NULL,
  `departamento` varchar(100) NOT NULL,
  `distrito` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `destino`
--

INSERT INTO `destino` (`codigo_postal`, `departamento`, `distrito`) VALUES
(1, 'Arequipa', 'J.L.B. y R.'),
(2, 'Arequipa', 'Paucarpata'),
(3, 'Arequipa', 'Selva Alegre'),
(4, 'Arequipa', 'Cerro Colorado'),
(5, 'Arequipa', 'Cayma');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `favoritos`
--

CREATE TABLE `favoritos` (
  `codigo_cliente` int(5) NOT NULL,
  `codigo_producto` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `feedback`
--

CREATE TABLE `feedback` (
  `codigo_feedback` int(5) NOT NULL,
  `codigo_cliente` int(5) NOT NULL,
  `codigo_pedido` int(5) NOT NULL,
  `opciones_reclamo` varchar(150) NOT NULL,
  `opciones_satisfaccion` varchar(150) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `marca`
--

CREATE TABLE `marca` (
  `codigo_marca` int(5) NOT NULL,
  `nombre_marca` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `marca`
--

INSERT INTO `marca` (`codigo_marca`, `nombre_marca`) VALUES
(1, 'SAMM'),
(2, 'SAMM2');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `metodo_pago`
--

CREATE TABLE `metodo_pago` (
  `codigo_pago` int(5) NOT NULL,
  `codigo_cliente` int(5) NOT NULL,
  `nombre_metodo` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `metodo_pago`
--

INSERT INTO `metodo_pago` (`codigo_pago`, `codigo_cliente`, `nombre_metodo`) VALUES
(1, 7, 'Debito'),
(3, 8, 'Debiro'),
(4, 9, 'TARJETA');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pedido`
--

CREATE TABLE `pedido` (
  `codigo_pedido` int(5) NOT NULL,
  `codigo_cliente` int(5) NOT NULL,
  `codigo_pago` int(5) NOT NULL,
  `fecha_pedido` date NOT NULL,
  `fecha_entrega` date NOT NULL,
  `estado_pedido` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `pedido`
--

INSERT INTO `pedido` (`codigo_pedido`, `codigo_cliente`, `codigo_pago`, `fecha_pedido`, `fecha_entrega`, `estado_pedido`) VALUES
(70, 8, 3, '2021-11-29', '2021-12-14', 'en estado'),
(71, 7, 1, '2021-11-29', '2021-12-14', 'en estado'),
(72, 9, 4, '2024-11-09', '2024-11-24', 'en proceso'),
(73, 9, 4, '2024-11-09', '2024-11-24', 'en proceso'),
(74, 9, 4, '2024-11-10', '2024-11-25', 'en proceso'),
(75, 9, 4, '2024-11-11', '2024-11-26', 'en proceso'),
(76, 9, 4, '2024-11-11', '2024-11-26', 'en proceso'),
(77, 9, 4, '2024-11-11', '2024-11-26', 'en proceso'),
(78, 9, 4, '2024-11-11', '2024-11-26', 'en proceso'),
(79, 9, 4, '2024-11-12', '2024-11-27', 'en proceso');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto`
--

CREATE TABLE `producto` (
  `codigo_producto` int(5) NOT NULL,
  `codigo_marca` int(5) NOT NULL,
  `codigo_talla` int(5) NOT NULL,
  `codigo_color` int(5) NOT NULL,
  `codigo_categoria` int(5) NOT NULL,
  `nombre_producto` varchar(80) NOT NULL,
  `precio` decimal(10,2) NOT NULL,
  `stock` int(5) NOT NULL,
  `descripcion` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `producto`
--

INSERT INTO `producto` (`codigo_producto`, `codigo_marca`, `codigo_talla`, `codigo_color`, `codigo_categoria`, `nombre_producto`, `precio`, `stock`, `descripcion`) VALUES
(3, 1, 2, 2, 1, 'Wide High Jeans', 74.50, 10, 'Vaquero de cinco bolsillos en denim de algodón. Modelo de talle alto con perneras amplias rectas y cierre de cremallera con botón.'),
(4, 1, 1, 1, 1, 'Chaqueta THERMOLITE', 55.00, 10, 'Abrigo de botonadura sencilla en mezcla de lana afieltrada con solapas de muesca y bolsillos insertados al bies. Manga forrada.'),
(5, 2, 4, 1, 2, 'Camisa de Franela Regular Fit', 35.50, 10, 'Camisa de algodón con cuello americano, botones delante y canesú de doble capa con pliegue de caja en la espalda. Modelo corte relajado con hombros caídos, mangas largas con puños anchos abotonados y bajo redondeado. Espalda algo más larga.'),
(6, 1, 1, 1, 1, 'Cardigan en Punto Peludo', 60.99, 10, 'Cárdigan ligeramente corto en punto suave de canalé con lana en la trama. Modelo de manga amplia con escote de pico y cierre de botones.'),
(7, 1, 1, 1, 1, 'Vestido Peto de Pana', 63.00, 10, 'Vestido corto en pana de algodón con tirantes ajustables cruzados en la espalda. Costura en la cintura, bolsillos delanteros y cierre oculto de cremallera con botón en un lateral. Sin forrar.'),
(8, 2, 3, 1, 2, 'Joggers Cargo', 39.99, 10, 'Joggers de tela con elástico revestido y cordón de ajuste en la cintura, cierre decorativo, bolsillos al bies y bolsillos traseros con solapa. Perneras con costuras moldeadoras sobre las rodillas, prácticos bolsillos con cremallera y elástico revestido en los bajos.'),
(9, 1, 1, 1, 1, 'Vestido de Punto', 60.00, 10, 'Vestido corto en punto fino con lana en la trama. Modelo de corte relajado con cuello ancho en canalé y abertura en V delante, hombros ligeramente caídos y mangas largas amplias. Puños y bajo en punto de canalé.'),
(10, 1, 4, 3, 1, 'Vestido con Cinturón', 75.00, 10, 'Vestido midi en denim de algodón grueso con cuello elevado y botonadura frontal. Hombros ligeramente caídos, mangas globo largas con elástico fino en los puños y cinturón de anudar extraíble. Sin forrar.'),
(11, 1, 2, 2, 1, 'Falda Denim Tableada', 47.50, 10, 'Minifalda tableada en denim de algodón grueso. Modelo de talle alto con botón de presión y cremallera oculta en un lateral. Sin forrar.');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `registro_actividades`
--

CREATE TABLE `registro_actividades` (
  `id_actividad` int(11) NOT NULL,
  `id_admin` int(11) NOT NULL,
  `accion` varchar(255) NOT NULL,
  `fecha` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `talla`
--

CREATE TABLE `talla` (
  `codigo_talla` int(5) NOT NULL,
  `nombre_talla` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `talla`
--

INSERT INTO `talla` (`codigo_talla`, `nombre_talla`) VALUES
(1, 'Extra Small'),
(4, 'Large'),
(3, 'Medium'),
(2, 'Small');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tareas`
--

CREATE TABLE `tareas` (
  `id` int(11) NOT NULL,
  `tarea` varchar(255) NOT NULL,
  `asignada_a` varchar(100) NOT NULL,
  `estado` enum('pendiente','completada') DEFAULT 'pendiente',
  `superadmin` varchar(100) NOT NULL,
  `fecha_asignacion` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `tareas`
--

INSERT INTO `tareas` (`id`, `tarea`, `asignada_a`, `estado`, `superadmin`, `fecha_asignacion`) VALUES
(1, 'caminar', 'nose@gmail.com', 'completada', 'victor juan', '2024-11-19 13:12:27');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `administrar_usiarios`
--
ALTER TABLE `administrar_usiarios`
  ADD PRIMARY KEY (`id_admin`),
  ADD UNIQUE KEY `email` (`email`);

--
-- Indices de la tabla `carrito`
--
ALTER TABLE `carrito`
  ADD PRIMARY KEY (`codigo_producto`,`codigo_pedido`),
  ADD KEY `codigo_pedido` (`codigo_pedido`);

--
-- Indices de la tabla `categoria`
--
ALTER TABLE `categoria`
  ADD PRIMARY KEY (`codigo_categoria`);

--
-- Indices de la tabla `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`codigo_cliente`),
  ADD KEY `codigo_postal` (`codigo_postal`);

--
-- Indices de la tabla `colores`
--
ALTER TABLE `colores`
  ADD PRIMARY KEY (`codigo_color`);

--
-- Indices de la tabla `destino`
--
ALTER TABLE `destino`
  ADD PRIMARY KEY (`codigo_postal`);

--
-- Indices de la tabla `favoritos`
--
ALTER TABLE `favoritos`
  ADD PRIMARY KEY (`codigo_cliente`,`codigo_producto`),
  ADD KEY `codigo_producto` (`codigo_producto`);

--
-- Indices de la tabla `feedback`
--
ALTER TABLE `feedback`
  ADD PRIMARY KEY (`codigo_feedback`),
  ADD KEY `codigo_cliente` (`codigo_cliente`),
  ADD KEY `codigo_pedido` (`codigo_pedido`);

--
-- Indices de la tabla `marca`
--
ALTER TABLE `marca`
  ADD PRIMARY KEY (`codigo_marca`);

--
-- Indices de la tabla `metodo_pago`
--
ALTER TABLE `metodo_pago`
  ADD PRIMARY KEY (`codigo_pago`),
  ADD KEY `codigo_cliente` (`codigo_cliente`);

--
-- Indices de la tabla `pedido`
--
ALTER TABLE `pedido`
  ADD PRIMARY KEY (`codigo_pedido`),
  ADD KEY `codigo_pedido` (`codigo_pedido`,`codigo_cliente`),
  ADD KEY `codigo_pago` (`codigo_pago`),
  ADD KEY `codigo_cliente` (`codigo_cliente`);

--
-- Indices de la tabla `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`codigo_producto`),
  ADD KEY `codigo_marca` (`codigo_marca`),
  ADD KEY `codigo_talla` (`codigo_talla`),
  ADD KEY `codigo_color` (`codigo_color`),
  ADD KEY `codigo_categoria` (`codigo_categoria`),
  ADD KEY `nombre_producto` (`nombre_producto`);

--
-- Indices de la tabla `registro_actividades`
--
ALTER TABLE `registro_actividades`
  ADD PRIMARY KEY (`id_actividad`),
  ADD KEY `id_admin` (`id_admin`);

--
-- Indices de la tabla `talla`
--
ALTER TABLE `talla`
  ADD PRIMARY KEY (`codigo_talla`),
  ADD KEY `nombre_talla` (`nombre_talla`);

--
-- Indices de la tabla `tareas`
--
ALTER TABLE `tareas`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `administrar_usiarios`
--
ALTER TABLE `administrar_usiarios`
  MODIFY `id_admin` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `categoria`
--
ALTER TABLE `categoria`
  MODIFY `codigo_categoria` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT de la tabla `cliente`
--
ALTER TABLE `cliente`
  MODIFY `codigo_cliente` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT de la tabla `colores`
--
ALTER TABLE `colores`
  MODIFY `codigo_color` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `destino`
--
ALTER TABLE `destino`
  MODIFY `codigo_postal` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de la tabla `feedback`
--
ALTER TABLE `feedback`
  MODIFY `codigo_feedback` int(5) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `marca`
--
ALTER TABLE `marca`
  MODIFY `codigo_marca` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT de la tabla `metodo_pago`
--
ALTER TABLE `metodo_pago`
  MODIFY `codigo_pago` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT de la tabla `pedido`
--
ALTER TABLE `pedido`
  MODIFY `codigo_pedido` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=80;

--
-- AUTO_INCREMENT de la tabla `producto`
--
ALTER TABLE `producto`
  MODIFY `codigo_producto` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=53;

--
-- AUTO_INCREMENT de la tabla `registro_actividades`
--
ALTER TABLE `registro_actividades`
  MODIFY `id_actividad` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `talla`
--
ALTER TABLE `talla`
  MODIFY `codigo_talla` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT de la tabla `tareas`
--
ALTER TABLE `tareas`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `carrito`
--
ALTER TABLE `carrito`
  ADD CONSTRAINT `carrito_ibfk_1` FOREIGN KEY (`codigo_producto`) REFERENCES `producto` (`codigo_producto`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `carrito_ibfk_2` FOREIGN KEY (`codigo_pedido`) REFERENCES `pedido` (`codigo_pedido`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `cliente`
--
ALTER TABLE `cliente`
  ADD CONSTRAINT `cliente_ibfk_1` FOREIGN KEY (`codigo_postal`) REFERENCES `destino` (`codigo_postal`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `favoritos`
--
ALTER TABLE `favoritos`
  ADD CONSTRAINT `favoritos_ibfk_1` FOREIGN KEY (`codigo_cliente`) REFERENCES `cliente` (`codigo_cliente`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `favoritos_ibfk_2` FOREIGN KEY (`codigo_producto`) REFERENCES `producto` (`codigo_producto`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `feedback`
--
ALTER TABLE `feedback`
  ADD CONSTRAINT `feedback_ibfk_1` FOREIGN KEY (`codigo_cliente`) REFERENCES `cliente` (`codigo_cliente`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `feedback_ibfk_2` FOREIGN KEY (`codigo_pedido`) REFERENCES `pedido` (`codigo_pedido`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `metodo_pago`
--
ALTER TABLE `metodo_pago`
  ADD CONSTRAINT `metodo_pago_ibfk_1` FOREIGN KEY (`codigo_cliente`) REFERENCES `cliente` (`codigo_cliente`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `pedido`
--
ALTER TABLE `pedido`
  ADD CONSTRAINT `pedido_ibfk_1` FOREIGN KEY (`codigo_cliente`) REFERENCES `cliente` (`codigo_cliente`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `pedido_ibfk_2` FOREIGN KEY (`codigo_pago`) REFERENCES `metodo_pago` (`codigo_pago`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `producto`
--
ALTER TABLE `producto`
  ADD CONSTRAINT `producto_ibfk_1` FOREIGN KEY (`codigo_marca`) REFERENCES `marca` (`codigo_marca`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `producto_ibfk_2` FOREIGN KEY (`codigo_talla`) REFERENCES `talla` (`codigo_talla`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `producto_ibfk_3` FOREIGN KEY (`codigo_color`) REFERENCES `colores` (`codigo_color`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `producto_ibfk_4` FOREIGN KEY (`codigo_categoria`) REFERENCES `categoria` (`codigo_categoria`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `registro_actividades`
--
ALTER TABLE `registro_actividades`
  ADD CONSTRAINT `registro_actividades_ibfk_1` FOREIGN KEY (`id_admin`) REFERENCES `administrar_usiarios` (`id_admin`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
