class Person
{
	String name;
	char sex;
	int age;
	Person(String n)
	{
		this.name = n;
	}
	Person(char m)
	{
		sex = m;
	}
	Person(int z)
	{
		age = z;
	}
	public String toString()
	{
		return "����:"+name+
			"\n�Ա�:"+sex+
			"\n����:"+age;
	}
}
class Student extends Person
{
	String xh;
	int java;
	int sjk;
	int sjjg;
	public String toString()
	{
		return "����:"+name+
		"\n�Ա�:"+sex+
		"\n����:"+age+
		"\njava�ɼ�:"+java+
		"\n���ݿ�ɼ�:"+sjk+
		"\n���ݽṹ�ɼ�:"+sjjg;
	}
	double aver()
	{
		return ((double)(java+sjk+sjjg))/3;
	}
	int max()
	{
		int x = java;
		x=x>sjk?x:sjk;
		x=x>sjjg?x:sjjg;
		return x;
	}
	int min()
	{
		int x = java;
		x=x<sjk?x:sjk;
		x=x<sjjg?x:sjjg;
		return x;
	}
}
public class zuoye31 {
	public static void main(String args[])
	{}
}
