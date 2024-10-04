const fechaElemento = document.getElementById('fecha');
const opciones = { day: 'numeric', month: 'long', year: 'numeric' };
const fechaActual = new Date().toLocaleDateString('es-ES', opciones);
fechaElemento.textContent = fechaActual;

const lista = document.querySelector("#lista");
const input = document.querySelector("#input");
const botonEnter = document.getElementById('enter');
const check = 'fa-check-circle';
const uncheck = 'fa-circle';
const lineThrough = 'line-through';
let id = 0;

function agregarTarea(tarea, id, realizado, eliminado) {
    if (eliminado) {
        return;
    }

    const REALIZADO = realizado ? check : uncheck;
    const LINEA = realizado ? lineThrough : '';

    const elemento = `
        <li>
            <i class="far ${REALIZADO}" data-realizado="true" id="check-${id}"></i>
            <p class="text ${LINEA}" id="tarea-${id}">${tarea}</p>
            <div class="iconos">
                <i class="fas fa-edit editar" data-editar="true" id="edit-${id}"></i>
                <i class="fas fa-trash de" data-eliminado="true" id="delete-${id}"></i>
            </div>
        </li>
    `;
    
    lista.insertAdjacentHTML("beforeend", elemento);
}

botonEnter.addEventListener('click', () => {
    const tarea = input.value.trim(); 
    if (tarea) {
        agregarTarea(tarea, id, false, false);
        input.value = ''; 
        id++;
    }
});

document.addEventListener('keyup', function(event) {
    if (event.key === 'Enter') {
        const tarea = input.value.trim();
        if (tarea) {
            agregarTarea(tarea, id, false, false);
            input.value = ''; 
            id++; 
        }
    }
});

lista.addEventListener('click', function(event) {
    const elemento = event.target;

    if (elemento.dataset.realizado) {
        const parentLi = elemento.parentNode;
        const p = parentLi.querySelector(".text");
        elemento.classList.toggle(check);
        elemento.classList.toggle(uncheck);
        p.classList.toggle(lineThrough);
    }

    if (elemento.classList.contains('fa-trash')) {
        const parentLi = elemento.closest('li'); 
        parentLi.remove();
    }

    if (elemento.classList.contains('fa-edit')) {
        const id = elemento.id.split('-')[1]; 
        const tareaTexto = document.getElementById(`tarea-${id}`);
        
        const inputEdicion = document.createElement('input');
        inputEdicion.type = 'text';
        inputEdicion.value = tareaTexto.textContent;
        inputEdicion.classList.add('input-edicion');

        tareaTexto.replaceWith(inputEdicion);

        inputEdicion.addEventListener('blur', () => {
            const nuevoTexto = inputEdicion.value.trim();
            if (nuevoTexto) {
                tareaTexto.textContent = nuevoTexto;
            }
            inputEdicion.replaceWith(tareaTexto); 
        });

        inputEdicion.addEventListener('keyup', (event) => {
            if (event.key === 'Enter') {
                const nuevoTexto = inputEdicion.value.trim();
                if (nuevoTexto) {
                    tareaTexto.textContent = nuevoTexto;
                }
                inputEdicion.replaceWith(tareaTexto); 
            }
        });

        inputEdicion.focus();
    }
});


document.getElementById('borrar-todo').addEventListener('click', function() {
    lista.innerHTML = '';
    id = 0;  
});

document.getElementById('seleccionar-todo').addEventListener('click', function() {
    const tareas = lista.querySelectorAll('li');
    tareas.forEach(tarea => {
        const icono = tarea.querySelector('[data-realizado]');
        const p = tarea.querySelector('.text');
        icono.classList.add(check);
        icono.classList.remove(uncheck);
        p.classList.add(lineThrough);
    });
});
