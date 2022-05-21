class Box {
    Box() {
        System.out.println("box init");
        System.out.println("box volume=" + l * w * h);
    }

    public int l = 5, w = 5, h = 5, p = 10;
}

public class BoxWeight extends Box {
    BoxWeight() {
        weight = l * w * h * p;
        System.out.println("box weight=" + weight);
    }

    public int weight;

    public static void main(String[] args) {
        new BoxWeight();
    }
}
