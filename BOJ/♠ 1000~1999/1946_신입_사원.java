import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        final int INF = 1000000;
        
        int T = Integer.parseInt(br.readLine());
        
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            int participants[] = new int[N + 1];
            
            for (int i = 1; i <= N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                
                int firstRank = Integer.parseInt(st.nextToken());
                int secondRank = Integer.parseInt(st.nextToken());
                
                participants[firstRank] = secondRank;
            }
            
            int acceptedCount = 0;
            int requiredRank = INF;
            
            for (int i = 1; i <= N; i++) {
                if (participants[i] < requiredRank) {
                    requiredRank = participants[i];
                    acceptedCount += 1;
                }
            }
            
            bw.write(String.valueOf(acceptedCount) + "\n");
        }
        
        bw.flush();
        bw.close();
    }
}