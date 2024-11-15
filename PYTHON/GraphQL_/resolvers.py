def resolver_bienvenida(obj, info):
    return "¡Bienvenidos a nuestra API!"

def resolver_despedida(obj, info, nombre):
    return f"¡Adiós, {nombre}! Que tengas un buen día."

personas_db = {
    "1": {"id": "1", "nombre": "Juan", "edad": 35},
    "2": {"id": "2", "nombre": "María", "edad": 28},
    "3": {"id": "3", "nombre": "Carlos", "edad": 40},
    "4": {"id": "4", "nombre": "Lucía", "edad": 22},
}

def resolver_obtenerPersona(obj, info, id):
    return personas_db.get(id)

def resolver_obtenerEdad(obj, info, id):
    persona = personas_db.get(id)
    return persona["edad"] if persona else None
