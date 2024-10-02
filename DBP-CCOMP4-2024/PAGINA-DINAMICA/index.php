

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CV</title>
    <link rel="stylesheet" type="text/CSS" href="CSS/style_form.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
    <script src="index.js"></script>
</head>
<body>
    
<div class="form-container">
    <form action="mostrar_cv.php" method="POST"   class="register">
        <h3>Ingresa tus datos</h3>
        <div class="flex">
            <div class="col">
                
                <div class="input-field">
                    <p>Nombre y Apellidos <span class="asterisco">*</span></p>
                    <input type="text" name="nombre" placeholder="Ingresa tu nombre completo" maxlength="50" required class="box">
                </div>
                
                <div class="input-field">
                    <p>Fecha de Nacimiento <span class="asterisco">*</span></p>
                    <input type="date" name="fecha_nacimiento"  required class="box">
                </div>
                
                <div class="input-field">
                    <p>Ocupación <span class="asterisco">*</span></p>
                    <input type="text" name="ocupacion" placeholder="Ingresa tu ocupación" maxlength="50" required class="box">
                </div>
                
                <div class="input-field">
                    <p>Contacto ( Email) <span class="asterisco">*</span></p>
                    <input type="email" name="contacto" placeholder="Ingresa tu email" required pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}$" class="box">
                </div>

                <div id="formacion-container" class="input-field">
                    <p>Formación profesional<span class="asterisco">*</span>
                        <button type="button" onclick="addFormacion()">
                            <div class="tooltip-container">
                                <span class="tooltip">Agregar más profesiones</span>
                                <span class="text"><i class="fas fa-plus"></i></span>
                            </div>
                        </button>
                    </p>
                    <input type="text" name="formacion[]" placeholder="Descripción de la formación" required class="box">
                </div>

                <div id="habilidades-container" class="input-field">

                    <p>Habilidades <span class="asterisco">*</span></p>
                    <input type="checkbox" name="habilidades[]" value="HTML"> HTML
                    <input type="checkbox" name="habilidades[]" value="CSS"> CSS
                    <input type="checkbox" name="habilidades[]" value="JavaScript"> JavaScript
                    <input type="checkbox" name="habilidades[]" value="SQL"> SQL
                </div>
            </div>
            <div class="col">
                
                <div class="input-field">
                    <p>Nacionalidad <span class="asterisco">*</span></p>
                    <select name="nacionalidad" required class="box">
                        <option value="" disabled selected>Selecciona tu nacionalidad</option>
                        <option value="Argentina">Argentina</option>
                        <option value="Brasil">Brasil</option>
                        <option value="Chile">Chile</option>
                        <option value="México">México</option>
                        <option value="Perú">Perú</option>
                    </select>
                </div>

                <div class="input-field">
                    <p>Nivel de Inglés <span class="asterisco">*</span></p>
                    <input type="radio" name="nivel_ingles" value="básico" required> Básico
                    <input type="radio" name="nivel_ingles" value="intermedio"> Intermedio
                    <input type="radio" name="nivel_ingles" value="avanzado"> Avanzado
                    <input type="radio" name="nivel_ingles" value="fluido"> Fluido
                </div>

                <div id="idiomas-container" class="input-field">
                    <p>Idiomas <span class="asterisco">*</span>
                        <button type="button" onclick="addIdioma()">
                            <div class="tooltip-container">
                                <span class="tooltip">Agregar más idiomas</span>
                                <span class="text"><i class="fas fa-plus"></i></span>
                            </div>
                        </button>
                    </p>
                    <input type="text" name="idiomas[]" placeholder="Idioma y nivel" required class="box">
                </div>
                
                <div class="input-field">
                    <p>Lenguajes de Programación <span class="asterisco">*</span></p>
                    <select name="lenguajes[]" multiple required class="box">
                        <option value="php">PHP</option>
                        <option value="javascript">JavaScript</option>
                        <option value="cpp">C++</option>
                        <option value="java">Java</option>
                        <option value="python">Python</option>
                    </select>
                </div>
                
                <div id="aptitudes-container" class="input-field">
                    <p>Aptitudes<span class="asterisco">*</span>  
                        <button type="button" onclick="addAptitud()">
                            <div class="tooltip-container">
                                <span class="tooltip">Agregar más aptitudes</span>
                                <span class="text"><i class="fas fa-plus"></i></span>
                            </div>
                        </button>
                    </p> 
                    <input list="aptitudes" name="aptitudes[]" placeholder="Selecciona o ingresa una aptitud" required class="box">
                    <datalist id="aptitudes">
                        <option value="Trabajo en equipo">
                        <option value="Resolución de problemas">
                        <option value="Liderazgo">
                        <option value="Comunicación efectiva">
                    </datalist>
                </div>

                <div id="experiencia-laboral-container" class="input-field">
                    <p>Experiencia Laboral <span class="asterisco">*</span>
                        <button type="button" onclick="addExperiencia()">
                            <div class="tooltip-container">
                                <span class="tooltip">Agregar más experiencias laborales</span>
                                <span class="text"><i class="fas fa-plus"></i></span>
                            </div>
                        </button>
                    </p>
                    <input type="text" name="experiencia_laboral[]" placeholder="Descripción de la experiencia" required class="box">
                </div>
            </div>
        </div>
        
        <div class="input-field">
            <p>Perfil <span class="asterisco">*</span></p>
            <textarea name="perfil" rows="4" placeholder="Describe tu perfil aqui..." required class="box"></textarea>
        </div>
        
        <input type="submit" name="submit" value="Enviar" class="btn">
    </form>
</div>
</body>
</html>
