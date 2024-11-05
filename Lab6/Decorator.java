/*
File Name: Decorator.java
Assignment: Lab 6 Exercise AB
Lab section: B01
Completed by: Trevor Nguyen
Development Date: Nov 3, 2024
*/

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
