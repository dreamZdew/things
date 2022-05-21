class A {
    public void method1() {
        System.out.println("call A method1");
    }

    public void method2() {
        method1();
    }
}

class B extends A {
    public void method3() {
        System.out.println("call B method3");
    }
}

public class C {
    public static void main(String[] args) {
        B b = new B();
        A a = b;// 向上转型
        callA(a);
        callA(new B());

    }

    public static void callA(A a) {
        B b = (B) a;// 向下转型
        b.method1();
        b.method2();
        b.method3();
    }
}
