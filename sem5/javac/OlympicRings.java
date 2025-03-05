import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class OlympicRings extends JFrame {

    public OlympicRings() {
        // Set the title and size of the frame
        setTitle("Olympic Rings");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close the application when the window is closed

        // Add custom panel for drawing
        add(new RingsPanel());

        // Make the frame visible
        setVisible(true);
    }

    // Custom JPanel for drawing the Olympic rings
    class RingsPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g); // Call the superclass's paintComponent method

            // Cast Graphics to Graphics2D to set stroke thickness
            Graphics2D g2 = (Graphics2D) g;
            g2.setStroke(new BasicStroke(5)); // Set stroke thickness to 5 pixels

            // Draw the blue ring
            g2.setColor(Color.BLUE);
            g2.drawOval(100, 100, 100, 100);  // x, y, width, height

            // Draw the yellow ring
            g2.setColor(Color.YELLOW);
            g2.drawOval(150, 150, 100, 100);

            // Draw the black ring
            g2.setColor(Color.BLACK);
            g2.drawOval(200, 100, 100, 100);

            // Draw the green ring
            g2.setColor(Color.GREEN);
            g2.drawOval(300, 150, 100, 100);

            // Draw the red ring
            g2.setColor(Color.RED);
            g2.drawOval(400, 100, 100, 100);
        }
    }

    public static void main(String[] args) {
        new OlympicRings(); // Create and display the frame
    }
}
