import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
    
        final int T = Integer.parseInt(br.readLine());
        
        for (int t = 1; t <= T; t++) {
            final int[] numbers = new int[3];
            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 3; i++) {
                numbers[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(numbers);

            bw.write("Case #" + t + ": ");

            if (numbers[0] * numbers[0] + numbers[1] * numbers[1] == numbers[2] * numbers[2]) {
                bw.write("YES\n");
            } else {
                bw.write("NO\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
