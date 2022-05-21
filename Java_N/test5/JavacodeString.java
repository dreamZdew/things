package test5;

import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JavacodeString {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(
                    new FileReader("C:\\Users\\dream\\Desktop\\Code\\Java\\test5\\TestString.java"));
            String line = "";
            while ((line = br.readLine()) != null) {
                parse(line);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }

    public static void parse(String line) {
        Pattern p = Pattern.compile("[\\S[.]]+");
        Matcher m = p.matcher(line);
        while (m.find())
            System.out.println(m.group());

    }
}
