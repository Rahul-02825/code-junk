import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

class Calculator extends Frame{
    private Button button[];
    private Label l1;
    private ArrayList<Character> list =new ArrayList<>();

    public Calculator(){
        
        setTitle("calculator");
        setLayout(new GridLayout(4,4));
        setSize(300,300);
        
        button=new Button[10];
        int count=0;
       for(int i=0;i<3;i++){   
            for(int j=0;j<3;j++){
                button[count]=new Button("click me"+count);
                add(button[count]);
                count++;
            }
       }                                                                  
       for(int k=0;k<9;k++){
            final int index = k;
            button[k].addActionListener(new ActionListener(){
                public void actionPerformed(ActionEvent e){
                    char charac=(char)(index+'0');
                    list.add(charac);
                    StringBuilder sb = new StringBuilder();
                    for (Character ch : list) {
                        sb.append(ch); // Append each character
                    }    
                    String result = sb.toString();
                    sb.setLength(0);
                    l1.setText(result);
                }
            });
       }
       l1=new Label("");
       add(l1);
        Button b1=new Button("clear");

        b1.addActionListener(new ActionListener() {
           public void actionPerformed(ActionEvent e){
                list.remove(list.size()-1); 
                StringBuilder sb = new StringBuilder();
                for (Character ch : list) {
                    sb.append(ch); // Append each character
                }    
                String result = sb.toString();
                sb.setLength(0);
                l1.setText(result);    
            }
        });
        add(b1);

        setVisible(true);
    }
    public static void main(String[] args) {
        new Calculator();
    }
}