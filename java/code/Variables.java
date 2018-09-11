
enum FreshJuiceSize {
    SMALL, MEDIUM , LARGE
}

public class Variables {

    public static void enum_test() {
        FreshJuiceSize size;
        size = FreshJuiceSize.MEDIUM;
        System.out.println(size);
    }

    public static void main(String[] agrs) {
        enum_test();
    }
}

