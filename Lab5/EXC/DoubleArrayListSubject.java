package EXC;

import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject {
    private ArrayList<Double> data;
    private ArrayList<Observer> observers;

    public DoubleArrayListSubject() {
        data = new ArrayList<>();
        observers = new ArrayList<>();
    }

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
        o.update(data);
    }

    @Override
    public void remove(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyAllObservers() {
        for (Observer observer : observers) {
            observer.update(data);
        }
    }

    public void addData(Double value) {
        data.add(value);
        notifyAllObservers();
    }

    public void setData(Double value, int index) {
        if (index >= 0 && index < data.size()) {
            data.set(index, value);
            notifyAllObservers();
        }
    }

    public void populate(double[] values) {
        for (double val : values) {
            data.add(val);
        }
        notifyAllObservers();
    }

    // Adding the display method
    public void display() {
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
        } else {
            for (Double value : data) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}

