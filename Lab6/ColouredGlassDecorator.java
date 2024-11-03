import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator {
    public ColouredGlassDecorator(Component component, int x, int y, int width, int height) {
        super(component, x, y, width, height);
    }
    
    @Override
    public void draw(Graphics g) {
        super.draw(g);
        
        // Draw transparent green glass
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(new Color(0, 255, 0));  // Green
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.1f));
        g2d.fillRect(x, y, width, height);
        
        // Reset composite to normal
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1.0f));
    }
}