import java.awt.Graphics;

public abstract class Decorator implements Component {
    protected Component component;
    protected int x, y, width, height;
    
    public Decorator(Component component, int x, int y, int width, int height) {
        this.component = component;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
    
    @Override
    public void draw(Graphics g) {
        component.draw(g);
    }
}
