package EXAB;
import java.util.ArrayList;

class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> storage) {
        int n = storage.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (storage.get(j).getItem().compareTo(storage.get(j + 1).getItem()) > 0) {
                    Item<E> temp = storage.get(j);
                    storage.set(j, storage.get(j + 1));
                    storage.set(j + 1, temp);
                }
            }
        }
    }
}