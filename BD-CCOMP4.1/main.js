// Selecciona el contenedor de los iconos de navegación y el botón del menú
const navlist = document.querySelector(".iconos-navegacion");
const menuBtn = document.querySelector(".ri-menu-line");

// Función para alternar el menú de navegación en pantallas pequeñas
menuBtn.onclick = function () {
    navlist.classList.toggle("active");
    menuBtn.classList.toggle("ri-arrow-up-double-line"); // Cambia el ícono de menú al ícono de flecha
};

// Selecciona el botón de tema
let themeBtn = document.querySelector("#boton-tema");

// Función para cambiar entre tema claro y oscuro
themeBtn.onclick = function () {
    themeBtn.classList.toggle("ri-sun-line"); // Cambia el ícono de luna al ícono de sol
    if (themeBtn.classList.contains("ri-sun-line")) {
        document.body.classList.add("active"); // Aplica el tema oscuro
    } else {
        document.body.classList.remove("active"); // Vuelve al tema claro
    }
};
