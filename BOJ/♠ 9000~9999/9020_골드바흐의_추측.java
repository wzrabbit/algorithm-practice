import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws Exception {
        boolean[] prime = new boolean[10001];
        Arrays.fill(prime, true);

        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= 100; i++) {
            if (prime[i] == true) {
                for (int j = i * 2; j <= 10000; j += i) {
                    prime[j] = false;
                }
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            int num = Integer.parseInt(br.readLine());
            int l = num / 2;
            int r = num / 2;

            while (prime[l] == false || prime[r] == false) {
                l--;
                r++;
            }

            System.out.printf("%d %d\n", l, r);
        }
    }
}