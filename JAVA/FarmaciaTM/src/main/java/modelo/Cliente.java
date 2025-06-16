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
import java.util.Collections;
import java.util.Comparator;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author thotstin
 */

public class Cliente extends Conection implements Sentencias {

    private int id = -1;
    private String nombre;
    private String apellido;

    @Override
    public boolean insertar() {
        //String sql = "insert into cliente values (?, ?, ?)"; queremos usar el autoincrement
        String sql = "insert into Cliente (nombre, apellido) values (?, ?);";
        Connection con = getCon();
        try {
            PreparedStatement stm = con.prepareStatement(sql);
            //stm.setInt(1, this.id);
            stm.setString(1, this.nombre);
            stm.setString(2, this.apellido);
            stm.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }

        return true;
    }

    @Override
    public boolean actualizar() {
        String sql = "UPDATE Cliente SET nombre=\"" + nombre + "\", apellido=\"" + apellido + "\" WHERE idCliente=" + id;
        Connection con = getCon();
        try {
            PreparedStatement stm = con.prepareStatement(sql);
//            stm.setInt(1, this.id);
//            stm.setString(1, this.nombre);
            //stm.setString(2, this.apellido);
            stm.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        
        return true;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }
    
    @Override
    public ArrayList consulta() {
        ArrayList<Cliente> clientes = new ArrayList();
        String sql = "select * from Cliente";
        Connection con = getCon();
        Statement stm;
        try {
            stm = con.createStatement();

            ResultSet resultado = stm.executeQuery(sql);
            while (resultado.next()) {
                int ID = resultado.getInt("idCliente");
                //int id = resultado.getInt("1"); tambien se puede poner '1' para acceder elemento por elemento
                // pero parece mejor poner los nombres de las columnas
                String NOMBRE = resultado.getString("nombre");
                String APELLIDO = resultado.getString("apellido");
                clientes.add(new Cliente(ID, NOMBRE, APELLIDO));
            }
        } catch (SQLException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }

        Collections.sort(clientes, new SortbyRoll());
        return clientes;
    }

    public Cliente(int id, String nombre, String apellido) {
        this.id = id;
        this.nombre = nombre;
        this.apellido = apellido;
    }

    public Cliente() {
    }

    @Override
    public boolean eliminar() {
        if (-1 == id) {
            return false;
        }
        
        String sql = "delete from Cliente where idCliente=" + id;
        Connection con = getCon();
        try {
            PreparedStatement stm = con.prepareStatement(sql);
            stm.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }

        return true;
    }
}

class SortbyRoll implements Comparator<Cliente> 
{    
  	// Compare by roll number in ascending order
    @Override
    public int compare(Cliente a, Cliente b) {
        return (a.getApellido() + a.getNombre()).compareTo(b.getApellido() + b.getNombre());
    }
}

