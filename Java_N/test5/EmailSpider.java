package test5;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class EmailSpider {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("C:\\file.txt"));
            String line = "";
            while ((line = br.readLine()) != null) {
                parse(line);

            }
            br.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void parse(String line) {
        Pattern p = Pattern.compile("[\\w[.]]+@[\\w[.]]+\\.[\\w]+");
        Matcher m = p.matcher(line);
        while (m.find())
            System.out.println(m.group());
    }
}
