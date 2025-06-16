/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package com.karaikacho.farmaciatm;

import Clases.Reporte;
import java.io.IOException;
import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextInputDialog;
import javafx.stage.Stage;
import net.sf.jasperreports.engine.JRException;

/**
 * FXML Controller class
 *
 * @author thotstin
 */
public class MenuPrincipalController implements Initializable {


  /**
   * Initializes the controller class.
   */
  @Override
  public void initialize(URL url, ResourceBundle rb) {
    // TODO
  }

  @FXML
  @SuppressWarnings("unused") // Called from FXML
  private void cliente(ActionEvent event) {
    abrirFXML("primary.fxml", "Formulario Cliente");
  }

  public void abrirFXML(String direccion, String titulo) {
    FXMLLoader cargador = new FXMLLoader(getClass().getResource(direccion));

    try {
      Parent root = cargador.load();
      Stage stage = new Stage();
      stage.setTitle(titulo);
      stage.setScene(new Scene(root));
      stage.show();
    } catch (IOException ex) {
      Logger.getLogger(MenuPrincipalController.class.getName()).log(Level.SEVERE, null, ex);
    }

  }

  @FXML
  @SuppressWarnings("unused") // Called from FXML
  private void informeCliente(ActionEvent event) throws JRException {
    Reporte r = new Reporte();
    String ubicacion = "/com/karaikacho/farmaciatm/reportes/Cliente.jrxml";
    String titulo = "Informe de Cliente";
    r.generarReporte(ubicacion, titulo);
  }

  @FXML
  @SuppressWarnings("unused") // Called from FXML
  private void reportarCliente(ActionEvent event) throws JRException {
    Reporte r = new Reporte();
    String ubicacion = "/com/karaikacho/farmaciatm/reportes/ClienteEspecifico.jrxml";
    String titulo = "Informe de Cliente";
    TextInputDialog dialogo = new TextInputDialog();
    dialogo.setTitle("Ingrese el id");
    dialogo.setHeaderText(null);
    dialogo.setContentText("Id: ");

    Optional<String> resultado = dialogo.showAndWait();
    if (resultado.isPresent()) {
      r.generarReporteArgumento(ubicacion, titulo, Integer.valueOf(resultado.get()));
    } else {
      System.out.println("Eso no es un numero");
    }
  }

  @FXML
  private void factura(ActionEvent event) {
    abrirFXML("factura.fxml", "Formulario de ventas");
  }
}
