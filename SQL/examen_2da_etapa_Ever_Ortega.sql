drop database if exists kljop;
create database kljop;

use kljop;
-- Estructura de la base de datos

-- Tabla persona
create table persona (
    id INT primary key auto_increment,
    nif VARCHAR(9) not null,
    nombre VARCHAR(25) not null,
    apellido1 VARCHAR(50) not null,
    apellido2 VARCHAR(50),
    ciudad VARCHAR(25),
    direccion VARCHAR(50),
    telefono VARCHAR(9),
    fecha_nacimiento DATE,
    sexo ENUM('H', 'M'),
    tipo ENUM('Alumno', 'Profesor')
);

-- Tabla departamento
create table departamento (
    id INT primary key auto_increment,
    nombre VARCHAR(50) not null
);

-- Tabla profesor
create table profesor (
    id_profesor INT primary key auto_increment,
    id_departamento INT,
    foreign key (id_departamento) references departamento (id)
);

-- Tabla grado
create table grado (
    id INT primary key auto_increment,
    nombre VARCHAR(100) not null
);

-- Tabla asignatura
create table asignatura (
    id INT primary key auto_increment,
    nombre VARCHAR(100) not null,
    creditos FLOAT not null,
    tipo ENUM('Obligatoria', 'Optativa'),
    curso TINYINT(3),
    cuatrimestre TINYINT(3),
    id_profesor INT,
    id_grado INT,
    foreign key (id_profesor) references profesor (id_profesor),
    foreign key (id_grado) references grado (id)
);

-- Tabla curso_escolar
create table curso_escolar (
    id INT primary key auto_increment,
    anyo_inicio YEAR(4) not null,
    anyo_fin YEAR(4) not null
);

-- Tabla alumno_se_matricula_asignatura
create table alumno_se_matricula_asignatura (
    id_alumno INT,
    id_asignatura INT,
    id_curso_escolar INT,
    primary key (id_alumno, id_asignatura, id_curso_escolar),
    foreign key (id_alumno) references persona (id),
    foreign key (id_asignatura) references asignatura (id),
    foreign key (id_curso_escolar) references curso_escolar (id)
);

-- Insertar datos en la tabla persona
insert into persona (
    nif,
    nombre,
    apellido1,
    apellido2,
    ciudad,
    direccion,
    telefono,
    fecha_nacimiento,
    sexo,
    tipo
)
values
(
    '12345678A',
    'Juan',
    'Pérez',
    'García',
    'Madrid',
    'Calle Mayor 10',
    '600123456',
    '1990-05-12',
    'H',
    'Alumno'
),
(
    '87654321B',
    'Ana',
    'López',
    'Martínez',
    'Barcelona',
    'Avenida Diagonal 50',
    '600654321',
    '1985-08-23',
    'M',
    'Profesor'
),
(
    '12345679C',
    'Carlos',
    'Fernández',
    'Gómez',
    'Sevilla',
    'Calle Sierpes 12',
    '600789123',
    '1993-11-30',
    'H',
    'Alumno'
),
(
    '87654322D',
    'María',
    'Sánchez',
    'Rodríguez',
    'Valencia',
    'Calle Colón 25',
    '600321987',
    '1980-03-05',
    'M',
    'Profesor'
);

-- Insertar datos en la tabla departamento
insert into departamento (nombre)
values
('Matemáticas'),
('Física'),
('Informática'),
('Lenguas Extranjeras');

-- Insertar datos en la tabla profesor
insert into profesor (id_departamento)
values
(1),  -- Profesor en el departamento de Matemáticas
(2);  -- Profesor en el departamento de Física

-- Insertar datos en la tabla grado
insert into grado (nombre)
values
('Grado en Ingeniería Informática'),
('Grado en Física'),
('Grado en Matemáticas');

-- Insertar datos en la tabla asignatura
insert into asignatura (
    nombre, creditos, tipo, curso, cuatrimestre, id_profesor, id_grado
)
values
-- Profesor de Matemáticas imparte Álgebra
('Álgebra', 6.0, 'Obligatoria', 1, 1, 1, 3),
-- Profesor de Matemáticas imparte Cálculo
('Cálculo', 6.0, 'Obligatoria', 1, 2, 1, 3),
-- Profesor de Física imparte Física I
('Física I', 6.0, 'Obligatoria', 1, 1, 2, 2),
-- No tiene asignado profesor aún
('Programación', 6.0, 'Obligatoria', 1, 2, NULL, 1);

