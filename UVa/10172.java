import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.LinkedBlockingDeque;

class Main {
    //.

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in); 
        final int set = inp.nextInt();
        
        // For every set of input, perform:
        for (int i = 0; i < set; i++) {
            final int stationCount = inp.nextInt();
            final int stackSize = inp.nextInt();
            final int queueSize = inp.nextInt();
            int minutes = -2;
            
            Deque<Integer> stack = new LinkedBlockingDeque<>(stackSize);
            List<Deque<Integer>> platforms = new ArrayList<>();
            Map<Integer, Boolean> completedPlatforms = new HashMap<>();
            
            // Save all platform queues to list.
            for (int j = 0; j < stationCount; j++) {
                final int cargoCount = inp.nextInt();
                Deque<Integer> platform =  new LinkedBlockingDeque<>(queueSize);

                for (int k = 0; k < cargoCount; k++) {
                    platform.addLast(inp.nextInt());
                }
                
                platforms.add(platform);
            }
            
            // Check which platforms are already done.
            for (int x = 1; x < stationCount + 1; x++) {
                completedPlatforms.put(x, platforms.get(x - 1).isEmpty() ? true : false);
            }

            int curr = 1;
            while (true) {
                // Check if we're done.
                boolean platformsDone = true;
                for (boolean isDone : completedPlatforms.values()) {
                    if (!isDone) {
                        platformsDone = false;
                        break;
                    }
                }
                if (platformsDone && stack.isEmpty()) break;
                
                // Walk to next station, so add time.
                minutes += 2;

                // Unload cargo.
                while (!stack.isEmpty()) {
                    if (stack.peek() == curr) {
                        stack.pop();
                        minutes++;
                    } else {
                        if (!platforms.get(curr - 1).offerLast(stack.peek())) {
                            break;
                        } else {
                            minutes++;
                            stack.pop();
                        }
                    }
                }

                // Load cargo.
                while (!platforms.get(curr - 1).isEmpty()) {
                    if (!stack.offerFirst(platforms.get(curr - 1).peek())) {
                        break;
                    } else {
                        minutes++;
                        platforms.get(curr - 1).pop();
                    }
                }

                // Keep track of which platforms we're done with.
                completedPlatforms.put(curr, platforms.get(curr - 1).isEmpty());
                curr = Math.max(1, (curr + 1) % (stationCount + 1));
            }
            // Print result for this input set.
            System.out.println(minutes);
        }
        inp.close();
    }
}
