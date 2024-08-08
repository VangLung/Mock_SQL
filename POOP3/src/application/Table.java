package application;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

/**
 * The {@code Table} class represents a table structure with a name and a collection of columns and rows.
 * Each column has a unique key, and each row contains values corresponding to the columns.
 */
public class Table {

    /** A map representing the table where the key is the column name and the value is a vector of values for that column. */
    Map<String, Vector<String>> table;
    
    /** The name of the table. */
    String tableName;

    /**
     * Constructs a new {@code Table} with the specified name.
     *
     * @param t the name of the table
     */
    public Table(String t) {
        this.tableName = t;
        this.table = new HashMap<String, Vector<String>>();
    }

    /**
     * Inserts the first row with the specified column name.
     *
     * @param s the name of the column to insert
     * @return 1 if the operation is successful
     */
    public int insertFirstRow(String s) {
        this.table.put(s, null);
        return 1;
    }

    /**
     * Returns a string representation of the table.
     * The string representation consists of the table name followed by the column names and their values.
     *
     * @return a string representation of the table
     */
    @Override
    public String toString() {
        String s = "";
        s = s + this.tableName + "\n";
        for (Map.Entry<String, Vector<String>> entry : table.entrySet()) {
            s = s + entry.getKey() + " ";
            Vector<String> values = entry.getValue();
            for (int i = 0; i < values.size(); i++)
                s = s + values.get(i) + " ";
            s += "\n";
        }
        return s;
    }

    /**
     * Creates a new {@code Table} from the specified string representation.
     * The string representation should have the table name followed by the column names and their values.
     *
     * @param str the string representation of the table
     * @return the newly created table
     */
    public static Table fromString(String str) {
        String[] lines = str.split("\n");
        Table table = new Table("Temp");
        for (int i = 0; i < lines.length; i++) {
            String[] parts = lines[i].trim().split("\\s+");
            String key = parts[0];
            Vector<String> values = new Vector<>();
            for (int j = 1; j < parts.length; j++) {
                values.add(parts[j]);
            }
            table.table.put(key, values);
        }
        return table;
    }

    /**
     * Adds a value to the specified column in the table.
     *
     * @param key the name of the column
     * @param value the value to add
     * @return 1 if the operation is successful
     */
    public int add(String key, String value) {
        Vector<String> v = table.get(key);
        if (v == null) {
            v = new Vector<>();
            table.put(key, v);
        }
        v.add(value);
        table.put(key, v);
        return 1;
    }

    /**
     * Creates a new {@code Table} based on the specified create table string.
     * The create table string should follow the format: "CREATE TABLE table_name (column1,column2,column3,...)"
     *
     * @param s the create table string
     * @return the newly created table
     * @throws Exception if the format of the create table string is incorrect
     */
    public static Table createTable(String s) throws Exception {
        Vector<String> v = split(s, "\\s+");
        if (v.size() != 4 || !v.get(0).equals("CREATE") || !v.get(1).equals("TABLE") || v.get(2).matches(".*\\d.*")) {
            throw new Exception("Invalid table creation format");
        }
        String tableName = v.get(2);
        String columnsString = v.get(3).replaceAll("[()]", "");
        Vector<String> columnNames = split(columnsString, ",");
        Table table = new Table(tableName);
        for (String columnName : columnNames) {
            table.insertFirstRow(columnName.trim());
        }
        return table;
    }
    
    public String getIndex(int ind)
    {
    	Map<String, Vector<String>> m=this.table;
		
		StringBuilder sb = new StringBuilder();
		
        
        m.forEach((key, value) -> {
            sb.append(value.get(ind)).append(",");
        });
        
        sb.setLength(sb.length() - 1);
        
        return sb.toString();
    	
    	
    }

    /**
     * Splits the specified string into a vector of substrings based on the given regular expression.
     *
     * @param s the string to split
     * @param regex the regular expression to use for splitting
     * @return a vector of substrings
     */
    private static Vector<String> split(String s, String regex) {
        String[] parts = s.split(regex);
        Vector<String> vector = new Vector<>();
        for (String part : parts) {
            vector.add(part);
        }
        return vector;
    }
}
