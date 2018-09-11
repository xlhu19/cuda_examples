
public class Accumulator {
    public static void main(String[] args) {
        int max = Integer.parseInt(args[0]);
        System.out.println(addAll(max));
    }

    static int addAll(int max) {
        int accum = 0;
        for (int i = 0; i < max; i++) {
            accum = add(accum, i);
        }
        return accum;
    }

    static int add(int a, int b) {
        return a + b;
    }
}

