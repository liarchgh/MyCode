import javax.swing.JOptionPane;
class Student
{
	String xuehao="0000000000";
    String banhao="00000000";
    String name="";
    String sex = "��";
    int nianling=0;
    Student(String a,String b,String n,String x,int y)
    {
        xuehao = a;
        banhao = b;
        name = n;
        sex = x;
        nianling = y;
    }
    //˳��Ϊ ѧ�š���š��������Ա�����
    public String chakan()
    {
        String x = "����:" + name +
                "\nѧ��:" + xuehao +
                "\n���:" + banhao +
                "\n�Ա�:" + sex +
                "\n����:" + nianling
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
        String sex = "��";
        int nianling = 18;
		Student a = new Student(xuehao, banhao, name, sex, nianling);
        JOptionPane.showMessageDialog(null,"��ʼ�ֲ����\n");
        JOptionPane.showMessageDialog(null,a.name());
        JOptionPane.showMessageDialog(null,a.xuehao());
        JOptionPane.showMessageDialog(null,a.banhao());
        JOptionPane.showMessageDialog(null,a.sex());
        JOptionPane.showMessageDialog(null,a.nianling());
        JOptionPane.showMessageDialog(null,"����Ϊ�������\n");
        JOptionPane.showMessageDialog(null,a.chakan());
	}

	private static void a(String xuehao, String banhao, String name, String sex, int nianling) {
		// TODO Auto-generated method stub
		
	}
}