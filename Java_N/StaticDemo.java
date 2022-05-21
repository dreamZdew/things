public class StaticDemo {
    static int m=10;
    static int n;
    static void method(int a){
        System.out.println("a="+a);
        System.out.println("m="+m);
        System.out.println("n="+n);
    }
    static{
        System.out.println("static block initialized");
        n=m*4;
    }
    public static void main(String[] args) {
        method(42);
    }
}
