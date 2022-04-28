import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int num = Integer.parseInt(st.nextToken());
        int goal = Integer.parseInt(st.nextToken());
        int[] arr = new int[num];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        int l = 0;
        int r = 0;
        int current = arr[0];
        int answer = 0;
        while (r < num) {
            if (current == goal)
                answer++;

            if (current >= goal) {
                current -= arr[l];
                l++;
            }
        }
    }
}