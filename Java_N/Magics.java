public class Magics {
    public static void main(String[] args) {
        int i = 0, j = 0, m = 0, n = 5;
        j = (n + 1) / 2 - 1;
        int[][] a = new int[n][n];
        a[i][j] = ++m;
        while (m < n * n) {
            i--;
            j++;
            if (m % n == 0 && m > 1) {
                i += 2;
                j -= 1;
            }
            if (i < 0)
                i += n;
            if (j > n - 1)
                j -= n;
            a[i][j] = ++m;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                System.out.print(a[i][j] + "\t");
            System.out.println();
        }
    }
}
