public class ForecastDisplay implements Observer, DisplayElement {
    private Subject weatherData;

    public ForecastDisplay(Subject weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    public void update(float temperature, float humidity, float pressure) {
        display();
    }

    public void display() {
        System.out.println("Forecast: ");
    }
}
