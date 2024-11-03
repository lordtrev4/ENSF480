package EXC;

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer {
    private DoubleArrayListSubject subject;

    public FiveRowsTable_Observer(DoubleArrayListSubject subject) {
        this.subject = subject;
        this.subject.registerObserver(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        display(data);
    }

    public void display(ArrayList<Double> data) {
        System.out.println("\nNotification to Five-Rows Table Observer: Data Changed:");
        int count = 0;
        for (Double d : data) {
            System.out.print(d + " ");
            if (++count % 5 == 0) System.out.println();
        }
        if (count % 5 != 0) System.out.println();
    }
}
