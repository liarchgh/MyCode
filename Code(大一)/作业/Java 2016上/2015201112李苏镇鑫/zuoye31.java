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
		return "姓名:"+name+
			"\n性别:"+sex+
			"\n年龄:"+age;
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
		return "姓名:"+name+
		"\n性别:"+sex+
		"\n年龄:"+age+
		"\njava成绩:"+java+
		"\n数据库成绩:"+sjk+
		"\n数据结构成绩:"+sjjg;
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
