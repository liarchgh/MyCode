import javax.swing.JOptionPane;
class Student
{
	String xuehao="0000000000";
    String banhao="00000000";
    String name="";
    String sex = "男";
    int nianling=0;
    Student(String a,String b,String n,String x,int y)
    {
        xuehao = a;
        banhao = b;
        name = n;
        sex = x;
        nianling = y;
    }
    //顺序为 学号、班号、姓名、性别、年龄
    public String chakan()
    {
        String x = "姓名:" + name +
                "\n学号:" + xuehao +
                "\n班号:" + banhao +
                "\n性别:" + sex +
                "\n年龄:" + nianling
                +"\n";
        return x;
    }
    public String xuehao()
    {
        return xuehao;
    }
    public String banhao()
    {
        return banhao;
    }
    public String name()
    {
        return name;
    }
    public String sex()
    {
        return sex;
    }
    public int nianling()
    {
        return nianling;
    }
}

public class zuoye2
{
	public static void main(String args[])
	{
        String xuehao = "2015201100";
        String banhao = "20152011";
        String name = "long";
        String sex = "男";
        int nianling = 18;
		Student a = new Student(xuehao, banhao, name, sex, nianling);
        JOptionPane.showMessageDialog(null,"开始分步输出\n");
        JOptionPane.showMessageDialog(null,a.name());
        JOptionPane.showMessageDialog(null,a.xuehao());
        JOptionPane.showMessageDialog(null,a.banhao());
        JOptionPane.showMessageDialog(null,a.sex());
        JOptionPane.showMessageDialog(null,a.nianling());
        JOptionPane.showMessageDialog(null,"下面为整体输出\n");
        JOptionPane.showMessageDialog(null,a.chakan());
	}

	private static void a(String xuehao, String banhao, String name, String sex, int nianling) {
		// TODO Auto-generated method stub
		
	}
}