import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        final int n = inp.nextInt();

        Stack<Integer> stackA = new Stack<Integer>();
        Stack<Integer> stackB = new Stack<Integer>();
        
        for (int i = 0; i < n; i++) {
            switch (inp.nextInt()) {
                case 1:
                    stackA.push(inp.nextInt());
                    break;
                case 2:
                    // To dequeue, we need to access the first-in (bottom-most) element of the stack.
                    // If stackB is empty, pop all elements from stackA to stackB.
                    // This effectively reverses their order, and we can just pop from stackB
                    // until it runs out again to dequeue elements.
                    if (stackB.isEmpty()) {
                        while (!stackA.isEmpty()) {
                            stackB.push(stackA.pop());
                        }
                    }
                    stackB.pop();
                    break;
                case 3:
                    if (stackB.isEmpty()) {
                        while (!stackA.isEmpty()) {
                            stackB.push(stackA.pop());
                        }
                    }
                    System.out.println(stackB.peek());
            }
        }
        inp.close();
    }
}

