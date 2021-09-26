class Box{
	int c,k,g;
	Box(int x,int y,int z){
		c=x;
		k=y;
		g=z;
	}
	int v()
	{
		return c*k*g;
	}
}
public class zuoye1 {
	public static void main(String args[]){
		Box m;
		int a,b,c;
		a=2;
		b=3;
		c=4;
		m = new Box(a,b,c);
		System.out.println(m.v());
	}
}