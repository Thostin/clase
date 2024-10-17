DROP DATABASE IF EXISTS empleados;

CREATE DATABASE empleados;
USE empleados;

CREATE TABLE departamento (
    codigo INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    presupuesto DOUBLE UNSIGNED NOT NULL,
    gastos DOUBLE UNSIGNED NOT NULL
);

CREATE TABLE empleado (
    codigo INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    nif VARCHAR(9) NOT NULL UNIQUE,
    nombre VARCHAR(100) NOT NULL,
    apellido1 VARCHAR(100) NOT NULL,
    apellido2 VARCHAR(100),
    codigo_departamento INT UNSIGNED,
    FOREIGN KEY (codigo_departamento) REFERENCES departamento (codigo)
);
INSERT INTO departamento VALUES (1, 'Desarrollo', 120000, 6000);
INSERT INTO departamento VALUES (2, 'Sistemas', 150000, 21000);
INSERT INTO departamento VALUES (3, 'Recursos Humanos', 280000, 25000);
INSERT INTO departamento VALUES (4, 'Contabilidad', 110000, 3000);
INSERT INTO departamento VALUES (5, 'I+D', 375000, 380000);
INSERT INTO departamento VALUES (6, 'Proyectos', 0, 0);
INSERT INTO departamento VALUES (7, 'Publicidad', 0, 1000);
INSERT INTO empleado VALUES (1, '32481596F', 'Aarón', 'Rivero', 'Gómez', 1);
INSERT INTO empleado VALUES (2, 'Y5575632D', 'Adela', 'Salas', 'Díaz', 2);
INSERT INTO empleado VALUES (3, 'R6970642B', 'Adolfo', 'Rubio', 'Flores', 3);
INSERT INTO empleado VALUES (4, '77705545E', 'Adrián', 'Suárez', NULL, 4);
INSERT INTO empleado VALUES (5, '17087203C', 'Marcos', 'Loyola', 'Méndez', 5);
INSERT INTO empleado VALUES (6, '38382980M', 'María', 'Santana', 'Moreno', 1);
INSERT INTO empleado VALUES (7, '80576669X', 'Pilar', 'Ruiz', NULL, 2);
INSERT INTO empleado VALUES (8, '71651431Z', 'Pepe', 'Ruiz', 'Santana', 3);
INSERT INTO empleado VALUES (9, '56399183D', 'Juan', 'Gómez', 'López', 2);

INSERT INTO empleado VALUES (10, '46384486H', 'Diego', 'Flores', 'Salas', 5);
INSERT INTO empleado VALUES (11, '67389283A', 'Marta', 'Herrera', 'Gil', 1);
INSERT INTO empleado VALUES (12, '41234836R', 'Irene', 'Salas', 'Flores', NULL);
INSERT INTO empleado VALUES (
    13, '82635162B', 'Juan Antonio', 'Sáez', 'Guerrero',
    NULL
);








SELECT apellido1 FROM empleado;
SELECT DISTINCT apellido1 FROM empleado;
SELECT * FROM empleado;
SELECT
    apellido1,
    apellido2
FROM empleado;
SELECT codigo_departamento FROM empleado;
SELECT DISTINCT codigo_departamento FROM empleado;
SELECT concat(nombre, ' ', apellido1, ' ', apellido2) FROM empleado;
SELECT upper(concat(nombre, ' ', apellido1, ' ', apellido2)) FROM empleado;
SELECT lower(concat(nombre, ' ', apellido1, ' ', apellido2)) FROM empleado;
SELECT
    codigo,
    left(nif, 8),
    right(nif, 1)
FROM empleado;
SELECT
    nombre,
    (abs(presupuesto - gastos) - gastos + presupuesto) / 2 AS presupuesto_actual
FROM departamento
;
SELECT
    nombre,
    (abs(presupuesto - gastos) - gastos + presupuesto) / 2 AS presupuesto_actual
FROM departamento
ORDER BY presupuesto_actual ASC;
SELECT nombre FROM departamento ORDER BY nombre ASC;
SELECT nombre FROM departamento ORDER BY nombre DESC;
SELECT concat(apellido1, '', apellido2, ' ', nombre) AS apellidos_y_nombres
FROM empleado
ORDER BY apellidos_y_nombres;
SELECT
    nombre,
    presupuesto
FROM departamento ORDER BY presupuesto DESC LIMIT 3;
SELECT
    nombre,
    presupuesto
FROM departamento ORDER BY presupuesto ASC LIMIT 3;
SELECT
    nombre,
    gastos
FROM departamento ORDER BY gastos DESC LIMIT 2;
SELECT
    nombre,
    gastos
FROM departamento ORDER BY gastos ASC LIMIT 2;
SELECT
    nombre,
    presupuesto
FROM departamento WHERE presupuesto >= 150000;
SELECT
    nombre,
    gastos
FROM departamento WHERE gastos < 5000;
SELECT
    nombre,
    presupuesto
FROM departamento
WHERE presupuesto >= 100000 AND presupuesto <= 200000;
SELECT
    nombre,
    gastos,
    presupuesto
FROM departamento WHERE gastos > presupuesto;
SELECT * FROM empleado WHERE apellido2 IS NULL;
SELECT * FROM empleado WHERE apellido2 IS NOT NULL;
SELECT * FROM empleado WHERE apellido2 = 'López';
SELECT * FROM empleado WHERE apellido2 = 'Díaz' OR apellido2 = 'Moreno';
SELECT
    nombre,
    apellido1,
    apellido2,
    nif
FROM empleado
WHERE codigo_departamento = 3;
SELECT
    nombre,
    apellido1,
    apellido2,
    nif
FROM empleado
WHERE codigo_departamento IN (2, 4, 5);
SELECT gastos * 85 / 100 FROM departamento WHERE gastos > presupuesto;
SELECT * FROM empleado WHERE codigo_departamento IS NULL;
SELECT *
FROM departamento
WHERE codigo NOT IN (SELECT codigo_departamento FROM empleado);
SELECT sum(presupuesto) FROM departamento;
SELECT avg(presupuesto) FROM departamento;
SELECT presupuesto FROM departamento ORDER BY presupuesto ASC LIMIT 1;
SELECT
    nombre,
    presupuesto
FROM departamento ORDER BY presupuesto ASC LIMIT 1;
SELECT presupuesto AS presupuesto_maximo
FROM departamento
ORDER BY presupuesto DESC
LIMIT 1
;
SELECT sum(codigo / codigo) FROM empleado;
