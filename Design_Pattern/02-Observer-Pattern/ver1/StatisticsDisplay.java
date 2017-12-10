public class StatisticsDisplay implements Observer, DisplayElement {
    private float temperature;
    private Subject weatherData;

    public StatisticsDisplay(Subject weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    public void update(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        display();
    }

    public void display() {
        System.out.println("Avg/Max/Min temperature = ");
    }
}
