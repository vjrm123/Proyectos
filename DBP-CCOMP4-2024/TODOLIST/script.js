const fechaElemento = document.getElementById('fecha');
    const opciones = { day: 'numeric', month: 'long', year: 'numeric' }; // Añadido el año
    const fechaActual = new Date().toLocaleDateString('es-ES', opciones); // Formato en español
    fechaElemento.textContent = fechaActual;