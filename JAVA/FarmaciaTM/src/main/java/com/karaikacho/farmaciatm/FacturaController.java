/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package com.karaikacho.farmaciatm;

import Clases.VentaSingleton;
import java.io.IOException;
import java.net.URL;
import java.sql.ResultSet;
import java.time.LocalDate;
import java.util.Optional;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ComboBox;

import javafx.scene.control.DatePicker;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.Pane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import modelo.Cliente;
import modelo.DetalleVenta;
import modelo.Medicamento;
import modelo.Venta;

/**
 * FXML Controller class
 *
 * @author thotstin
 */
public class FacturaController implements Initializable {

    @FXML
    private Pane factura;
    @FXML
    private DatePicker fecha;
    @FXML
    private TextField txtCantidad;
    @FXML
    private TextField txtCliente;
    @FXML
    private TextField txtProducto;
    @FXML
    private Button btnBuscarCliente;
    @FXML
    private TextField txtFact;
    @FXML
    private ComboBox<String> cmbMetodo;
    @FXML
    private Button btnNuevo;
    @FXML
    private Button btnBuscarProducto;
    @FXML
    private TextField txtTotal;

    private int idCliente;
    private int idProducto;
    private double suma = 0;
    private double precio;
    Cliente cliente = new Cliente(); //un objeto de la clase Cliente para uso posterior
    Medicamento medicamento = new Medicamento();
    Venta v = new Venta();
    //DetalleVenta dv;
    ObservableList<Cliente> registrosClientes;
    ObservableList<Medicamento> registrosMedicamentos;
    ObservableList<DetalleVenta> registrosDetalles = FXCollections.observableArrayList();

    @FXML
    private Button btnAgregar;
    @FXML
    private Button btnGrabar;
    @FXML
    private Button btnCancelar;
    @FXML
    private Button btnImprimir;
    @FXML
    private TableColumn<DetalleVenta, Integer> colCodigo;
    @FXML
    private TableColumn<DetalleVenta, Integer> colPrecio;
    @FXML
    private TableColumn<DetalleVenta, Integer> colCantidad;
    @FXML
    private TableColumn<DetalleVenta, Integer> colSubTotal;
    @FXML
    private TableColumn<DetalleVenta, String> colDescripcion;
    @FXML
    private TableView<DetalleVenta> tablaDetalle;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        fecha.setEditable(false);
        fecha.setDisable(true);
        fecha.setValue(LocalDate.now());

        registrosClientes = FXCollections.observableArrayList(cliente.consulta());
        registrosMedicamentos = FXCollections.observableArrayList(medicamento.consulta());

