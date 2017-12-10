public class RedheadDuck implements Quackable {
    QuackObservable quackObservable;

    public RedheadDuck() {
        quackObservable = new QuackObservable(this);
    }

    public void quack() {
        System.out.println("Quack");
        notifyObservers();
    }

    public void registerObserver(Observer observer) {
        quackObservable.registerObserver(observer);
    }

    public void notifyObservers() {
        quackObservable.notifyObservers();
    }
}
