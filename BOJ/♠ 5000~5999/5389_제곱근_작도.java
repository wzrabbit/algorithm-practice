import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for (int o = 0; o < t; o++) {
            int n = Integer.parseInt(br.readLine());
            boolean isSuccess = false;
            int maxA = 2100000000;
            int maxB = 2100000000;
            int a, b;

            for (int i = 1; i <= Math.floor(Math.sqrt(n)) + 1; i++) {
                int j = n / i;

                if (n % i == 0 && (j - i) % 2 == 0) {
                    isSuccess = true;
                    a = (j - i) / 2;
                    b = (j + i) / 2;

                    if (a < maxA) {
                        maxA = a;
                        maxB = b;
                    }
                }
            }

            if (isSuccess)
                bw.write(Integer.toString(maxA) + " " + Integer.toString(maxB) + "\n");
            else
                bw.write("IMPOSSIBLE\n");
        }

        bw.flush();
        bw.close();
    }
}