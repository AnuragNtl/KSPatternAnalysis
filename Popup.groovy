import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import groovy.json.*;
public class Popup
{
	private static def t1;
public static void main(String[] args)
{
def f1=new JFrame();
def p1=new JPanel();
t1=new JComboBox<String>();
t1.setEditable(true);
def jsonSlurper=new JsonSlurper();
def object;
if(new File("EntryList.json").exists())
object=jsonSlurper.parseText(new File("EntryList.json").getText()) as Set;
else
object=[] as Set;
JButton b1;
b1=new JButton("Add");
p1.setLayout(new GridLayout(0,1));
p1.add(t1);
p1.add(b1);
f1.add(p1);
b1.addActionListener(new ActionListener()
{
public void actionPerformed(ActionEvent e)
{
	object.add(t1.getSelectedItem().toString());
def pw1=new PrintWriter(new BufferedWriter(new FileWriter(new File("EntryList.json"))));
pw1.println(JsonOutput.toJson(object));
pw1.close();
System.exit(0);
}
	});
f1.pack();
f1.show();
}
};
