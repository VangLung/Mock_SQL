package application;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.Vector;

public class DataBase {
	 String name;
	 Vector<Table> tables;
	
	public DataBase(String s)
	{
		name=s;
		tables=new Vector<Table>();
	}
	
	Table checkTable(Table t)
	{
		for(int i=0;i<tables.size();i++)
		{
			if(tables.get(i).tableName==t.tableName)
				return tables.get(i);
		}
		
		return null;
	}
	
	int addTable(Table t)
	{
		tables.add(t);
		return 1;
	}
	
	String printTables()
	{
		String ret="";
		for(Table t : tables)
		{
			ret=ret+t.tableName+" ";
		}
		ret+="\n";
		return ret;
	}
	
	public void writeFile(String path) throws IOException
	{
		String filePath = path;  // zameni sa stvarnom putanjom fajla

		String s=this.name;
		
		BufferedWriter bw = new BufferedWriter(new FileWriter(filePath));
		
		bw.write(s);
        bw.newLine(); 
        bw.write("=================================");
        bw.newLine();
		
		for(int i=0;i<this.tables.size();i++)
		{
			s=this.tables.get(i).toString();
			
			bw.write(s);
             
            bw.write("=================================");
            bw.newLine();
			 
		}
		
		bw.close();
		
       
	}
	
	 public static DataBase readFile(String path) {
	        String line;
	        DataBase d = null;
	        Table t = null;
	        int cnt = 0;

	        try (BufferedReader inputFile = new BufferedReader(new FileReader(path))) {
	            // Read first line for database name
	            if ((line = inputFile.readLine()) != null) {
	                d = new DataBase(line);
	                
	                
	            }

	            // Read subsequent lines for table data
	            while ((line = inputFile.readLine()) != null) {
	            
	                if (!line.equals("=================================")) {
	                    if (cnt == 0) {
	                        t = new Table(line);
	                    } else {
	                        String[] v = line.split(" ");
	                        t.insertFirstRow(v[0]);
	                        
	                        for (int i = 1; i < v.length; i++) {
	                            t.add(v[0], v[i]);
	                        }
	                        
	                        
	                    }
	                    cnt++;
	                } else {
	                    cnt = 0;
	                    if (d != null && t != null) {
	                        d.addTable(t);
	                        System.out.println(t);
	                    }
	                }
	            }
	        } catch (IOException e) {
	            e.printStackTrace();
	        }

	        return d;
	    }
	 
	
	
	
	
}
