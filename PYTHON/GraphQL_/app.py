from ariadne import QueryType, make_executable_schema, load_schema_from_path
from ariadne.asgi import GraphQL
import uvicorn
from resolvers import resolver_bienvenida, resolver_despedida, resolver_obtenerPersona, resolver_obtenerEdad

type_defs = load_schema_from_path("schema.graphql")


query = QueryType()

query.set_field("bienvenida", resolver_bienvenida)
query.set_field("despedida", resolver_despedida)
query.set_field("obtenerPersona", resolver_obtenerPersona)
query.set_field("obtenerEdad", resolver_obtenerEdad)

esquema = make_executable_schema(type_defs, query)

app = GraphQL(esquema)

if __name__ == "__main__":
    uvicorn.run(app, host="127.0.0.1", port=8000)
