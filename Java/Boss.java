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
    public void getName(){
        System.out.println("你是老板：马化腾");
    }
}
