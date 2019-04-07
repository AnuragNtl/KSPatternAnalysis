import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.util.*;
import java.util.stream.Stream;
import org.json.*;
import java.nio.file.*;
import java.nio.charset.Charset;

public class Popup
{
	private static JComboBox<String> t1;
private static String contents="";
private static volatile boolean submitted=false;
private static volatile String selectedLabel="";
public static String getLabel()
{
	//if(true)
	//return "_____";
try
{
	System.out.println("Started");
JFrame f1=new JFrame();
JPanel p1=new JPanel();
java.util.List<String> object=new ArrayList<String>()
{{
	add("Not Now");
}};
if(new File("EntryList.json").exists())
{
	try
	{
	Stream<String> lines=Files.lines(FileSystems.getDefault().getPath("EntryList.json"),Charset.forName("UTF-8"));
	lines.forEach((line)->{
		contents+=line;
	});
	lines.close();

	JSONArray data=new JSONArray(contents);
	for(int i=0;i<data.length();i++)
		object.add((String)data.get(i));
	}
catch(Exception e){}
}

t1=new JComboBox<String>(object.toArray(new String[0]));
t1.setEditable(true);
JButton b1;
b1=new JButton("Add");
p1.setLayout(new GridLayout(0,1));
p1.add(t1);
p1.add(b1);
f1.add(p1);
f1.setUndecorated(true);
f1.setAlwaysOnTop(true);
f1.addWindowListener(new WindowAdapter()
{
public void windowClosing(WindowEvent e)
{
updateSelection();
}
});
b1.addActionListener(new ActionListener()
{
public void actionPerformed(ActionEvent e)
{
updateSelection();
}
	});
f1.pack();
f1.setVisible(true);
while(!submitted);
f1.dispose();
}
catch(Throwable t)
{
	t.printStackTrace();
}
return selectedLabel;
}
public static void main(String args[])
{
	System.out.println(getLabel());
}
private static void updateSelection()
{
		selectedLabel=t1.getSelectedItem().toString();
		submitted=true;
}
};
