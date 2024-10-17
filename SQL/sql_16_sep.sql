drop database if exists kopta;
create database kopta;
use kopta;


CREATE TABLE pais (
`idPais` VARCHAR(3) NOT NULL ,
`nombre` VARCHAR(20) NULL ,
PRIMARY KEY (`idPais`) )
ENGINE = InnoDB;
CREATE TABLE jugadores (
`codigo` VARCHAR(3) NOT NULL ,
`nombre` VARCHAR(20) NULL ,
`apellido` VARCHAR(20) NULL ,
`posicion` VARCHAR(20) NULL ,
`idPais` VARCHAR(3) NOT NULL ,
PRIMARY KEY (`codigo`) ,
INDEX (idPais) ,
FOREIGN KEY (idPais )
REFERENCES pais (idPais )
ON DELETE NO ACTION
ON UPDATE NO ACTION)
ENGINE = InnoDB;

INSERT INTO pais(`idPais`,nombre) VALUES('ESP','España');
INSERT INTO pais(`idPais`,nombre) VALUES('ARG','Argentina');
INSERT INTO pais(`idPais`,nombre) VALUES('AUS','Australia');
INSERT INTO pais(`idPais`,nombre) VALUES('LIT','Lituania');

INSERT INTO jugadores(codigo,nombre,apellido,posicion,`idPais`)
VALUES('RUB','Ricky','Rubio','Base','ESP');
INSERT INTO jugadores(codigo,nombre,apellido,posicion,`idPais`) VALUES('NAV','Juan
Carlos','Navarro','Alero','ESP');

INSERT INTO jugadores(codigo,nombre,apellido,posicion,`idPais`) VALUES('SCO','Luis','Scola','Ala-
Pivot','ARG');

INSERT INTO jugadores(codigo,nombre,apellido,posicion,`idPais`)
VALUES('DEL','Carlos','Delfino','Escolta','ARG');
INSERT INTO jugadores(codigo,nombre,apellido,posicion,`idPais`)
VALUES('MAC','Jonas','Maciulis','Alero','LIT');
INSERT INTO jugadores(codigo,nombre,apellido,posicion,`idPais`)
VALUES('BOG','Andrew','Bogut','Pivot','AUS')

SELECT UPPER(nombre), UPPER(apellido) FROM jugadores ORDER BY apellido, nombre;
SELECT CONCAT(apellido, ', ', nombre) AS nombreJug FROM jugadores WHERE pais = 'España';
SELECT LEFT(apellido, 4) FROM jugadores WHERE pais = 'Argentina' ORDER BY apellido DESC;
SELECT CONCAT('Don ', nombre, ' ', apellido) FROM jugadores;
SELECT TRIM(nombre), TRIM(apellido) FROM jugadores WHERE pais LIKE 'N';
SELECT nombre, LENGTH(apellido) AS longitud_apellido FROM jugadores;
SELECT UPPER(nombre), LOWER(apellido) FROM jugadores;


