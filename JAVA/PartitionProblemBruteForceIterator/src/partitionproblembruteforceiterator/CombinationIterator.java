package partitionproblembruteforceiterator;

public class CombinationIterator {

    private final int [] combinacion;
    private final int[] num;
    private final int size;
    private final int sum;
    private final int valormaximo = 1;
    private final int valorminimo = 0;

    public CombinationIterator(int[] num, int sum, int N) {
        this.size = N;
        this.combinacion = new int[size];
        this.num = num;
        this.sum = sum;
    }

    public boolean ultimaCombinacion() {
        for (int i = 0; i < combinacion.length; i++) {
            if (combinacion[i] == 0) {
                return false;
            }
        }
        return true;
    }

    public boolean siguienteCombinacion() {
        for (int i = 0; i < combinacion.length; i++) {
            if (combinacion[i] == valormaximo) {
                combinacion[i] = valorminimo;
            } else {
                combinacion[i] = combinacion[i] + 1;
                return true;
            }
        }
        return false;
    }
    
    public boolean searchedCombination(){
        int actualSum=0;
        for (int i = 0; i < num.length; i++) {
            if (combinacion[i] == 1){
                actualSum= actualSum + num[i];
            }    
        }
        return (actualSum == sum);
    }
}