public class TestOverLoad {
    void max(int a, int b) {
        System.out.print("int: ");
        System.out.println(a > b ? a : b);
    }
    void max(short a, short b) {
        System.out.print("short: ");
        System.out.println(a > b ? a : b);
    }
    void max(double a, double b) {
        System.out.print("double: ");
        System.out.println(a > b ? a : b);
    }
    public static void main(String[] args) {
        TestOverLoad t=new TestOverLoad();
        t.max(300,400);
        short a=100,b=110;
        t.max(a, b);
        t.max(300.5, 400.5);
    }

}
