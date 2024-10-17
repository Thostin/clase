use empleados;

select apellido1 from empleado;
select distinct apellido1 from empleado;
select * from empleado;
select
    apellido1,
    apellido2
from empleado;
select codigo_departamento from empleado;
select distinct codigo_departamento from empleado;
select concat(nombre, ' ', apellido1, ' ', apellido2) from empleado;
select upper(concat(nombre, ' ', apellido1, ' ', apellido2)) from empleado;
select lower(concat(nombre, ' ', apellido1, ' ', apellido2)) from empleado;
select
    codigo,
    left(nif, 8),
    right(nif, 1)
from empleado;
select
    nombre,
    (abs(presupuesto - gastos) - gastos + presupuesto) / 2 as presupuesto_actual
from departamento
;
select
    nombre,
    (abs(presupuesto - gastos) - gastos + presupuesto) / 2 as presupuesto_actual
from departamento
order by presupuesto_actual asc;
select nombre from departamento order by nombre asc;
select nombre from departamento order by nombre desc;
select concat(apellido1, '', apellido2, ' ', nombre) as apellidos_y_nombres
from empleado
order by apellidos_y_nombres;
select
    nombre,
    presupuesto
from departamento order by presupuesto desc limit 3;
select
    nombre,
    presupuesto
from departamento order by presupuesto asc limit 3;
select
    nombre,
    gastos
from departamento order by gastos desc limit 2;
select
    nombre,
    gastos
from departamento order by gastos asc limit 2;
select
    nombre,
    presupuesto
from departamento where presupuesto >= 150000;
select
    nombre,
    gastos
from departamento where gastos < 5000;
select
    nombre,
    presupuesto
from departamento
where presupuesto >= 100000 and presupuesto <= 200000;
select
    nombre,
    gastos,
    presupuesto
from departamento where gastos > presupuesto;
select * from empleado where apellido2 is NULL;
select * from empleado where apellido2 is not NULL;
select * from empleado where apellido2 = 'López';
select * from empleado where apellido2 = 'Díaz' or apellido2 = 'Moreno';
select
    nombre,
    apellido1,
    apellido2,
    nif
from empleado
where codigo_departamento = 3;
select
    nombre,
    apellido1,
    apellido2,
    nif
from empleado
where codigo_departamento in (2, 4, 5);
select gastos * 85 / 100 from departamento where gastos > presupuesto;
select * from empleado where codigo_departamento is NULL;
select *
from departamento
where codigo not in (select codigo_departamento from empleado);
select sum(presupuesto) from departamento;
select avg(presupuesto) from departamento;
select presupuesto from departamento order by presupuesto asc limit 1;
select
    nombre,
    presupuesto
from departamento order by presupuesto asc limit 1;
select presupuesto as presupuesto_maximo
from departamento
order by presupuesto desc
limit 1
;
select sum(codigo / codigo) from empleado;
