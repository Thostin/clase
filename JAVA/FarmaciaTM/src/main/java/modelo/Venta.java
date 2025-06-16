/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import Clases.Conection;

import Clases.Sentencias;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author thotstin
 */
public class Venta extends Conection implements Sentencias {

    private int id;
    private String fecha;
    private double total;
    private String metodo;
    private int idCliente;
    private int idEmpleado = 1;

    private long lastId = -1;

    public Venta(int id, String fecha, String metodo, Integer total, int idCliente, int idEmpleado) {
        this.id = id;
        this.fecha = fecha;
        this.metodo = metodo;
        this.total = total;
        this.idCliente = idCliente;
        this.idEmpleado = idEmpleado;
    }

    public Venta() {
    }

    @Override
    public boolean insertar() {
        String sql = "INSERT INTO Venta(fecha, total, metodoPago, Cliente_idCliente, Empleado_idEmpleado) values(?,?,?,?,?)";
        try (
                Connection con = getCon(); PreparedStatement stm = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            stm.setString(1, this.fecha);
            stm.setDouble(2, this.total);
            stm.setString(3, this.metodo);
            stm.setInt(4, this.idCliente);
            stm.setInt(5, this.idEmpleado);
            stm.executeUpdate();
            try (ResultSet generatedKeys = stm.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    lastId = generatedKeys.getLong(1);
                    System.out.println("ID de Nueva Fila Insertada: " + lastId);
                } else {
                    throw new SQLException("Inserting row failed, no ID obtained.");
                }
            }
            return true;
        } catch (SQLException ex) {
            Logger.getLogger(Venta.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
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

    public int getId() {
        return id;
    }

    public String getFecha() {
        return fecha;
    }

    public String getMetodo() {
        return metodo;
    }

    public int getIdCliente() {
        return idCliente;
    }

    public int getIdEmpleado() {
        return idEmpleado;
    }

    public void setId(int id) {
        this.id = id;
    }

    public long getLastId() {
        return this.lastId;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public void setMetodo(String metodo) {
        this.metodo = metodo;
    }

    public void setIdCliente(int idCliente) {
        this.idCliente = idCliente;
    }

    public void setIdEmpleado(int idEmpleado) {
        this.idEmpleado = idEmpleado;
    }

    public void setTotal(Double total) {
        this.total = total;
    }
}
