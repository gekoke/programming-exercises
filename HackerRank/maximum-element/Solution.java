import java.io.*;
import java.util.*;


public class Solution {

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        Stack<Integer> stack = new Stack<Integer>();

        final int n = inp.nextInt();
        
        for (int i = 0; i < n; i++) {
            switch (inp.nextInt()) {
                case 1:
                    if (stack.isEmpty()) {
                        stack.push(inp.nextInt());
                    } else {
                        // Keep pushing current highest value to the top of the stack
                        // for faster access later. Smaller values aren't used for anything
                        // anyway.
                        stack.push(Math.max(inp.nextInt(), stack.peek()));
                    }
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    System.out.println(stack.peek());
            }
        }
        inp.close();
    }
}
