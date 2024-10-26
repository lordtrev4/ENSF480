package EXC;

public interface Subject {
    void registerObserver(Observer o);
    void remove(Observer o);
    void notifyAllObservers();
}