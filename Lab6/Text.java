/*
File Name: Text.java
Assignment: Lab 6 Exercise AB
Lab section: B01
Completed by: Trevor Nguyen
Development Date: Nov 3, 2024
*/

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
        g.setColor(Color.BLACK);
        g.drawString(text, x-3, y);
    }
}
