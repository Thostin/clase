/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package com.karaikacho.farmaciatm;

import Clases.VentaSingleton;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import modelo.Cliente;

/**
 * FXML Controller class
 *
 * @author thotstin
 */
public class BuscarClienteController implements Initializable {

    @FXML
    private TextField txtBuscar;
    @FXML
    private TableView<Cliente> tablaCliente;

    Cliente cliente = new Cliente();
    ObservableList<Cliente> registros;
    ObservableList<Cliente> registrosFiltrados; // Para búsqueda

    @FXML
    private TableColumn<Cliente, Integer> columnaId;
    @FXML
    private TableColumn<Cliente, String> columnaNombre;
    @FXML
    private TableColumn<Cliente, String> columnaApellido;

    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        mostrarDatos();
    }

    @FXML
    private void mostrarFila(MouseEvent event) {
        Cliente clienteSeleccionado = tablaCliente.getSelectionModel().getSelectedItem();
        VentaSingleton.getInstance().setIdCliente(clienteSeleccionado.getId());

        Stage stage = (Stage) ((javafx.scene.Node) event.getSource()).getScene().getWindow();
        stage.close();
    }

    private void mostrarDatos() {
        registros = FXCollections.observableArrayList(cliente.consulta());
        columnaId.setCellValueFactory(new PropertyValueFactory<>("id"));
        columnaNombre.setCellValueFactory(new PropertyValueFactory<>("nombre"));
        columnaApellido.setCellValueFactory(new PropertyValueFactory<>("apellido"));
        tablaCliente.setItems(registros);
        //throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @FXML
    private void buscar(KeyEvent event) {
        String busqueda = txtBuscar.getText();
        registrosFiltrados = FXCollections.observableArrayList();
        if (busqueda.isEmpty()) {
            tablaCliente.setItems(registros);
        } else {
            registrosFiltrados.clear();
            for (Cliente registro : registros) {
                if (registro.getNombre().toLowerCase().contains(busqueda.toLowerCase())
                        || registro.getApellido().toLowerCase().contains(busqueda.toLowerCase())) {
                    registrosFiltrados.add(registro);
                }
            }

            tablaCliente.setItems(registrosFiltrados);
        }
    }
}
