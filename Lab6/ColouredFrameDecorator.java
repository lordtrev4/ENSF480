import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Color;

public class ColouredFrameDecorator extends Decorator {
    private int x, y, width, height, thickness;

    public ColouredFrameDecorator(Component component, int x, int y, int width, int height, int thickness) {
        super(component);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.thickness = thickness;
    }

    @Override
    public void draw(Graphics g) {
        super.draw(g); // Draw the wrapped component first
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(Color.RED);
        g2d.fillRect(x, y, width, thickness); // Top border
        g2d.fillRect(x, y + height - thickness, width, thickness); // Bottom border
        g2d.fillRect(x, y, thickness, height); // Left border
        g2d.fillRect(x + width - thickness, y, thickness, height); // Right border
    }
}
