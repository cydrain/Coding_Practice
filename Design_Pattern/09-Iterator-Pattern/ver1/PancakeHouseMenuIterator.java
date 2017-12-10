import java.util.*;

public class PancakeHouseMenuIterator implements Iterator {
    ArrayList items;
    int position = 0;

    public PancakeHouseMenuIterator(ArrayList items) {
        this.items = items;
    }

    public MenuItem next() {
        MenuItem item = (MenuItem)items.get(position);
        position = position + 1;
        return item;
    }

    public boolean hasNext() {
        if (position >= items.size() || items.get(position) == null) {
            return false;
        }
        else {
            return true;
        }
    }
}
