import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int dp[][] = new int[15][15];
        
        for (int c = 1; c <= 14; c++) {
            dp[0][c] = c;
        }
        
        for (int r = 1; r <= 14; r++) {
            for (int c = 1; c <= 14; c++) {
                int sum = 0;
                
                for (int i = 1; i <= c; i++) {
                    sum += dp[r - 1][i];
                }
                
                dp[r][c] = sum;
            }
        }
        
        int T = sc.nextInt();
        
        for (int t = 1; t <= T; t++) {
             int K = sc.nextInt();
            int N = sc.nextInt();
            
            System.out.println(dp[K][N]);
        }
        
    }
}