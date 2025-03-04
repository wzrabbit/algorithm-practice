import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < T; i++) {
            String[] carNo = sc.nextLine().split("-");
            String first = carNo[0];
            int secondValue = Integer.parseInt(carNo[1]);

            int firstValue = (Character.codePointAt(first, 0) - 65) * 676 +
                        (Character.codePointAt(first, 1) - 65) * 26 +
                        (Character.codePointAt(first, 2) - 65);

            if (Math.abs(firstValue - secondValue) <= 100) {
                System.out.println("nice");
            } else {
                System.out.println("not nice");
            }
        }
    }
}
