package partitionproblemmemoization;

import java.io.File;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

public final class ParserArgs {
    private final String[] args;
    private final Options options;
    private final HelpFormatter formatter;
    private final CommandLineParser parser;
    private String scale;  
    private String message;
    private final String errorMessage = "java -jar *.jar [-h][-f PathDir [-di][-do][-dt [s|ms|ns]]]";
    
    public ParserArgs(String[] args){
        this.args = args;
        this.options = new Options();
        this.formatter = new HelpFormatter();
        this.parser = new DefaultParser();
        init();
    }
    
    private void init(){
        message = "\n\nPartition problem is to determine whether a given set"
                 +"\ncan be partitioned into two subsets such that the sum"
                 +"\nof elements in both subsets is same.\n"
                 +"For further information, use the option '-h'.\n\n";
        Option help = new Option("h", "help", false, "Display help usage");
        Option printIn = new Option("di", "input", false, "Display input data");
        Option printOut = new Option("do", "output", false, "Display ouput data");
        Option printTime = Option.builder("dt")
                          .longOpt("time")
                          .hasArg()
                          .optionalArg(true)
                          .desc("Display taken time in seconds or (arg [ms | ns])")
                          .build();
        Option folder = Option.builder("f")
                       .longOpt("file")
                       .hasArg()
                       .desc("Read elements from a file")
                       .build();
        
        options.addOption(help);
        options.addOption(printIn);
        options.addOption(printOut);
        options.addOption(printTime);
        options.addOption(folder);
    }
    
    public void parserArg(){          
        try {
            CommandLine cmd = parser.parse(options, args);
            
            if(cmd.hasOption("h")){
                formatter.printHelp(errorMessage + message, options );
            }else if(cmd.hasOption("f")){
                String fich = cmd.getOptionValue("f");
                fileOption(fich, cmd);
            }else{
                error("");
            }
            
        } catch (ParseException exp) {
            error("Fallo de parseo: " + exp.getMessage());           
        }
    }
    
    private void fileOption(String fich, CommandLine cmd){
        if (fich != null && new File(fich).exists() && new File(fich).isFile()){
            ReadFile fichero = new ReadFile(fich);
            int[] vector = fichero.readFolder();
                        
            Memoization tab = new Memoization(vector); 
                
            if (cmd.hasOption("di")){
                System.out.println("Vector is : "); 
                tab.printVector();
                System.out.println();
            } 
            
            if (!tab.canPartition()){
                System.out.print("Sum of the elements is odd..");
                System.exit(1);
            }
            
            long startTN = System.nanoTime();
            long startTM = System.currentTimeMillis();
            tab.canPartitionRecursiveAux();
            long endTM = System.currentTimeMillis();
            long endTN = System.nanoTime();
                
            if (cmd.hasOption("do")){
                tab.printResult();             
            }
            
            if (cmd.hasOption("dt")){
                long timeMillis = (endTM - startTM);
                long timeNano = (endTN - startTN);
                scale = cmd.getOptionValue("dt");
                tab.printTime(timeMillis, timeNano, scale);
            }
        }else{
            error("");
        }                 
    }  
    
    private void error(String error){
        System.out.println(error);
        formatter.printHelp(errorMessage+message, options );
        System.exit(1);
    }
}
