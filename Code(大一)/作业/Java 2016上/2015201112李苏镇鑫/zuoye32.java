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
			"����:"+name+
			"\n�Ա�:"+sex+
			"\n����:"+age+
			"\n����:"+gongzi+"\n"
		);
	}
}
class CollegeStudent extends Person
{
	int zxbz;
	public void pay()
	{
		System.out.println(
				"����:"+name+
				"\n�Ա�:"+sex+
				"\n����:"+age+
				"\n��ѧ����:"+zxbz+"\n"
			);
	}
}
public class zuoye2 {
	public static void main(String args[])
	{
		
	}
}
