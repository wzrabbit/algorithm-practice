import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int set = Integer.parseInt(st.nextToken());
        Integer[] arr = new Integer[n - 1];
        int before;
        int answer = 0;

        st = new StringTokenizer(br.readLine());
        before = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n - 1; i++) {
            int current = Integer.parseInt(st.nextToken());
            arr[i] = current - before;
            answer += arr[i];
            before = current;
        }

        Arrays.sort(arr, Collections.reverseOrder());

        for (int i = 2; i <= set; i++)
            answer -= arr[i - 2];

        System.out.println(answer);
    }
}