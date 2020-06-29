package partitionproblembacktrackingiterator;

public class IteratorCombinations {

    private final int [] combinacion;
    private final int [] num;
    private final int sum;
    private int totalVal;
    private final int valormaximo = 1;
    private final int valorminimo = 0;

    public IteratorCombinations(int[] num, int sum) {
        this.combinacion = new int[num.length];
        this.num = num;
        this.sum = sum;
    }

    public boolean lastCombination() {
        for (int i = 0; i < combinacion.length; i++) {
            if (combinacion[i] == 0) return false;
        }
        return true;
    }

    public boolean nextCombination() {
        for (int i = 0; i < combinacion.length; i++) {
            if (combinacion[i] == valormaximo) {
                combinacion[i] = valorminimo;
            } else {
                combinacion[i] += 1;
                if (isValidCombination()){
                    return true;
                } else {
                    combinacion[i] = valorminimo;
                }
            }
        }
        return false;
    }
    
    public boolean searchedCombination(){
        return (totalVal == sum);
    }

    private boolean isValidCombination() {
        return (totalValues() <= sum);
    }

    private int totalValues() {
        totalVal = 0;
        for (int i = 0; i < num.length; i++) {
            if (combinacion[i] == 1){
                totalVal += num[i];
            }
        }
        return totalVal;
    }
}