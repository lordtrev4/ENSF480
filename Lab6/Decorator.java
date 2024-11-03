import java.awt.Graphics;

public abstract class Decorator implements Component {
    protected Component component;

    public Decorator(Component component) {
        this.component = component;
    }

    @Override
    public void draw(Graphics g) {
        component.draw(g); // Delegate drawing to the wrapped component
    }
}
