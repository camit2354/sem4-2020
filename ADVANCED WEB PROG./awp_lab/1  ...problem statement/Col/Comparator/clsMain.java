 import java.util.*;
public class clsMain 
{
	public static void main(String[] args) 
	{
		clsComparator cc=new clsComparator();
		TreeSet<String> ts = new TreeSet<String>(cc);
		ts.add("ShivXXXX");
		ts.add("ShivXXXXXXX");
		ts.add("ShivXXXXX");
		ts.add("ShivXXXXXX");
		ts.add("ShivXXXX");
		ts.add("ShivXXXXX");
		Iterator<String> i = ts.iterator();
		while(i.hasNext())
		{
		String el = i.next();
		System.out.println(el +"");
		}
	}
}


