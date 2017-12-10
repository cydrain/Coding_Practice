public class MallardDuck implements Quackable {
    QuackObservable quackObservable;

    public MallardDuck() {
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
