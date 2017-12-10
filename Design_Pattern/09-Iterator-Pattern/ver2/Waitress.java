import java.util.Iterator;

public class Waitress {
    Menu pancakeHouseMenu;
    Menu dinnerMenu;
    Menu cafeMenu;

    public Waitress(Menu pancakeHouseMenu, Menu dinnerMenu, Menu cafeMenu) {
        this.pancakeHouseMenu = pancakeHouseMenu;
        this.dinnerMenu = dinnerMenu;
        this.cafeMenu = cafeMenu;
    }

    public void printMenu() {
        Iterator pancakeIterator = pancakeHouseMenu.createIterator();
        Iterator dinnerIterator = dinnerMenu.createIterator();
        Iterator cafeIterator = cafeMenu.createIterator();

        System.out.println("MENU\n----\nBREAKFAST");
        printMenu(pancakeIterator);

        System.out.println("\nLUNCH");
        printMenu(dinnerIterator);

        System.out.println("\nDINNER");
        printMenu(cafeIterator);
    }

    public void printMenu(Iterator iterator) {
        while (iterator.hasNext()) {
            MenuItem menuItem = (MenuItem)iterator.next();
            System.out.println(menuItem.getName() + ", "
                             + menuItem.getPrice() + " -- "
                             + menuItem.getDescription());
        }
    }
}

