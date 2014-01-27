public class DuckCall implements Quackable {
    QuackObservable quackObservable;

    public DuckCall() {
        quackObservable = new QuackObservable(this);
    }

    public void quack() {
        System.out.println("Kwak");
        notifyObservers();
    }

    public void registerObserver(Observer observer) {
        quackObservable.registerObserver(observer);
    }

    public void notifyObservers() {
        quackObservable.notifyObservers();
    }
}
