import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long answer = 0;
        long left, right;

        StringTokenizer st = new StringTokenizer(br.readLine());
        left = Long.parseLong(st.nextToken());
        right = Long.parseLong(st.nextToken());
        
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            long curLeft = Long.parseLong(st.nextToken());
            long curRight = Long.parseLong(st.nextToken());

            answer += left * curRight + right * curLeft;
            left += curLeft;
            right += curRight;
        }

        System.out.println(answer);
    }
}
