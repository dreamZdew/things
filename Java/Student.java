public class Student {
    Student() {
        System.out.println("Student init");
    }

    Student(int i) {
        System.out.println("it's int! " + i);
    }

    Student(double d) {
        System.out.println("it's double! " + d);
    }

    public static void main(String[] args) {
        new Student();
        new Student(5);
        new Student(53.35);
    }
}
