drop database if exists veterinaria;

create database
veterinaria;

use veterinaria;

create table mascotas (
    nombre VARCHAR(20),
    propietario VARCHAR(20),
    especie VARCHAR(20),
    sexo CHAR(1),
    nacimiento DATE,
    fallecimiento DATE
);

insert into mascotas (
    nombre, propietario, especie, sexo, nacimiento, fallecimiento
)
values ("Fluffy", "Arnoldo", "Gato", "f", "1999-02-04", null),
("Mau", "Juan", "Gato", "m", "1998-03-17", null),
("Buffy", "Arnoldo", "Perro", "f", "1999-05-13", null),
("FanFan", "Benito", "Perro", "m", "2000-08-27", null),
("Kaiser", "Diana", "Perro", "m", "1998-08-31", "2008-07-29"),
("Chispa", "Omar", "Ave", "f", "1998-09-11", null),
("Wicho", "Tomas", "Ave", "m", "2000-02-09", null),
("Skim", "Benito", "Serpiente", "m", "2001-04-29", null);













-- select YEAR(DATE_SUB(NOW(), INTERVAL nacimiento)) from mascotas;
-- select YEAR(DATEDIFF(NOW(), nacimiento)) from mascotas;
-- select TIMESTAMPDIFF(year, nacimiento, NOW()) from mascotas;
-- select TIMESTAMPDIFF(year, nacimiento, (select NOW() if fallecimiento = null else fallecimiento) from mascotas) from mascotas;
-- select TIMESTAMPDIFF(year, nacimiento, (select NOW() if fallecimiento = null else fallecimiento from mascotas)) from mascotas;


select TIMESTAMPDIFF(year, nacimiento, NOW()) from mascotas;

select TIMESTAMPDIFF(year, nacimiento, fallecimiento) from mascotas where fallecimiento is not null;

select MONTH(nacimiento) from mascotas;

select MONTH(nacimiento) from mascotas where MONTH(nacimiento) = MONTH(NOW());

select MONTH(nacimiento) from mascotas where MONTH(nacimiento) = MONTH(NOW()) + 1;


