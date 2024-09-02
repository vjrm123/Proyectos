// ============== MENU NAVBAR ================
const navlist = document.querySelector(".iconos-navegacion");
const menuBtn = document.querySelector(".ri-menu-line");

menuBtn.onclick = function () {
  navlist.classList.toggle("active");
  menuBtn.classList.toggle("ri-arrow-up-double-line");
};

/* start secction universidad */
const companeros = [
  { name: "Victor Juan Ramos Mamani", url: "https://victor-juan-ramos-mamani.web.app/" },
  { name: "Sergio Alejandro Paucar Cruz", url: "https://sergio-alejandro-paucar-cruz.web.app/" },
  { name: "Frank Eduardo Calcina Arias", url: "https://frankeduardocalcinaarias.000webhostapp.com/" },
  { name: "Brysett Magely Valenzuela Lazarte", url: "https://brysettmagelyvalenzuelalazarte.github.io/" },
  { name: "Eduardo Sebastian Cordova Choque", url: "https://eduardosebastiancordovachoque.netlify.app/" },
  { name: "Stefano Aaron Ballesteros Roque.", url: "https://steffanoaaronballesterosroque.netlify.app/" },
  { name: "Angelica Danitza Flores Yauri.", url: "https://angelicadanitzafloresyauri.netlify.app/" },
  { name: "Dayanna Milagros Vizcarra Vargas", url: "https://dayannamilagrosvizcarravargas.netlify.app/" },
  { name: "Christian Gabriel Sana Flores.", url: "https://christian-gabriel.web.app/" }
];

const docentes = [
  { name: "Dr.Ernesto Cuadros Vargas.", url: "https://ecuadros.blogspot.com/" },
  { name: "Dr.Manuel Loaiza Fernandez.", url: "https://ctivitae.concytec.gob.pe/appDirectorioCTI/VerDatosInvestigador.do?id_investigador=54641" },
  { name: "Mg.Kelly Vizconde La Motta.", url: "https://ctivitae.concytec.gob.pe/appDirectorioCTI/VerDatosInvestigador.do?id_investigador=258819" }
  
];

function mostrarCompañeros() {
      var companerosList = document.getElementById("compañeros-lista");
      var docentesList = document.getElementById("docentes-lista");
  
      // Limpiar la lista de compañeros antes de agregar los nuevos
      companerosList.innerHTML = "";
  
      // Agregar los nombres de compañeros a la lista como enlaces
      for (var i = 0; i < companeros.length; i++) {
      var li = document.createElement("li");
      li.className = "nombre-item"; // Agrega la clase CSS aquí
  
      var link = document.createElement("a");
      link.href = companeros[i].url;
      link.textContent = companeros[i].name;
      link.className = "nombre-link"; // Agrega la clase CSS aquí
      link.target = "_blank";
      link.onclick = function(event) {
          console.log("Hiciste clic en el nombre: ", this.textContent);
          event.preventDefault();
          window.open(this.href, '_blank');
      };
  
      li.appendChild(link);
      companerosList.appendChild(li);
      }
  
      if (companerosList.style.display === "none") {
      companerosList.style.display = "block";
      docentesList.style.display = "none";
      } else {
      companerosList.style.display = "none";
      }
  }

function mostrarDocentes() {
  var companerosList = document.getElementById("compañeros-lista");
  var docentesList = document.getElementById("docentes-lista");

  docentesList.innerHTML = "";
  for (var i = 0; i < docentes.length; i++) {
  var li = document.createElement("li");
  li.className = "nombre-item";

  var link = document.createElement("a");
  link.href = docentes[i].url;
  link.textContent = docentes[i].name;
  link.className = "nombre-link"; // Agrega la clase CSS aquí
  link.target = "_blank";
  link.onclick = function() {
      console.log("Hiciste clic en el nombre: ", this.textContent);
  };

  li.appendChild(link);
  docentesList.appendChild(li);
  }

  if (docentesList.style.display === "none") {
  docentesList.style.display = "block";
  companerosList.style.display = "none";
  } else {
  docentesList.style.display = "none";
  }
}

/*END SECCTION UNIVERSIDAD*/

// ============== DARK THEME================
let themeBtn = document.querySelector("#boton-tema");

