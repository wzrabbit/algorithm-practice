import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        double max = 0;
        double current = 1;

        for (int i = 0; i < tc; i++) {
            double data = sc.nextDouble();
            if (current >= 1)
                current *= data;
            else
                current = data;
            if (current > max)
                max = current;
        }

        System.out.println(String.format("%.3f", max));
    }
}