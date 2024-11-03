import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.BasicStroke;

public class ColouredFrameDecorator extends Decorator {
    private int thickness;
    
    public ColouredFrameDecorator(Component component, int x, int y, int width, int height, int thickness) {
        super(component, x, y, width, height);
        this.thickness = thickness;
    }
    
    @Override
    public void draw(Graphics g) {
        super.draw(g);
        
        // Draw thick red frame
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(thickness));
        g2d.setColor(Color.RED);
        g2d.drawRect(x, y, width, height);
    }
}
