public class GetPrime {
    public static void main(String[] args) {
        int a, b, c;
        a = Integer.parseInt(args[0]);
        b = Integer.parseInt(args[1]);
        c = Integer.parseInt(args[2]);
        boolean flag;
        int m, p, count = 0;
        for (m = a; m <= b; m++) {
            flag = true;
            for (p = 2; p <= m / 2; p++)
                if (m % p == 0) {
                    flag = false;
                    break;
                }
            if (flag) {
                System.out.print(m + "\t");
                count++;
                if (count % c == 0)
                    System.out.println();
            }
        }
    }
}
