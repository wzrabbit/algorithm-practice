import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(st.nextToken());
        long need = Long.parseLong(st.nextToken());
        long cur = 0;
        boolean[] arr = new boolean[N + 1];

        for (int i = 1; i <= N; i++)
            arr[i] = false;

        for (int i = 1; i <= N - 2; i++) {
            if (cur + N - 1 - i <= need) {
                cur += N - 1 - i;
                arr[i] = true;
            }
        }

        if (cur < need)
            bw.write("-1");
        else {
            for (int i = 1; i <= N - 2; i++) {
                if (arr[i] == false)
                    bw.write(Integer.toString(i) + ' ');
            }
            bw.write(Integer.toString(N - 1) + ' ');
            for (int i = N - 2; i >= 1; i--) {
                if (arr[i] == true)
                    bw.write(Integer.toString(i) + ' ');
            }
            bw.write(Integer.toString(N) + ' ');
        }

        bw.flush();
    }
}