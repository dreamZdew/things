public class PluMi {
    public static void main(String[] args) {
        int  i2 = 10;
        int i = (i2++);
        System.out.println("i=" + i);
        System.out.println("i2=" + i2);
        i = (++i2);
        System.out.println("i=" + i);
        System.out.println("i2=" + i2);
    }
}