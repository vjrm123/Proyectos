const allSideMenu = document.querySelectorAll("#sidebar .side-menubar.top li a");

allSideMenu.forEach(item=> {

    const li = item.parentElement;

    item.addEventListener('click', function () {
        allSideMenu.forEach(i=> {
            i.parentElement.classList.remove('active');
        })
    }
)
});

//toggle sidebar

const menuBar = document.querySelector("#content nav .bx.bx-menu");
const sidebar = document.getElementById('sidebar');

menuBar.addEventListener('click', function () {
    sidebar.classList.toggle('hide');
});

const searchButton = document.querySelector("#content nav form .form-input button");
const searchButtonIcon = document.querySelector("#content nav form .form-input button .bx");
const searchForm = document.querySelector("#content nav form");

searchButton.addEventListener('click', function (e) {
    if(window.innerWidth < 576) {
        e.preventDefault();
        searchForm.classList.toggle('show');
        if(searchForm.classList.contains('show')) {
            searchButtonIcon.classList.replace('bx-search', 'bx-x');
        } else {
            searchButtonIcon.classList.replace('bx-x', 'bx-search');
        }
    }
})

if(window.innerWidth < 768) {
    sidebar.classList.add('hide');
} else if (window.innerWidth > 576) {
    searchButtonIcon.classList.replace('bx-x', 'bx-search');
    searchForm.classList.remove('show');
}

window.addEventListener('resize', function () {
    if(this.innerWidth > 576) {
        searchButtonIcon.classList.replace('bx-x', 'bx-search');
        searchForm.classList.remove('show');
    }
})


const switchMode = document.getElementById('swith-mode');

switchMode.addEventListener('change', function () {
    if(this.checked) {
        document.body.classList.add('dark');
    } else {
        document.body.classList.remove('dark');
    }
})

    function mostrarSeccion(seccionId, elemento) {
        const secciones = document.querySelectorAll('.seccion');
        secciones.forEach(seccion => seccion.style.display = 'none');
        document.getElementById(seccionId).style.display = 'block';
        
        // Eliminar la clase "active" de todos los elementos
        var items = document.querySelectorAll('.side-menu.top li');
        items.forEach(function(item) {
            item.classList.remove('active');
        });

        // Agregar la clase "active" al elemento clickeado
        elemento.parentElement.classList.add('active');
    }