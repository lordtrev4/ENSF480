package EXAB;
import java.util.ArrayList;

interface Sorter<E extends Number & Comparable<E>> {
    void sort(ArrayList<Item<E>> storage);
}