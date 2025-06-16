/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Clases;

/**
 *
 * @author thotstin
 */
public class VentaSingleton {
    // Atributos de la clase: código del cliente y código del producto
    int idCliente;
    int idProducto;

    // Constructor privado para evitar que se puedan crear instancias desde fuera de la clase
    private VentaSingleton() {
    }

    // Método público estático para obtener la única instancia de la clase
    public static VentaSingleton getInstance() {
        return VentaSingletonHolder.INSTANCE; // Retorna la instancia contenida en la clase interna
    }

    // Clase estática interna que contiene la instancia única de ventaSingleton
    // Esta técnica asegura que la instancia se cree solo cuando se llama a getInstance()
    private static class VentaSingletonHolder {
        private static final VentaSingleton INSTANCE = new VentaSingleton(); // Instancia única
    }

    // Getter para obtener el código del cliente
    public int getIdCliente() {
        return idCliente;
    }

    // Setter para establecer el código del cliente
    public void setIdCliente(int idCliente) {
        this.idCliente = idCliente;
    }

    // Getter para obtener el código del producto
    public int getIdProducto() {
        return idProducto;
    }

    // Setter para establecer el código del producto
    public void setIdProducto(int idProducto) {
        this.idProducto = idProducto;
    }
}
