import java.awt.*;

public class CircleDrawingExample extends Frame {

    public CircleDrawingExample() {
        // Frame settings
        setSize(400, 400);
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        // Draw the outer circle (larger one)
        g.setColor(Color.RED);
        g.fillOval(130, 100, 200, 200); // Draws a red circle

        // Draw the inner circle (smaller one) inside the larger circle
        g.setColor(Color.BLUE);
        g.fillOval(180, 150, 100, 100); // Draws a blue circle inside the red circle
    }

    public static void main(String[] args) {
        new CircleDrawingExample();
    }
}
