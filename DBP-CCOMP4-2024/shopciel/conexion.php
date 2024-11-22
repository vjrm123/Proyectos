<?php
$link = mysqli_connect("localhost", "root", "", "ropa_samm");
/* comprobar la conexión */
if (mysqli_connect_errno()) {
	printf("Falló la conexión: %s\n", mysqli_connect_error());
	exit();
}
?>