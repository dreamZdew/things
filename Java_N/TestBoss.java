class Boss {
    private static Boss boss = null;

    private Boss() {
    }

    public static Boss getInstance() {
        if (boss == null) {
            boss = new Boss();
        }
        return boss;
    }

    public void getName() {
        System.out.println("你是老板：马化腾");
    }
}

public class TestBoss {
    public static void main(String[] args) {
        System.out.println("创建老板1对象：");
        Boss boss1 = Boss.getInstance();
        boss1.getName();
        System.err.println("创建老板2对象：");
        Boss boss2 = Boss.getInstance();
        boss2.getName();
        System.err.println("创建老板3对象：");
        Boss boss3 = Boss.getInstance();
        boss3.getName();
    }
}
