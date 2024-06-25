CREATE DATABASE lib;
USE lib;

CREATE TABLE autores (
    id_autor int,
    nombre varchar(45),
    nacionalidad varchar(30)
-- PRIMARY KEY(id_autor)
);

CREATE TABLE libros (
    id_libro int,
    titulo varchar(100),
    ano int,
    id_autor int,
    FOREIGN KEY (id_libro) REFERENCES autores (id_libro)
);

INSERT INTO autores (
    id_autor,
    nombre,
    nacionalidad
)

VALUES
(
    1,
    "Gabriel García Márquez",
    "Colombia"
),
(
    2,
    "J. K. Rowding",
    "Reino Unido"
),
(
    3,
    "George Orwell",
    "Reino Unido"
);

INSERT INTO libros (
    id_libro,
    titulo,
    ano,
    id_autor
)
VALUES
(
    1,
    "Cien años de soledad",
    1967,
    1
),
(
    2,
    "Harry Potter y la Piedra Filosofal",
    1997,
    2
),
(
    3,
    "1984",
    1949,
    3
),
(
    4,
    "El Amor en los Tiempos de Cólera",
    1985,
    1
);
