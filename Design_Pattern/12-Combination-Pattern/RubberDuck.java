public class RubberDuck implements Quackable {
    QuackObservable quackObservable;

    public RubberDuck() {
        quackObservable = new QuackObservable(this);
    }

    public void quack() {
        System.out.println("Squeak");
        notifyObservers();
    }

    public void registerObserver(Observer observer) {
        quackObservable.registerObserver(observer);
    }

    public void notifyObservers() {
        quackObservable.notifyObservers();
    }
}
