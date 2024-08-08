package application;

import java.io.FileWriter;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;



public class Main extends Application {
	static String execFile="C:\\Users\\Mateja\\Desktop\\ispis.txt";

    @Override
    public void start(Stage stage) {
        try {
            Parent root = FXMLLoader.load(getClass().getResource("/layout.FXML"));
            Scene scene = new Scene(root);
            stage.setTitle("SQL");
            stage.setScene(scene);
            stage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws Exception {
    	FileWriter fw = new FileWriter(execFile, false);
    	fw.close();
        launch(args);
    }
}
