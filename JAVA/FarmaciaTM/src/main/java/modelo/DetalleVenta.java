/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import Clases.Conection;

import Clases.Sentencias;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author thotstin
 */
public class DetalleVenta extends Conection implements Sentencias {

    private int Venta_idVenta;
    private int Medicamento_idMedicamento;

    private String descripcion;
    private double precio;
    private int cantidad;
    private double subTotal;

    @Override
    public boolean insertar() {
        String sql = "INSERT INTO DetalleVenta(Venta_idVenta, Medicamento_idMedicamento, cantidad) VALUES(?, ?, ?)";
        try (Connection con = getCon(); PreparedStatement stm = con.prepareStatement(sql)) {
            //stm.setInt(1,this.);
            stm.setInt(1, this.Venta_idVenta);
            stm.setInt(2, this.Medicamento_idMedicamento);
            stm.setInt(3, this.cantidad);
            stm.executeUpdate();
            return true;
        } catch (SQLException ex) {
            Logger.getLogger(DetalleVenta.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
    }

    public DetalleVenta(int Medicamento_idMedicamento, String descripcion, double precio, int cantidad, double subTotal) {
        this.Medicamento_idMedicamento = Medicamento_idMedicamento;
        this.descripcion = descripcion;
        this.precio = precio;
        this.cantidad = cantidad;
        this.subTotal = subTotal;
    }

    @Override
    public ArrayList consulta() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public boolean actualizar() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public boolean eliminar() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    public void setVenta_idVenta(int Venta_idVenta) {
        this.Venta_idVenta = Venta_idVenta;
    }

    public void setMedicamento_idMedicamento(int Medicamento_idMedicamento) {
        this.Medicamento_idMedicamento = Medicamento_idMedicamento;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public void setSubTotal(double subTotal) {
        this.subTotal = subTotal;
    }

    public int getVenta_idVenta() {
        return Venta_idVenta;
    }

    public int getMedicamento_idMedicamento() {
        return Medicamento_idMedicamento;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public double getPrecio() {
        return precio;
    }

    public int getCantidad() {
        return cantidad;
    }

    public double getSubTotal() {
        return subTotal;
    }

}
