drop database if exists Tienda_de_karai_kacho;
create database Tienda_de_karai_kacho;

use Tienda_de_karai_kacho;

create table Productos (
    Id INT primary key,
    Nombre VARCHAR(50),
    Precio DECIMAL(10, 2),
    Cantidad INT
);

insert into Productos (
    Id, Nombre,
    Precio, Cantidad
)
values
(1, 'Producto A', 10.50, 100),
(2, 'Producto B', 15.75, 50),
(3, 'Producto C', 8.99, 75),
(4, 'Producto D', 20.00, 30),
(5, 'Producto E', 12.49, 90);


select Precio * Cantidad as Precios_totales from Productos;

select min(Precio) as Producto_mas_barato from Productos;

select max(Precio) as Producto_mas_caro from Productos;

select avg(Precio * Cantidad) as Promedio_de_precios from Productos;

select count(Id) as Cantidad_mayor_que_15 from Productos where Precio > 15.00;

select sum(Precio * Cantidad) as Precio_total_del_inventario from Productos;

select avg(Precio) as Precio_promedio from Productos;

select
    0.9
    * sum(Precio * Cantidad)
        as Precio_total_del_inventario_con_descuento_del_10_por_ciento
from Productos;

select Precio as Precios_mayores_al_promedio
from Productos
where Precio > (select avg(Precio) from Productos);

select Precio * Precio as Cuadrado_de_los_precios from Productos;
