
document.getElementById('showRegister').addEventListener('click', function(event) {
    event.preventDefault();
    document.getElementById('formulario').style.display = 'block';
    document.getElementById('formulario2').style.display = 'none'; 
});
document.getElementById('showLogin').addEventListener('click', function(event) {
    event.preventDefault(); 
    document.getElementById('formulario').style.display = 'none';
    document.getElementById('formulario2').style.display = 'block'; 
});

document.getElementById('showAdminRegister').addEventListener('click', function(e) {
    e.preventDefault();
    document.getElementById('formulario').style.display = 'block';
    document.getElementById('formulario2').style.display = 'none';
});

document.getElementById('showAdminLogin').addEventListener('click', function(e) {
    e.preventDefault();
    document.getElementById('formulario').style.display = 'none';
    document.getElementById('formulario2').style.display = 'block';
});