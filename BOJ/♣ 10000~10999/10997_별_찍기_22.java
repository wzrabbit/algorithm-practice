import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int row = n * 4 - 1;
        int col = n * 4 - 3;
        String[][] board = new String[row][col];
        int[] dr = { -1, 0, 1, 0 };
        int[] dc = { 0, 1, 0, -1 };

        if (n == 1) {
            System.out.println("*");
            return;
        }

        for (int r = 0; r < row; r++)
            Arrays.fill(board[r], " ");

        int posR = n * 2;
        int posC = n * 2 - 2;
        int speed = 2;
        boolean nextStep = false;
        int dir = 0;

        while (posR != 0 || posC != 0) {
            for (int s = 0; s < speed; s++) {
                board[posR][posC] = "*";
                posR += dr[dir];
                posC += dc[dir];
            }

            dir = (dir + 1) % 4;

            if (nextStep) {
                speed += 2;
                nextStep = false;
            } else
                nextStep = true;
        }

        for (int c = 0; c < col; c++)
            board[0][c] = "*";

        for (int r = 0; r < row; r++)
            bw.write(String.join("", board[r]).trim() + "\n");

        bw.flush();
        br.close();
        bw.close();
    }
}