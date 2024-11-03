package EXAB;
import java.util.ArrayList;

class MyVector<E extends Number & Comparable<E>> {
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    // Constructor with capacity
    public MyVector(int capacity) {
        storageM = new ArrayList<>(capacity);
    }

    // Constructor with ArrayList
    public MyVector(ArrayList<Item<E>> arr) {
        storageM = new ArrayList<>(arr);
    }

    // Add an Item<E> to storageM
    public void add(Item<E> value) {
        storageM.add(value);
    }

    // Set the sorting strategy
    public void setSortStrategy(Sorter<E> s) {
        sorter = s;
    }

    // Perform sort using the selected strategy
    public void performSort() {
        if (sorter != null) {
            sorter.sort(storageM);
        }
    }

    // Display items in storageM
    public void display() {
        for (Item<E> item : storageM) {
            System.out.print(item.getItem() + " ");
        }
        System.out.println();
    }
}