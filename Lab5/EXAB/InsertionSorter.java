package EXAB;
import java.util.ArrayList;

class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> storage) {
        int n = storage.size();
        for (int i = 1; i < n; i++) {
            Item<E> key = storage.get(i);
            int j = i - 1;

            while (j >= 0 && storage.get(j).getItem().compareTo(key.getItem()) > 0) {
                storage.set(j + 1, storage.get(j));
                j = j - 1;
            }
            storage.set(j + 1, key);
        }
    }
}