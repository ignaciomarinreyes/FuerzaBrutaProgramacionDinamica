package partitionproblemtabulation;

public class Tabulation {
    private final int[] num;
    private boolean[][] dp;
    private final int n;
    private int sum = 0;
    private boolean found;
    
    public Tabulation(int[] num){
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
        
        String set1 = "{";
        String set2 = "{";
        
        int x = n; 
        int currSum = sum; 
      
        while (x > 0 && currSum >= 0){
            
            if (dp[x-1][currSum]){ 
                x--;
                set1 += num[x] + ", ";                
            }else if (dp[x-1][currSum-num[x-1]]){ 
                x--; 
                currSum -= num[x]; 
                set2 += num[x] + ", "; 
            } 
        } 
        
        set1 = set1.substring(0, set1.length()-2) + '}';
        set2 = set2.substring(0, set2.length()-2) + '}';
        System.out.println("Set 1: " + set1);
        System.out.println("Set 2: " + set2);
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
        int sum = add();
        return (sum % 2 == 0);
    }
    
    public void canPartitionTab(){
        sum /= 2;
        dp = new boolean[n + 1][sum + 1];

        for(int i=0; i <= n; i++) dp[i][0] = true;

        for(int s=1; s <= sum ; s++) dp[0][s] = false;

        for(int i=1; i <= n; i++) {
            for(int s=1; s <= sum; s++) {
                
                if (s < num[i-1]) { 
                    dp[i][s] = dp[i-1][s];
                }else{
                    dp[i][s] = dp[i-1][s] || dp[i-1][s-num[i-1]];
                }
            }
        }
        found = dp[n][sum];
    }
}
