package application;


import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicInteger;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;

public class TableViewExampleController {

    @FXML
    private TextField commandTextField;
    
    @FXML
    private TextArea textArea;
    
    @FXML
    private TableView<ObservableList<String>> tableView;
    
    public String execFile="C:\\Users\\Mateja\\Desktop\\ispis.txt";
    
    public void openPressed() throws IOException
    {
    	textArea.clear();
    	 String path = commandTextField.getText();
         commandTextField.clear();
         if(path.length()<3) {
         	textArea.setText("NEPRAVILNA PUTANJA");
         	return;
         }
         
         DataBase d=DataBase.readFile(path);
         
         
        d.writeFile("C:\\Users\\Mateja\\Desktop\\ispis.txt");  //upisi u glavni fajl
        
        textArea.setText("USPESNO OTVOREN FAJL");
        
        
         
    }
    
    public void exportPressed() throws IOException
    {
    	textArea.clear();
    	
    	String path = commandTextField.getText();
        commandTextField.clear();
        
        if(path.length()<3) {
        	textArea.setText("NEPRAVILNA PUTANJA");
        	return;
        }
        
        BufferedWriter bw = new BufferedWriter(new FileWriter(path));
        
        
    	DataBase d=DataBase.readFile(execFile);
    	String s1="CREATE DATABASE "+d.name;
    	bw.write(s1+"\n");
    	
    	Vector<Table> tables=d.tables;
    	
    	for(int i=0;i<tables.size();i++)
    	{
    		String s="CREATE TABLE ";
    		Table t=tables.get(i);
    		s=s+t.tableName+" (";
    		
    		String ins="INSERT INTO TABLE "+t.tableName+ "( ";
    		Map<String, Vector<String>> m=t.table;
    		
    		StringBuilder sb = new StringBuilder();
    		//sb.append(s);
    		
    		
    		 AtomicInteger cnt = new AtomicInteger();
            
            m.forEach((key, value) -> {
                sb.append(key).append(", ");                
                cnt.set(value.size());
            });
            sb.setLength(sb.length() - 2);
            
            sb.append(")");
            bw.write(s+sb+"\n");
            
            String p;
            for(int j=0;j<cnt.intValue();j++)
            {
            	p=t.getIndex(j);
            	p=ins+sb.toString()+ " VALUES (" +p+")";
            	bw.write(p+"\n");
            }
            	 
            	
            
           
    	}
    	
    	bw.close();
    	
    	textArea.setText("USPESNO EKSPORTOVANO");
    	
    	
    	
    	
    }
    
    public void savePressed() throws IOException
    {
    	textArea.clear();
    	String path = commandTextField.getText();
        commandTextField.clear();
        
        if(path.length()<3) {
        	textArea.setText("NEPRAVILNA PUTANJA");
        	return;
        }
       	 
        
        DataBase d=DataBase.readFile("C:\\Users\\Mateja\\Desktop\\ispis.txt");//procitaj iz glavnog fajla
        
        d.writeFile(path);    //upisi u dati fajl
        
        textArea.setText("USPESNO SACUVANO");
    }

    public void initialize() {
    	
    	
        commandTextField.setOnKeyPressed(event -> {
        	
        	
            if (event.getCode() == KeyCode.ENTER) {
            	
            	textArea.clear();
            	
            	tableView.getItems().clear();
            	tableView.getColumns().clear();
            	
                String text = commandTextField.getText();
                commandTextField.clear();
                Wrapper w = new Wrapper();
                //System.out.println(w.exec(text));
                
                if (text.contains("SELECT")) {
                    String ppp = w.exec(text);
                    Table t = Table.fromString(ppp);
                    System.out.println(t);
                    
                    Map<String, Vector<String>> map = t.table;

                    map.forEach((key, value) -> {
                        TableColumn<ObservableList<String>, String> tc1 = new TableColumn<>(key);
                        
                        // Provera da li je kolona već dodata
                        if (!tableView.getColumns().contains(tc1)) {
                            tableView.getColumns().add(tc1);
                        }
                        
                        ObservableList<String> data1 = FXCollections.observableArrayList(value);
                        
                        tc1.setCellValueFactory(param -> {
                            int index = tableView.getColumns().indexOf(tc1);
                            if (param.getValue().size() > index) {
                                return new SimpleStringProperty(param.getValue().get(index));
                            } else {
                                return new SimpleStringProperty("");
                            }
                        });
                        
                        tc1.setCellFactory(col -> new TableCell<ObservableList<String>, String>() {
                            @Override
                            protected void updateItem(String item, boolean empty) {
                                super.updateItem(item, empty);
                                if (item != null) {
                                    setText(item);
                                } else {
                                    setText("");
                                }
                            }
                        });

                        // Priprema redova ako nisu pripremljeni
                        if (tableView.getItems().isEmpty()) {
                            for (int i = 0; i < data1.size(); i++) {
                                tableView.getItems().add(FXCollections.observableArrayList());
                            }
                        }

                        // Popunjavanje odgovarajuće kolone
                        for (int i = 0; i < data1.size(); i++) {
                            ObservableList<String> row = tableView.getItems().get(i);
                            while (row.size() <= tableView.getColumns().indexOf(tc1)) {
                                row.add("");
                            }
                            row.set(tableView.getColumns().indexOf(tc1), data1.get(i));
                        }
                    });
                }
                
                else 
                {
                	textArea.setText(w.exec(text));

                }
                
                
            }
        });
    }
}