        colCodigo.setCellValueFactory(new PropertyValueFactory<>("Medicamento_idMedicamento"));
        colDescripcion.setCellValueFactory(new PropertyValueFactory<>("descripcion"));
        colPrecio.setCellValueFactory(new PropertyValueFactory<>("precio"));
        colCantidad.setCellValueFactory(new PropertyValueFactory<>("cantidad"));
        colSubTotal.setCellValueFactory(new PropertyValueFactory<>("subTotal"));
    }

    @FXML
    private void nuevo(ActionEvent event) {
        txtFact.setDisable(false);
        txtFact.requestFocus();
        btnBuscarCliente.setDisable(false);
        fecha.setDisable(false);
        btnNuevo.setDisable(true);
        //metodo de pago

        cmbMetodo.setPromptText("Seleccione Método");

        cmbMetodo.getItems().add("Efectivo");
        cmbMetodo.getItems().add("Tarjeta de Débito");
        cmbMetodo.getItems().add("Tarjeta de Crédito");

        //fecha actual
        fecha.setValue(LocalDate.now());
    }

    @FXML
    private void grabar(ActionEvent event) {
        //mostramos un mensaje para grabar
        Alert alerta = new Alert(Alert.AlertType.CONFIRMATION);
        alerta.setTitle("El sistema comunica;");
        alerta.setHeaderText(null);
        alerta.setContentText("¿Desea grabar la venta?");
        Optional<ButtonType> opcion = alerta.showAndWait();
        if (opcion.get() == ButtonType.OK) {//si presiona ok
            //enviamos los datos al objeto previamente creado de forma global
            //v.setId(Integer.parseInt(txtFact.getText()));
            v.setFecha(fecha.getValue().toString());
            v.setTotal(suma);
            v.setMetodo(cmbMetodo.getSelectionModel().getSelectedItem());
            v.setIdCliente(idCliente);
            v.setIdEmpleado(1);// debe existir en la base  de dato
            if (v.insertar()) {//llama al metodo insertar de venta
                //recorremos la lista detalle venta y obtenemos los valores y los enviamos al modelo detalle
                for (DetalleVenta object : registrosDetalles) {
                    object.setVenta_idVenta((int) v.getLastId());
                    alerta.setContentText("" + object.getMedicamento_idMedicamento());
                    alerta.showAndWait();
                    object.insertar();
                    /*dv.setVenta_idVenta(Integer.parseInt(txtFact.getText()));
                        dv.setMedicamento_idMedicamento(object.getMedicamento());
                        dv.setCantidad(object.getCantidad());
                        dv.insertar();   //llama al metodo insertar de detalle venta*/
                }
                //mensaje de confirmacion
                Alert alertaIn = new Alert(Alert.AlertType.INFORMATION);
                alertaIn.setTitle("El sistema comunica:");
                alertaIn.setHeaderText(null);
                alertaIn.setContentText("Insertado correctamente en la base de datos");
                alertaIn.show();
                //habilitar Imprimir
                btnImprimir.setDisable(false);
                //mensaje de error
            } else {
                Alert alertaIn = new Alert(Alert.AlertType.ERROR);
                alertaIn.setTitle("El sistema comunica:");
                alertaIn.setHeaderText(null);
                alertaIn.setContentText("Error. Registro no insertado.");
                alertaIn.show();
            }
        }
        cancelar(event);//ejecuta el boton cancelar
    }

    @FXML
    private void cancelar(ActionEvent event) {
        //limpiar los campos
        TextField[] fields = {txtFact, txtCantidad, txtCliente, txtProducto, txtTotal};
        for (TextField field : fields) {
            field.clear();
            field.setDisable(true);
        }

        cmbMetodo.getItems().clear();
        cmbMetodo.setDisable(true);
        fecha.setDisable(true);
        btnGrabar.setDisable(true);
        btnNuevo.setDisable(false);
        btnBuscarCliente.setDisable(true);
        btnBuscarProducto.setDisable(true);
        btnAgregar.setDisable(true);
        btnImprimir.setDisable(true);
    }

    @FXML
    private void imprimir(ActionEvent event) {
    }

    public void abrirFXMLModal(String direccion, String titulo) {
        FXMLLoader loader = new FXMLLoader(getClass().getResource(direccion));

        try {
            Parent root = loader.load();
            Stage stage = new Stage();
            stage.setScene(new Scene(root));
            stage.initModality(Modality.APPLICATION_MODAL);
            stage.setTitle(titulo);
            stage.setResizable(false); // Evita que la ventana sea redimensionable
            stage.setMinWidth(300); // Establece un ancho mínimo
            stage.setMinHeight(200); // Establece una altura mínima
            stage.showAndWait();
        } catch (IOException ex) {
            Logger.getLogger(FacturaController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @FXML
    private void buscarCliente(ActionEvent event) {
        abrirFXMLModal("buscarCliente.fxml", "Buscar Cliente");
        idCliente = VentaSingleton.getInstance().getIdCliente();

        for (Cliente c : registrosClientes) {
            if (c.getId() == idCliente) {
                txtCliente.setText(c.getNombre() + " " + c.getApellido());
                return;
            }
        }

        btnBuscarProducto.setDisable(false);
    }

    @FXML
    private void buscarProducto(ActionEvent event) {
        abrirFXMLModal("buscarProducto.fxml", "Buscar Producto");
        int codProd = VentaSingleton.getInstance().getIdProducto();

        for (Medicamento object : registrosMedicamentos) {
            if (object.getId() == codProd) {
                txtProducto.setText(object.getNombre());
                precio = object.getPrecio();
                idProducto = object.getId();
                Alert alerta = new Alert(Alert.AlertType.CONFIRMATION);
                alerta.setContentText("" + idProducto);
                alerta.showAndWait();
            }
        }
        txtCantidad.setDisable(false);
        btnAgregar.setDisable(false);
    }

    @FXML
    private void agregarFila(ActionEvent event) {
        if (!txtCantidad.getText().isEmpty()) {
            double subtotal = precio * Integer.parseInt(txtCantidad.getText());
            suma = suma + subtotal;
            DetalleVenta dtv = new DetalleVenta(idProducto, txtProducto.getText(), precio, Integer.parseInt(txtCantidad.getText()), subtotal);
            registrosDetalles.add(dtv);
            tablaDetalle.setItems(registrosDetalles);
            txtTotal.setText(String.valueOf(suma));
            txtProducto.clear();
            txtCantidad.clear();
            txtCantidad.setDisable(true);
            btnGrabar.setDisable(false);
        } else {
            //mensaje correspondiente
            System.out.println("no debe quedar vacio");
        }
    }

}
