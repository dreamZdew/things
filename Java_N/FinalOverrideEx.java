class FinalMethod {
    final void f() {
        System.out.println("FinalMethod.f()");
    }

    void g() {
        System.out.println("FinalMethod.g()");
    }

    final void h() {
        System.out.println("FinalMethod.h()");
    }
}

class OverrideFinal extends FinalMethod {
    public void g() {
        System.out.println("OverrideFinal.g()");
    }
}

public class FinalOverrideEx {
    public static void main(String[] args) {
        OverrideFinal of = new OverrideFinal();
        of.f();
        of.g();
        of.h();
        FinalMethod wf = of;
        wf.f();
        wf.g();
        wf.h();
    }
}
