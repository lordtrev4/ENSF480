import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.BasicStroke;

public class BorderDecorator extends Decorator {
    private int x, y, width, height;

    public BorderDecorator(Component component, int x, int y, int width, int height) {
        super(component);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    @Override
    public void draw(Graphics g) {
        super.draw(g); // Draw the wrapped component first
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(3)); // Set border thickness
        g2d.drawRect(x, y, width, height); // Draw border
    }
}
