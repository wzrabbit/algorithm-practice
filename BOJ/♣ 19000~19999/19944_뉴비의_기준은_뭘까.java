import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        if (M <= 2)
            System.out.print("NEWBIE!");
        else if (M <= N)
            System.out.print("OLDBIE!");
        else
            System.out.print("TLE!");
    }
}
