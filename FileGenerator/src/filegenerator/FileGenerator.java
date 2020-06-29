package filegenerator;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.concurrent.ThreadLocalRandom;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

public class FileGenerator {
    public static void main(String[] args) { 
        Options options = new Options();
        init(options);  
        HelpFormatter formatter = new HelpFormatter();
        CommandLineParser parser = new DefaultParser();
                  
        try {
            CommandLine cmd = parser.parse(options, args);
            if(cmd.hasOption("h")){
                formatter.printHelp("java -jar *.jar [-h][-n [digit > 0][-s][-min minVal][-max maxVal]]", options );
            }else if(cmd.hasOption("n")){
                int numVect = Integer.parseInt(cmd.getOptionValue("n"));
                
                if (numVect <= 0){
                    error("El número de elementos debe ser mayor que 0", formatter, options);
                }
                
                int min = (cmd.hasOption("min"))? Integer.parseInt(cmd.getOptionValue("min")) : 1;
                int max = (cmd.hasOption("max"))? Integer.parseInt(cmd.getOptionValue("max")) : 100;
                
                if(min > max) error("El rango superior debe ser mayor que el inferior", formatter, options);
                
                boolean sure = (cmd.hasOption("s"));
                createVectors(numVect, min, max, sure);
                
            }else{
                error("", formatter, options);
            }
        } catch (ParseException exp) {
            error("Fallo de parseo: " + exp.getMessage(), formatter, options);
        }       
    }  
    
    public static void init(Options options){    
        Option vectors = new Option("n", "elements", true, "Input the number of elements");
        Option sureEven = new Option("s", "sure", false, "Sure that the sum of the output is even");
        Option minimum = new Option("min", "minimum", true, "Input de minumum value taken");
        Option maximum = new Option("max", "maximum", true, "Input the maximum value taken");
        Option help = new Option("h", "help", false, "Display help message");
        
        options.addOption(vectors);
        options.addOption(sureEven);
        options.addOption(minimum);
        options.addOption(maximum);
        options.addOption(help);
    }
    
    public static void error(String error, HelpFormatter formatter, Options options){
        System.out.println(error);
        formatter.printHelp("java -jar *.jar [-h][-n [digit > 0][-s][-min minVal][-max maxVal]]", options );
        System.exit(1);
    }

    private static void createVectors(int nVect, int min, int max, boolean sure) {
        deleteFiles();
        String ruta = "../../fichVect.txt"; 
        int size = nVect;
        int sum = 0;
                            
            try {
                File fichero = new File(ruta);
                BufferedWriter bw;
                bw = new BufferedWriter(new FileWriter(fichero));
                bw.write(String.valueOf(size));            
                for (int line = 0; line < size; line++){                    
                    int n = ThreadLocalRandom.current().nextInt(min, max + 1);
                    sum += n;
                    if(line == size-1 && sure && sum%2 != 0){
                        if(n == max){
                            n--;
                        }else if(n == min){
                            n++;
                        }else{
                            n++;
                        }
                    }                  
                    bw.newLine();
                    bw.write(String.valueOf(n));
                }
                bw.close();
            }catch(IOException e){
                 System.out.println("Error IO:: " + e.getMessage());
            } 
    }
    
    private static void deleteFiles(){        
        File file = new File("../../");    
        File[] ficheros = file.listFiles();
        
        for (File fileAct : ficheros) {
            if(fileAct.isFile() && fileAct.getName().matches("fichVect.txt")){
                fileAct.delete();
                break;
            }
        }
    }
}
