/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import Clases.Conection;

import Clases.Sentencias;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author thotstin
 */
public class Medicamento extends Conection implements Sentencias {
    private int id;
    private String nombre;
    private String descripcion;
    private double precio;
    private int stock;
    private String tipoVenta;
    private Date fechaCaducidad;
    private String formaDeAdministracion;
    private int idProveedor;
    private int idCategoria;
    
    
    @Override
    public boolean insertar() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    public Medicamento() {
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public void setFechaCaducidad(Date fechaCaducidad) {
        this.fechaCaducidad = fechaCaducidad;
    }

    public void setFormaDeAdministracion(String formaDeAdministracion) {
        this.formaDeAdministracion = formaDeAdministracion;
    }

    public void setIdProveedor(int idProveedor) {
        this.idProveedor = idProveedor;
    }

    public void setIdCategoria(int idCategoria) {
        this.idCategoria = idCategoria;
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

    public String getNombre() {
        return nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public double getPrecio() {
        return precio;
    }

    public int getStock() {
        return stock;
    }

    public Date getFechaCaducidad() {
        return fechaCaducidad;
    }

    public Medicamento(int id, String nombre, String descripcion, double precio, int stock, String tipoVenta, Date fechaCaducidad, String formaDeAdministracion, int idProveedor, int idCategoria) {
        this.id = id;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.precio = precio;
        this.stock = stock;
        this.tipoVenta=tipoVenta;
        this.fechaCaducidad = fechaCaducidad;
        this.formaDeAdministracion = formaDeAdministracion;
        this.idProveedor = idProveedor;
        this.idCategoria = idCategoria;
    }

    

    public String getFormaDeAdministracion() {
        return formaDeAdministracion;
    }

    public int getIdProveedor() {
        return idProveedor;
    }

    public int getIdCategoria() {
        return idCategoria;
    }
    
    @Override
    public ArrayList consulta() {
        ArrayList<Medicamento> medicamentos = new ArrayList<>();
        String sql = "SELECT * FROM Medicamento";
       
        try (Connection con = getCon();
             Statement stm = con.createStatement();
             ResultSet rs = stm.executeQuery(sql)) {
           
            while (rs.next()) {
                int ide = rs.getInt("idMedicamento");
                String nom = rs.getString("nombre");
                String desc= rs.getString("descripcion");
                double pre = rs.getDouble("precio");
                String tipoV = rs.getString("tipoVenta");
                String formaAd = rs.getString("formaDeAdministracion");
                int cant = rs.getInt("stock");
                Date fechaCad = rs.getDate("fechaCaducidad");
                int idProv = rs.getInt("Proveedor_idProveedor");
                int idCat = rs.getInt("CategoriaMedicamento_idCategoriaMedicamento");
               
                Medicamento medicamento = new Medicamento(ide, nom, desc, pre, cant, tipoV, fechaCad, formaAd, idProv, idCat);
                medicamentos.add(medicamento);
            }
           
        } catch (SQLException ex) {
            Logger.getLogger(Medicamento.class.getName()).log(Level.SEVERE, null, ex);
        }
       
        return medicamentos;
    }
    
}
