import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static String isBalanced(String s) {
        final Map<String, String> parenMap = new HashMap<String, String>() {{
            put("]", "[");
            put(")", "(");
            put("}", "{");
        }};
        Stack<String> stack = new Stack<String>();

        for (String ch : s.split("")) {
            if (parenMap.containsKey(ch)) {
                if (stack.isEmpty() || !stack.peek().equals(parenMap.get(ch))) return "NO";
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        
        return stack.isEmpty() ? "YES" : "NO";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String s = scanner.nextLine();

            String result = isBalanced(s);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}

