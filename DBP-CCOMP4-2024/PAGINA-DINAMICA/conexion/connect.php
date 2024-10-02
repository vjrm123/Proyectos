<?php
    const base_url = "http://localhost:8012/CV/";
    const host = "localhost";
    const user = "root";
    const pass = "";
    const db = "formulario";
    const charset = "charset=utf8";

    $dsn = "mysql:host=" . host . ";dbname=" . db . ";" . charset;

    $conn = new PDO($dsn, user, pass);
?>
