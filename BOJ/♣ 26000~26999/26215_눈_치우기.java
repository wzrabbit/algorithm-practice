import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        Integer[] snows = new Integer[N + 1];
        
        for (int i = 0; i < N; i++) {
            int cur = sc.nextInt();
            snows[i] = cur;
        }

        snows[N] = 0;

        int time = 0;
        
        Arrays.sort(snows, Collections.reverseOrder());
        
        while (snows[0] > 0 && time <= 1440) {
            snows[0] -= 1;
            snows[1] -= 1;
            
            time += 1;
            
            Arrays.sort(snows, Collections.reverseOrder());
        }
        
        if (time > 1440) {
            System.out.println(-1);
        } else {
            System.out.println(time);
        }
    }
}