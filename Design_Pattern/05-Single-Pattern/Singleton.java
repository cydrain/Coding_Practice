public class Singleton {
    private volatile static Singleton uniqueInstance;

    private Singleton() {
        System.out.println("Singleton instance created!");
    }

    public static Singleton getInstance() {
        if (uniqueInstance == null) {
            synchronized (Singleton.class) {
                if (uniqueInstance == null) {
                    uniqueInstance = new Singleton();
                }
            }
        }
        System.out.println("Get Singleton instance.");
        return uniqueInstance;
    }
}

