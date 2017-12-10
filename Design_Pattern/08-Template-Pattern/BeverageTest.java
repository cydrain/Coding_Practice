public class BeverageTest {
    public static void main(String[] args) {
        System.out.println("\nGet a cup of tea ...");
        Tea tea = new Tea();
        tea.prepareRecipe();

        System.out.println("\nGet a cup of coffee ...");
        Coffee coffee = new Coffee();
        coffee.prepareRecipe();
    }
}