-- Insertar datos en la tabla curso_escolar
insert into curso_escolar (anyo_inicio, anyo_fin)
values
(2023, 2024),
(2024, 2025);

-- Insertar datos en la tabla alumno_se_matricula_asignatura
insert into alumno_se_matricula_asignatura (
    id_alumno, id_asignatura, id_curso_escolar
)
values
(1, 1, 1), -- Juan Pérez se matricula en Álgebra en el curso 2023-2024
(1, 2, 1), -- Juan Pérez se matricula en Cálculo en el curso 2023-2024
(3, 3, 1), -- Carlos Fernández se matricula en Física I en el curso 2023-2024
-- Carlos Fernández se matricula en Programación en el curso 2023-2024
(3, 4, 1);


-- 1 
-- select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as nombre_completo
-- from persona p
-- left join alumno_se_matricula_asignatura a on p.id = a.id_alumno
-- where p.id is not NULL
-- order by nombre_completo asc;

-- 1.2:
select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as nombre_completo
from persona p
where p.id in (select id_alumno from alumno_se_matricula_asignatura)
order by nombre_completo asc;

-- 2:
select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as nombre_completo
from persona p
where p.id  in (select id_alumno from alumno_se_matricula_asignatura) and p.telefono is NULL;

-- 3:
select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as alumnos_nacidos_en_1999
from persona p
where p.id  in (select id_alumno from alumno_se_matricula_asignatura) and YEAR(p.fecha_nacimiento) = '1999';


-- 4:
select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as profesores
from persona p
where p.id  in (select id_profesor from profesor) and p.telefono is NULL and substring(p.nif, 9, 9) = 'k';

-- 5:
-- select * from asignatura a where (select nombre from grado where grado.id = a.id) = 'Grado en Ingeniería Informática';
select * from asignatura where id_grado = (select id from grado where nombre = 'Grado en Ingeniería Informática');

-- 6:

select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as alumnas_INFO
from persona p
where p.id  in (select id_alumno from alumno_se_matricula_asignatura where id_asignatura in
  (select id from asignatura where id_grado = (select id from grado where nombre = 'Grado en Ingeniería Informática')))
and p.sexo = 'M';

-- 7:
select concat(p.apellido1, ', ', p.apellido2, ', ', p.nombre) as alumnos_2018_2019
from persona p
where p.id  in (select id_alumno from alumno_se_matricula_asignatura where id_curso_escolar in (select id from curso_escolar where anyo_inicio = 2018 and anyo_fin = 2019));

-- 8:
select p.apellido1, p.apellido2, p.nombre from persona p join departamento where p.tipo = 'Profesor';
-- 9:
select count(id)
from persona p
where p.id  in (select id_alumno from alumno_se_matricula_asignatura)
and p.sexo = 'M';

-- 10:
select count(id)
from persona p
where p.id  in (select id_alumno from alumno_se_matricula_asignatura)
and YEAR(fecha_nacimiento) = '1999';

-- 11:
select *
from persona p
where p.id in (select id_alumno from alumno_se_matricula_asignatura)
order by fecha_nacimiento desc limit 1;

-- 12:
select * from persona p where p.id in (select id_profesor from profesor where id_departamento is NULL);

-- 13:
-- select * from persona p where p.in in (select id_profesor from profesor where id_departamento is NOT NULL) and p.id NOT IN (select id_profesor from asignatura);
-- al parecer no hay una manera de saber quién es el profesor, pero sí su id
-- select id_profesor from profesor where p.tipo = 'Profesor' and p.id NOT IN (select id_profesor from asignatura);
select id_profesor as ids_profesores_sin_asignatura_con_departamento from profesor where id_profesor not in (select id_profesor from asignatura) and id_departamento is not NULL;

-- 14: 26902806M 
select a.nombre from asignatura a join curso_escolar on
a.id in (select id_asignatura from alumno_se_matricula_asignatura where id_alumno in (select l.id from persona l where l.nif = '26902806M')); 

-- 15:
select a.nombre as asignaturas from asignatura a where a.cuatrimestre = 1 and a.curso = 3 and a.id_grado = 7;

