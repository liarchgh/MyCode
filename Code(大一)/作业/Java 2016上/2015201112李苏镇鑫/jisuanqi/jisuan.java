package jisuanqi;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class jisuan {

	public static void main(String args[])
	{
		js xmm=new js();
	}
}

class js
{
	shuzi s1 = new shuzi();
	yunsuan s2 = new yunsuan();
	denghao s3 = new denghao();
	qingchu s4 = new qingchu();
	del s5 = new del();
	private static JButton bs[] = new JButton[9];
	public static boolean z = false;
	private static JButton fus[] = new JButton[9];
	public static JTextField te=new JTextField(0);
	int i,j;
	public static double x,y;
	public static String fu;
	js()
	{
		fu = "";
		x=y=0;
		JFrame fr=new JFrame("计算器");
		fr.setLayout(null);
		fr.setSize(900,700);
		fr.setBackground(Color.white);
		fr.setLocation(200,100);
		for(i=0;i<9;++i)
		{
			int m=i+1;
			bs[i] = new JButton(""+m);
			bs[i].addActionListener(s1);
			fr.add(bs[i]);
		}
		for(i=0;i<=6;i+=3)
			for(j=0;j<3;++j)
			{
				bs[i+j].setBounds(30+j*60+5,90+i/3*60+5,55,50);
			}
		fus[0] = new JButton("+");
		fus[0].addActionListener(s2);
		fus[1] = new JButton("-");
		fus[1].addActionListener(s2);
		fus[2] = new JButton("C");
		fus[2].addActionListener(s4);
		fus[3] = new JButton("*");
		fus[3].addActionListener(s2);
		fus[4] = new JButton("/");
		fus[4].addActionListener(s2);
		fus[5] = new JButton("=");
		fus[5].addActionListener(s3);
		fus[6] = new JButton("0");
		fus[6].addActionListener(s1);
		fus[7] = new JButton(".");
		fus[7].addActionListener(s1);
		fus[8] = new JButton("Del");
		fus[8].addActionListener(s5);
		for(i=0;i<=6;i+=3)
			for(j=0;j<3;++j)
			{
				fr.add(fus[i+j]);
				fus[i+j].setBounds(210+j*60+5,90+i/3*60+5,55,50);
			}
		fr.add(te);
		te.setEditable(false);
		te.setBounds(35,35,600,50);
		fr.setVisible(true);
		
	}
}

class shuzi implements ActionListener//数字按钮的时间
{
	public void actionPerformed(ActionEvent e)
	{
		boolean p=true;
		if(js.z) {js.te.setText("");js.z = false;}
		String b = js.te.getText();
		if((e.getActionCommand() == ".")&&(b.indexOf('.') != -1))
			p=false;
		if(p)
		{
			b+=e.getActionCommand();
			js.te.setText(b);
		}
	}
}

class yunsuan implements ActionListener
{
	public void actionPerformed(ActionEvent e)
	{
		if(js.fu == "")
		{
			js.fu = e.getActionCommand();
			js.x+=Double.parseDouble(js.te.getText().toString());
			js.te.setText("");
		}
		else
		{
			if(js.te.getText() != "")
			{
				byte f[] = js.fu.getBytes();
				switch((int)(f[0]))
				{
					case '+':js.x+=Double.parseDouble(js.te.getText());break;
					case '-':js.x-=Double.parseDouble(js.te.getText());break;
					case '*':js.x*=Double.parseDouble(js.te.getText());break;
					case '/':js.x/=Double.parseDouble(js.te.getText());break;
				}
				js.te.setText("");
			}
			js.fu = e.getActionCommand();
		}
	}
}

class denghao implements ActionListener
{
	public void actionPerformed(ActionEvent e)
	{
		byte f[] = js.fu.getBytes();
		switch((int)(f[0]))
		{
			case '+':js.x+=Double.parseDouble(js.te.getText());break;
			case '-':js.x-=Double.parseDouble(js.te.getText());break;
			case '*':js.x*=Double.parseDouble(js.te.getText());break;
			case '/':js.x/=Double.parseDouble(js.te.getText());break;
		}
		js.te.setText(String.valueOf(js.x));
		js.fu = "";
		js.x = 0;
		js.z = true;
	}
}

class qingchu implements ActionListener
{
	public void actionPerformed(ActionEvent e)
	{
		js.te.setText("");
	}
}

class del implements ActionListener
{
	public void actionPerformed(ActionEvent e)
	{
		String str = js.te.getText();
		str = str.substring(0,str.length()-1);
		js.te.setText(str);
	}
}