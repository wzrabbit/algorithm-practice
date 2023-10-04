import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int[] numbers = new int[N + 1];
        
        st = new StringTokenizer(br.readLine());
        
        for (int i = 1; i <= N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        
        int sum = 0;
        int max = 0;
        
        for (int i = 1; i <= N; i++) {
            sum += numbers[i];
            max = Math.max(max, numbers[i]);
        }
        
        System.out.println(sum - max);
    }
}