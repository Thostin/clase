module com.karaikacho.farmaciatm {
  requires javafx.controls;
  requires javafx.fxml;
  requires java.sql;
  requires java.base;
  requires jasperreports;
  // requires com.karaikacho.farmaciatm;
  //  requires com.karaikacho.farmaciatm;
    //requires com.karaikacho.farmaciatm;

  opens com.karaikacho.farmaciatm to javafx.fxml;

  exports com.karaikacho.farmaciatm;
  exports modelo;
  exports Clases;
}
