import java.util.Scanner;

public class FactorialComparison {
   
    public static long factorialRecursive(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorialRecursive(n - 1);
    }

   
    public static long factorialIterative(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 5; 
        
        
        long startTime = System.nanoTime();
        long recResult = factorialRecursive(n);
        long endTime = System.nanoTime();
        long recursiveTime = endTime - startTime;
        
       
        startTime = System.nanoTime();
        long iterResult = factorialIterative(n);
        endTime = System.nanoTime();
        long iterativeTime = endTime - startTime;
        
        System.out.println("Factorial of " + n + " (Recursive): " + recResult + ", Time taken: " + recursiveTime + " nanoseconds");
        System.out.println("Factorial of " + n + " (Iterative): " + iterResult + ", Time taken: " + iterativeTime + " nanoseconds");
    }
}
