interface PersonPay
{
	void pay();
}
abstract class Person implements PersonPay
{
	String name;
	char sex;
	int age;
	int gongzi;
}
class Teacher extends Person
{
	public void pay()
	{
		System.out.println(
			"姓名:"+name+
			"\n性别:"+sex+
			"\n年龄:"+age+
			"\n工资:"+gongzi+"\n"
		);
	}
}
class CollegeStudent extends Person
{
	int zxbz;
	public void pay()
	{
		System.out.println(
				"姓名:"+name+
				"\n性别:"+sex+
				"\n年龄:"+age+
				"\n助学补助:"+zxbz+"\n"
			);
	}
}
public class zuoye2 {
	public static void main(String args[])
	{
		
	}
}
