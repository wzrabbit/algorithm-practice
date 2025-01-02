import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long total = 0;

        for (int i = 1; i <= N; i++) {
            br.readLine();
        }

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            total += Long.parseLong(st.nextToken());
        }

        double average = total / (double)N;

        System.out.printf("%.5f", average);
    }
}
