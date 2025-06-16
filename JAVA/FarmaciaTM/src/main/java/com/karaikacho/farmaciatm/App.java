package com.karaikacho.farmaciatm;

import Clases.Conection;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import javafx.scene.control.Alert;

/**
 * JavaFX App
 */
public class App extends Application {

    private static Scene scene;

    @Override
    public void start(Stage stage) throws IOException {
        Conection conectar = new Conection();
        
        if(conectar.getCon()!=null){
            scene = new Scene(loadFXML("MenuPrincipal"), 640, 480);
            stage.setScene(scene);
            stage.show();
        }else{
            // System.out.println("Error al conectar");
            Alert alerta = new Alert(Alert.AlertType.ERROR);
            alerta.setTitle("Error de conexion");
            alerta.setHeaderText(null);
            alerta.setContentText("Por favor revise su conexion y vuelva a intentarlo");
            alerta.showAndWait();
        }
        
        /*
        scene = new Scene(loadFXML("primary"), 640, 480);
        stage.setScene(scene);
        stage.show();*/
    }

    
    static void setRoot(String fxml) throws IOException {
        scene.setRoot(loadFXML(fxml));
    }

    private static Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void main(String[] args) {
        launch();
    }

}