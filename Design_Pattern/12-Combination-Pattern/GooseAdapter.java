public class GooseAdapter implements Quackable {
    QuackObservable quackObservable;
    Goose goose;

    public GooseAdapter(Goose goose) {
        this.goose = goose;
        quackObservable = new QuackObservable(this);
    }

    public void quack() {
        goose.honk();
        notifyObservers();
    }

    public void registerObserver(Observer observer) {
        quackObservable.registerObserver(observer);
    }

    public void notifyObservers() {
        quackObservable.notifyObservers();
    }
}
