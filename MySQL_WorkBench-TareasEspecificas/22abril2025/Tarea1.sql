insert into dept
VALUES
(10, "CONTABILIDAD", "ELCHE"),
(20, "INVESTIGACIÓN", "MADRID"),
(30, "VENTAS", "BARCELONA"),
(40, "PRODUCCIÓN", "SALAMANCA");

insert into emp
values
(7119, "SERRA", "DIRECTOR", 7839, "1983-11-19 00:00:00", 225000.00, 39000.00, 20),
(7322, "GARCIA", "EMPLEADO", 7119, "1982-10-12 00:00:00", 129000.00, 0.00, 20),
(7369, "SANCHEZ", "EMPLEADO", 7902, "1980-12-17 00:00:00", 10400.00, 0.00, 20),
(7499, "ARROYO", "VENDEDOR", 7698, "1981-02-22 00:00:00", 208000.00, 39000.00, 30),
(7521, "SALA", "VENDEDOR", 689, "1981-02-22 00:00:00", 162500.00, 65000.00, 30);

insert into hospital
values
(18, "GENERAL", "ATOCHA S/N", "595-3111", 987),
(19, "PROVINCIAL", "O Donell 50", "964-4256", 502),
(22, "La Paz", "Castellana 1000", "923-5411", 412),
(45, "San Carlos", "Ciudad Universitaria", "597-1500", 845);

insert into doctor
values
(386, 22, "Cabeza D.", "Psiquiatría"),
(398, 22, "Best D.", "Urología"),
(435, 19, "López A.", "Cardiología"),
(453, 22, "Galo D.", "Pediatría");

insert into sala
values
(1, 22, "Recuperación", 10),
(1, 45, "Recuperación", 15),
(2, 22, "Maternidad", 34),
(2, 45, "Maternidad", 24),
(3, 18, "Ciudadanos Intensivos", 10),
(3, 19, "Ciudadanos Intensivos", 21),
(4, 18, "Cardiología", 53);

/*
insert into plantilla
values
(1280, 4, 45, "Amigo R.", "Interino", "N", 221000.00),
(6065, 1, 22, "Rivera G.", "Enfermera", "N", 162600.00),
(6357, 4, 18, "Karplus W.", "Interino", "T", 337900.00);
*/

insert into plantilla 
values
(1280, 4, 18, "Amigo R.", "Interino", "N", 221000.00),
(6065, 1, 22, "Rivera G.", "Enfermera", "N", 162600.00),
(6357, 4, 18, "Karplus W.", "Interino", "T", 337900.00);

insert into enfermo
values
(10995, "Laguía M.", "Goya 20", "16-may-56", "M", 280862422),
(14024, "Fernández M.", "Recoletos 50", "21-may-60", "F", 284991452),
(18004, "Serrano V.", "Alcalá 12", "23-jun-67", "F", 321790059),
(36658, "Dormin S.", "Mayor 71", "01-ene-42", "M", 160654471),
(38702, "Neal R.", "Orense 11", "18-jun-40", "F", 380010217);

-- 2
insert into dept
values
(50, "INFORMÁTICA", "MADRID");

-- 1
insert into emp
values
(8912, "BARRERA", "INFORMÁTICO", 7839, "2025-04-22 00:00:00", 70000.00, 0.00, 50);

--3
update dept set Loc = "Lerida" where Dept_No = 30;

--4
insert into emp
values
(8913, "ROMERAL", "VENDEDOR", 7850, "2025-04-22 00:00:00", 80000.00, 12000.00, 30),
(8914, "ALONSO", "VENDEDOR", 9850, "2025-04-22 00:00:00", 80000.00, 12000.00, 30);

--5
update emp
set
Comision = Comision + Salario*0.1
where Emp_No = Emp_No;

--6
update emp
set 
salario	= 1.05 * salario where Emp_No in (select Empleado_No from plantilla where T="N");

--7
update 
emp
set
salario = salario + 5000
where
dept_Dept_No = 30;

--8
update 
hospital
set 
Num_Cama = Num_Cama - 100 
where Nombre = "San Carlos";

--9
delete 
from
emp
where
Fecha_Alt >= "1980-01-01 00:00:00" and Fecha_Alt <= "1982-12-31 00:00:00";

--10
delete 
from
enfermo
where 
Inscripcion=36658;

--11
delete 
from
emp
where 
dept_Dept_No = 40;
