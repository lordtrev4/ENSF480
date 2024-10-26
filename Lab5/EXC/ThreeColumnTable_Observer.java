package EXC;

import java.util.ArrayList;

public class ThreeColumnTable_Observer implements Observer {
    private DoubleArrayListSubject subject;

    public ThreeColumnTable_Observer(DoubleArrayListSubject subject) {
        this.subject = subject;
        this.subject.registerObserver(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        display(data);
    }

    public void display(ArrayList<Double> data) {
        System.out.println("\nNotification to Three-Column Table Observer: Data Changed:");
        int count = 0;
        for (Double d : data) {
            System.out.print(d + " ");
            if (++count % 3 == 0) System.out.println();
        }
        if (count % 3 != 0) System.out.println();
    }
}
