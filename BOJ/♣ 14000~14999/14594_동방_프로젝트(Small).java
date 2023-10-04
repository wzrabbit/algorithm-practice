import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[] walls = new boolean[N];
        
        for (int i = 1; i <= M; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            
            for (int j = start; j < end; j++) {
                walls[j] = true;
            }
        }
        
        int roomCount = 1;
        
        for (int i = 1; i < N; i++) {
            if (!walls[i]) {
                roomCount += 1;
            }
        }
        
        System.out.println(roomCount);
    }
}