package partitionproblembacktrackingiterator;

public class BackTrackingIt {
    private final int[] num;
    private final int n;
    private int sum = 0;
    private boolean found;
    
    public BackTrackingIt(int[] num){
        this.num = num;
        this.n = num.length;        
    }
    
    public void printVector(){
        System.out.print("| ");
        for (int i = 0; i < n; i++) { 
            System.out.print(num[i] + " | "); 
        } 
    } 
    
    private void getResult(){
        System.out.println("Results: " + sum);
    }
    
    public void printResult(){
        if(found){
            System.out.println("\nVector can be partitioned");       
            getResult();
        }else{
            System.out.println("\nVector can not be partitioned");
        }
    }
    
    public void printTime(long timeMillis, long timeNano, String scale){
        System.out.print("For " + n + " elements -> " + "Taken time: ");
        float print = (float) ((timeMillis == 0)? timeNano/1e9d : timeMillis/1e3d);
        if(scale == null){            
            System.out.printf("%.8f s.\n", print);
        }else{
            switch (scale) {
                case "ns": System.out.println(timeNano + " " + scale + '.');
                break;
                case "ms": System.out.println(timeMillis + " " + scale + '.');
                break;
                default: System.out.printf("%.8f s.\n", print);
                break;
            }  
        }
    }
    
    private int add(){
        for (int i = 0; i < n; i++) sum += num[i];
        return sum;
    }
    
    public boolean canPartition() {
        int su = add();
        return (su % 2 == 0);
    }
    
    public void canPartitionIterator(){
        sum /= 2;
        IteratorCombinations it = new IteratorCombinations(num, sum);
        while (! it.lastCombination() && it.nextCombination()){
            if (it.searchedCombination()) found = true;
        }
    }
}
