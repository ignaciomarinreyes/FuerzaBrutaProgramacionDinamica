package partitionproblembruteforcerecursive;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public final class ReadFile {
    private final File fileVect;
    private String entero;
    private FileReader f;
    private BufferedReader b;
    
    public ReadFile(String fichS){        
        this.fileVect = new File(fichS);
    }
    
    public int[] readFolder(){       
        int i = 0;
         
        try {
            f = new FileReader(fileVect);
            b = new BufferedReader(f);
            int[] vector = new int[Integer.parseInt(b.readLine())];
               
            while((entero = b.readLine()) != null) {
                vector[i] = Integer.parseInt(entero);
                i++;
            }
            b.close();
            
            return vector; 
        } catch (FileNotFoundException ex) {
            System.out.println("Fichero no encontrado: " + ex.getMessage());
            System.exit(1);
        } catch (IOException ex){
            System.out.println("Fallo de IO: " + ex.getMessage());
            System.exit(1);
        }    
        return null;
    }
}
