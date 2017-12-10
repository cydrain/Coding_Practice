public class Quackologist implements Observer {
    public void update(Observable duck) {
        System.out.println("Quackologist: " + duck + " just quacked.");
    }
}
