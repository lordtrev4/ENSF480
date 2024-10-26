package EXC;

import java.util.ArrayList;

public class OneRow_Observer implements Observer {
    private DoubleArrayListSubject subject;

    public OneRow_Observer(DoubleArrayListSubject subject) {
        this.subject = subject;
        this.subject.registerObserver(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        display(data);
    }

    public void display(ArrayList<Double> data) {
        System.out.println("\nNotification to One-Row Observer: Data Changed:");
        for (Double d : data) {
            System.out.print(d + " ");
        }
        System.out.println();
    }
}
