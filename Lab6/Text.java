import java.awt.Graphics;
import java.awt.Color;

public class Text implements Component {
    private String text;
    private int x, y;
    
    public Text(String text, int x, int y) {
        this.text = text;
        this.x = x;
        this.y = y;
    }
    
    @Override
    public void draw(Graphics g) {
        g.setColor(Color.GREEN);
        g.drawString(text, x, y);
    }
}
