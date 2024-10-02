
function addExperiencia() {
    var container = document.getElementById('experiencia-laboral-container');
    var newField = document.createElement('div');
    newField.className = 'input-field';
    newField.innerHTML = '<input type="text" name="experiencia_laboral[]" placeholder="Descripción de la experiencia" required class="box">';
    container.appendChild(newField);
}

function addFormacion() {
    var container = document.getElementById('formacion-container');
    var newField = document.createElement('div');
    newField.className = 'input-field';
    newField.innerHTML = '<input type="text" name="formacion[]" placeholder="Descripción de la formación" required class="box">';
    container.appendChild(newField);
}

function addIdioma() {
    var container = document.getElementById('idiomas-container');
    var newField = document.createElement('div');
    newField.className = 'input-field';
    newField.innerHTML = '<input type="text" name="idiomas[]" placeholder="Idioma y nivel" required class="box">';
    container.appendChild(newField);
}

function addAptitud() {
    var container = document.getElementById('aptitudes-container');
    var newField = document.createElement('div');
    newField.className = 'input-field';
    newField.innerHTML = `<input list="aptitudes" name="aptitudes[]" placeholder="Selecciona o ingresa una aptitud" required class="box">
        <datalist id="aptitudes">
            <option value="Trabajo en equipo">
            <option value="Resolución de problemas">
            <option value="Liderazgo">
            <option value="Comunicación efectiva">
        </datalist>`;
    container.appendChild(newField);
}



