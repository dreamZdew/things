class Person {
    Person() {
        System.out.println("person init");
    }

    public void getinfo() {
        System.out.println("person getinfo");
    }
}

public class Employee extends Person {
    public void getinfo() {
        System.out.println("employee getinfo");
    }
    public static void main(String[] args) {
        Person p=new Person();
        Employee e=new Employee();
        p.getinfo();
        e.getinfo();
    }
}
