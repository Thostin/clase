package com.karaikacho.farmaciatm;

import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import modelo.Cliente;

public class PrimaryController implements Initializable {

    @FXML
    private Button btnCancelar;

    @FXML
    private Button btnEliminar;

    @FXML
    private Button btnGuardar;

    @FXML
    private Button btnModificar;

    @FXML
    private Button btnNuevo;

    Cliente cliente = new Cliente(); //un objeto de la clase Cliente para uso posterior
    ObservableList<Cliente> registros;
    ObservableList<Cliente> registrosFiltrados; // Para búsqueda

    @FXML
    private TableColumn<Cliente, String> columnaApellido;

    @FXML
    private TableColumn<Cliente, Integer> columnaId;

    @FXML
    private TableColumn<Cliente, String> columnaNombre;

    @FXML
    private TableView<Cliente> tablaCliente;

    @FXML
    private TextField txtApellido;

    @FXML
    private TextField txtBuscar;

    @FXML
    private TextField txtCodigo;

    @FXML
    private TextField txtNombre;
    @FXML
    private Button btnActualizar;

    private void switchToSecondary() throws IOException {
        App.setRoot("secondary");
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        mostrarDatos();
        // throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @FXML
    void nuevo(ActionEvent event) {
        txtCodigo.setDisable(false);
        txtNombre.setDisable(false);
        txtApellido.setDisable(false);
        btnGuardar.setDisable(false);
        btnEliminar.setDisable(false);
        // btnNuevo.setDisable(false);
        btnCancelar.setDisable(false);
        btnModificar.setDisable(false);
    }

    @FXML
    private void cancelar(ActionEvent event) {
        txtCodigo.setDisable(true);
        txtNombre.setDisable(true);
        txtApellido.setDisable(true);

        txtCodigo.setText("");
        txtNombre.setText("");
        txtApellido.setText("");
        btnGuardar.setDisable(true);
        // btnNuevo.setDisable(true);
        btnCancelar.setDisable(true);
    }

    @FXML
    private void guardar(ActionEvent event) {
        //int cod = Integer.parseInt(txtCodigo.getText());
        String nombre = txtNombre.getText();
        String apellido = txtApellido.getText();

        // cliente.setId(cod);
        cliente.setNombre(nombre);
        cliente.setApellido(apellido);

        Alert alerta = new Alert(Alert.AlertType.INFORMATION);
        alerta.setTitle("El sistema comunica: ");
        alerta.setHeaderText("");

        if (cliente.insertar()) {
            alerta.setContentText("Datos insertados correctamente");
            alerta.show();
        } else {
            alerta.setContentText("Hubo un error al insertar los datos");
            alerta.show();
        }
        actualizarDatos();
        txtCodigo.setText("");
        txtNombre.setText("");
        txtApellido.setText("");
    }

    @FXML
    private void actualizarDatos() {
        registros = FXCollections.observableArrayList(cliente.consulta());
        tablaCliente.setItems(registros);
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

    //Para guardar si modificar es para iniciar modificacion
    //o para actualizar los datos 
    private boolean isGuardado;

    // Para guardar el objeto Cliente que se dese modificar
    private Cliente clienteSeleccionado = null;

    @FXML
    private void modificar(ActionEvent event) {
        if (isGuardado) {
            clienteSeleccionado.setNombre(txtNombre.getText());
            clienteSeleccionado.setApellido(txtApellido.getText());

            txtNombre.setText("");
            txtApellido.setText("");
            txtNombre.setDisable(true);
            txtApellido.setDisable(true);

            isGuardado = false;
            btnModificar.setStyle("");
            Alert alerta = new Alert(Alert.AlertType.INFORMATION);
            alerta.setTitle("El sistema comunica: ");
            alerta.setHeaderText("");

            if (clienteSeleccionado.actualizar()) {
                alerta.setContentText("Datos modificados correctamente");

            } else {
                alerta.setContentText("Hubo un error al modificar los datos");
            }

            alerta.show();
        } else {
            clienteSeleccionado = tablaCliente.getSelectionModel().getSelectedItem();
            if (null == clienteSeleccionado) {
                return;
            }

            txtNombre.setText(clienteSeleccionado.getNombre());
            txtApellido.setText(clienteSeleccionado.getApellido());

            isGuardado = true;
            btnModificar.setStyle("-fx-background-color: #ff0000");
        }
    }

    @FXML
    private void eliminar(ActionEvent event) {
        Cliente clienteSeleccionadoEliminar = tablaCliente.getSelectionModel().getSelectedItem();
        if (null != clienteSeleccionadoEliminar) {
            Alert confirmar = new Alert(Alert.AlertType.CONFIRMATION);
            confirmar.setTitle("Aviso de borrado");
            confirmar.setHeaderText("");
            confirmar.setContentText("Estas seguro de eliminar a '" + clienteSeleccionadoEliminar.getNombre() + "' " + "'" + clienteSeleccionadoEliminar.getApellido() + "'?");

            if (confirmar.showAndWait().get() == ButtonType.OK) {

                Alert alerta = new Alert(Alert.AlertType.INFORMATION);
                alerta.setTitle("El sistema comunica: ");
                alerta.setHeaderText("");

                if (clienteSeleccionadoEliminar.eliminar()) {
                    alerta.setContentText("'" + clienteSeleccionadoEliminar.getNombre() + "' " + "'" + clienteSeleccionadoEliminar.getApellido() + "' fue eliminado de la base de datos satisfactoriamente");
                } else {
                    alerta.setContentText("'" + clienteSeleccionadoEliminar.getNombre() + "' " + "'" + clienteSeleccionadoEliminar.getApellido() + "' no pudo ser eliminado de la base de datos");
                }

                actualizarDatos();
                alerta.show();
            }
        }
    }

    @FXML
    private void selected(MouseEvent event) {

    }
}
