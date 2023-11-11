import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int[] arr = new int[N];
        
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        
        Arrays.sort(arr);
        
        int worst_need = 1;
        int cur_need = 1;
        
        for (int i = 1; i < N; i++) {
            if (arr[i] == arr[i - 1]) {
                cur_need += 1;
            } else {
                cur_need = 1;
            }
            
            worst_need = Math.max(worst_need, cur_need);
        }
        
        System.out.println(worst_need);
    }
}