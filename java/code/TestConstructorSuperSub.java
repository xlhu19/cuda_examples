
class SuperClass {
    private int n;

    SuperClass() {
        System.out.println("SuperClass()");
    }

    SuperClass(int n) {
        System.out.println("SuperClass(int n)");
        this.n = n;
    }
}

class SuperClass2 {

}

class SubClass extends SuperClass {
    private int n;

    SubClass() {
        super(300);
        System.out.println("SubClass");
    }

    public SubClass(int n) {
        System.out.println("SubClass(int n):" + n);
        this.n = n;
    }
}


class SubClass2 extends SuperClass2 {
    private int n;

    SubClass2() {
        System.out.println("SubClass");
    }

    public SubClass2(int n) {
        System.out.println("SubClass(int n):" + n);
        this.n = n;
    }
}

public class TestConstructorSuperSub{
    public static void main (String args[]) {
        SubClass sc11 = new SubClass();
        SubClass sc12 = new SubClass(200);

        SubClass2 sc21 = new SubClass2();
        SubClass2 sc22 = new SubClass2(200);

    }
}

