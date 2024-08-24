
const valorAnterior = document.getElementById("valor_anterior");
const valorActual = document.getElementById("valor_actual");
const botonesNumeros = document.querySelectorAll(".numero");
const botonesOperadores = document.querySelectorAll(".operador" );
const botonIgual = document.querySelector(".operador");
const botonBorrarTodo = document.querySelector(".col_dos");
const botonBorrarUltimo = document.querySelector(".borrar-ultimo"); 

let operacion = "";
let numeroAnterior = "";
let numeroActual = "";

function actualizarVisualizacion() {
    valorActual.innerText = numeroActual;
    valorAnterior.innerText = numeroAnterior + " " + operacion;
}

botonesNumeros.forEach((boton) => {
    boton.addEventListener("click", () => {
        numeroActual += boton.innerText;
        actualizarVisualizacion();
    });
});

botonesOperadores.forEach((boton) => {
    boton.addEventListener("click", () => {
        if (numeroActual === "") return;
        if (numeroAnterior !== "") {
            calcular();
        }
        operacion = boton.innerText;
        numeroAnterior = numeroActual;
        numeroActual = "";
        actualizarVisualizacion();
    });
});

function calcular() {
    let resultado;
    const anterior = parseFloat(numeroAnterior);
    const actual = parseFloat(numeroActual);
    switch (operacion) {
        case "+":
            resultado = anterior + actual;
            break;
        case "-":
            resultado = anterior - actual;
            break;
        case "x":
            resultado = anterior * actual;
            break;
        case "%":
            resultado = anterior * (actual /100) ;
            break;
        case "÷":
            if (actual === 0) {
                alert("nose puede dividir por cero");
                return;
            } else {
                resultado = (anterior  / actual);
                break;
            }
        default:
            return;
    }
    numeroActual = resultado.toString();
    operacion = "";
    numeroAnterior = "";
    actualizarVisualizacion();
}

botonIgual.addEventListener("click", () => {
    calcular();
    numeroAnterior = "";
    operacion = ""; 
});

botonBorrarTodo.addEventListener("click", () => {
    numeroActual = " ";
    actualizarVisualizacion();
});

botonBorrarUltimo.addEventListener("click", () => {
    numeroActual = numeroActual.slice(0, -1);
    actualizarVisualizacion();
});