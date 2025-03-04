import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String A = sc.nextLine();
        String B = sc.nextLine();

        if (A.equals("null")) {
            System.out.println("NullPointerException");
            System.out.println("NullPointerException");
            return;
        }

        if (B.equals("null")) {
            System.out.println("false");
            System.out.println("false");
            return;
        }

        if (A.equals(B)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }

        if (A.equalsIgnoreCase(B)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}