themeBtn.onclick = function () {
  themeBtn.classList.toggle("ri-sun-line");
  if (themeBtn.classList.contains("ri-sun-line")) {
    document.body.classList.add("active");
  } else {
    document.body.classList.remove("active");
  }
};


/* SECTION LENGUAJES */
const container = document.querySelector(".containerES");
const containercarrossel = container.querySelector(".container-carrossel");
const carrossel = container.querySelector(".carrossel");
const carrosselItems = carrossel.querySelectorAll(".carrossel-item");

// Iniciamos variables que cambiaran su estado.
let isMouseDown = false;
let currentMousePos = 0;
let lastMousePos = 0;
let lastMoveTo = 0;
let moveTo = 0;

const createcarrossel = () => {
  const carrosselProps = onResize();
  const length = carrosselItems.length; // Longitud del array
  const degress = 360 / length; // Grados por cada item
  const gap = 20; // Espacio entre cada item
  const tz = distanceZ(carrosselProps.w, length, gap);

  const fov = calculateFov(carrosselProps);
  const height = calculateHeight(tz);

  container.style.width = tz * 2 + gap * length + "px";
  container.style.height = height + "px";

  carrosselItems.forEach((item, i) => {
    const degressByItem = degress * i + "deg";
    item.style.setProperty("--rotatey", degressByItem);
    item.style.setProperty("--tz", tz + "px");
  });
};

// Funcion que da suavidad a la animacion
const lerp = (a, b, n) => {
  return n * (a - b) + b;
};

// https://3dtransforms.desandro.com/carousel
const distanceZ = (widthElement, length, gap) => {
  return widthElement / 2 / Math.tan(Math.PI / length) + gap; // Distancia Z de los items
};

// Calcula el alto del contenedor usando el campo de vision y la distancia de la perspectiva
const calculateHeight = (z) => {
  const t = Math.atan((90 * Math.PI) / 180 / 2);
  const height = t * 2 * z;

  return height;
};

// Calcula el campo de vision del carrossel
const calculateFov = (carrosselProps) => {
  const perspective = window
    .getComputedStyle(containercarrossel)
    .perspective.split("px")[0];

  const length =
    Math.sqrt(carrosselProps.w * carrosselProps.w) +
    Math.sqrt(carrosselProps.h * carrosselProps.h);
  const fov = 2 * Math.atan(length / (2 * perspective)) * (180 / Math.PI);
  return fov;
};

// Obtiene la posicion X y evalua si la posicion es derecha o izquierda
const getPosX = (x) => {
  currentMousePos = x;

  moveTo = currentMousePos < lastMousePos ? moveTo - 2 : moveTo + 2;

  lastMousePos = currentMousePos;
};

const update = () => {
  lastMoveTo = lerp(moveTo, lastMoveTo, 0.05);
  carrossel.style.setProperty("--rotatey", lastMoveTo + "deg");

  requestAnimationFrame(update);
};

const onResize = () => {
  // Obtiene la propiedades del tamaño de carrossel
  const boundingcarrossel = containercarrossel.getBoundingClientRect();

  const carrosselProps = {
    w: boundingcarrossel.width,
    h: boundingcarrossel.height,
  };

  return carrosselProps;
};

const initEvents = () => {
  // Eventos del mouse
  carrossel.addEventListener("mousedown", () => {
    isMouseDown = true;
    carrossel.style.cursor = "grabbing";
  });
  carrossel.addEventListener("mouseup", () => {
    isMouseDown = false;
    carrossel.style.cursor = "grab";
  });
  container.addEventListener("mouseleave", () => (isMouseDown = false));

  carrossel.addEventListener(
    "mousemove",
    (e) => isMouseDown && getPosX(e.clientX)
  );

  // Eventos del touch
  carrossel.addEventListener("touchstart", () => {
    isMouseDown = true;
    carrossel.style.cursor = "grabbing";
  });
  carrossel.addEventListener("touchend", () => {
    isMouseDown = false;
    carrossel.style.cursor = "grab";
  });
  container.addEventListener(
    "touchmove",
    (e) => isMouseDown && getPosX(e.touches[0].clientX)
  );

  window.addEventListener("resize", createcarrossel);

  update();
  createcarrossel();
};

initEvents();
 /*SECTION END LENGUAJES */