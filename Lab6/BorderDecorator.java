import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.BasicStroke;
import java.awt.Color;

public class BorderDecorator extends Decorator {
    public BorderDecorator(Component component, int x, int y, int width, int height) {
        super(component, x, y, width, height);
    }
    
    @Override
    public void draw(Graphics g) {
        super.draw(g);
        
        // Draw dashed border
        Graphics2D g2d = (Graphics2D) g;
        Stroke dashed = new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 
                                      0, new float[]{9}, 0);
        g2d.setStroke(dashed);
        g2d.setColor(Color.BLACK);
        g2d.drawRect(x, y, width, height);
    }
}