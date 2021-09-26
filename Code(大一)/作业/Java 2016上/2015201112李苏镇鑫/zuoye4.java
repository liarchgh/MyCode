//2015201112 李苏镇鑫
import java.io.*;
import java.util.Calendar;
import javax.swing.*;

public class zuoye4{
	private static File fyc;
	private static String ss;

	public static void main(String args[]){
		FileInputStream f1 = null;
		try {
			f1 = new FileInputStream("HelloA.txt");
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			FileInputStream f2 = new FileInputStream("HelloB.txt");
		} catch (FileNotFoundException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		FileOutputStream fo = null;
		try {
			fo = new FileOutputStream("Hello.txt");
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		int t;
		try {
			while((t=f1.read())!=-1){
				byte x[] = new byte[1];
				x[0] = (byte)t;
				try {
					fo.write(x,0,1);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		fyc = new File("newHello.txt");
		Calendar cal = Calendar.getInstance(); 
		cal.setTimeInMillis(fyc.lastModified()); 
		ss = "路径:"+cal.getTime()+
				"\n修改时间:"+fyc.lastModified()+
				"\n大小:"+fyc.length()+"B"+
				"\n可读性:"+fyc.canRead()+
				"\n可修改性:"+fyc.canWrite()+
				"\n";
		JOptionPane.showMessageDialog(null,ss);
	}
}
