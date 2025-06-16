/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Clases;

import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;
import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperCompileManager;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.engine.JasperReport;
import net.sf.jasperreports.view.JasperViewer;

/**
 *
 * @author thotstin
 */
public class Reporte extends Conection {

    public void generarReporte(String ubicacion, String titulo) throws JRException {
        try {
            // NOTE: Aca estamos compilando el jasperreports en tiempo de compilacion
            // Obtener la ruta del archivo del formulario (JRXML)

            // Parámetros del informe
            InputStream streamReporte = getClass().getResourceAsStream(ubicacion);
            if (null == streamReporte) {
                throw new IllegalArgumentException("No se encontro el archivo: " + ubicacion);
            }

            JasperReport reporte = JasperCompileManager.compileReport(streamReporte);
            Map<String, Object> parameters = new HashMap<>();
            // Agrega parámetros según sea necesario

            // Llenar el informe
            JasperPrint jasperPrint = JasperFillManager.fillReport(reporte, parameters, getCon());

            // Mostrar el informe en una nueva ventana
            JasperViewer viewer = new JasperViewer(jasperPrint, false);
            viewer.setTitle(titulo);
            viewer.setVisible(true);

        } catch (JRException ex) {
            Logger.getLogger(Reporte.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void generarReporteArgumento(String ubicacion, String titulo, Integer parametro) throws JRException {
        try {
            // NOTE: Aca estamos compilando el jasperreports en tiempo de compilacion
            // Obtener la ruta del archivo del formulario (JRXML)

            // Parámetros del informe
            InputStream streamReporte = getClass().getResourceAsStream(ubicacion);
            if (null == streamReporte) {
                throw new IllegalArgumentException("No se encontro el archivo: " + ubicacion);
            }

            JasperReport reporte = JasperCompileManager.compileReport(streamReporte);
            Map<String, Object> parameters = new HashMap<>();
            // Agrega parámetros según sea necesario
            parameters.put("Codigo", parametro);
            
            
            // Llenar el informe
            JasperPrint jasperPrint = JasperFillManager.fillReport(reporte, parameters, getCon());

            // Mostrar el informe en una nueva ventana
            JasperViewer viewer = new JasperViewer(jasperPrint, false);
            viewer.setTitle(titulo);
            viewer.setVisible(true);

        } catch (JRException ex) {
            Logger.getLogger(Reporte.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public Reporte() {
    }
}
