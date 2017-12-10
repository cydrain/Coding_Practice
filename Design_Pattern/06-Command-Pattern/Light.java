public class Light {
    private boolean flag = false;
    private String name;

    public Light(String name) {
        this.name = name;
    }

    private String getName() {
        return name;
    }

    public void on() {
        if (!flag) {
            flag = true;
            System.out.println(getName() + " light is turned ON");
        }
        else {
            System.out.println(getName() + " light has already been turned ON");
        }
    }

    public void off() {
        if (flag) {
            flag = false;
            System.out.println(getName() + " light is turned OFF");
        }
        else {
            System.out.println(getName() + " light has already been turned OFF");
        }
    }
}
