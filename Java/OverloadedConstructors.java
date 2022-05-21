class Teacher {
    Teacher(int i) {
        this("doctor");
        int year = i;
        System.out.println("teaches " + year + " year");

    }

    Teacher(String s) {
        String degree = s;
        System.out.println("degree: " + degree);
    }

    void teach() {
        System.out.println("teach well");
    }
}

public class OverloadedConstructors {
    public static void main(String[] args) {
        new Teacher(8).teach();
        ;
    }
}
