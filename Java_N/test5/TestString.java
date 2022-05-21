package test5;
import java.util.*;

public class TestString {
    public static void main(String[] args) {
        String data = "this is a string";
        StringTokenizer st = new StringTokenizer(data);
        int count = st.countTokens();
        System.out.println("原串是"+data);
        System.out.println("各个单词如下：");
        while(st.hasMoreTokens())
        {
            String s=st.nextToken();
            System.out.println(s);
        }
        System.out.println("单词总数："+count);
    }

}
