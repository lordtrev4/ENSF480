package EXAB;
import java.util.ArrayList;

class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> storage) {
        int n = storage.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (storage.get(j).getItem().compareTo(storage.get(minIndex).getItem()) < 0) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element
            Item<E> temp = storage.get(minIndex);
            storage.set(minIndex, storage.get(i));
            storage.set(i, temp);
        }
    }
}