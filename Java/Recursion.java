public class Recursion {
static public int plus(int n) {
        if (n == 0)
            return 0;
        return plus(n - 1) + n;
    }
    public static void main(String[] args) {
        System.out.println(plus(100));
    }
}
