public class Reverse {
    public static void main(String[] args) {
        int[] a = { 15, 12, 9, 6, 3 };
        int t;
        for (int i = 0; i < a.length / 2; i++) {
            t = a[i];
            a[i] = a[a.length - i - 1];
            a[a.length - i - 1] = t;
        }
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
    }
}
