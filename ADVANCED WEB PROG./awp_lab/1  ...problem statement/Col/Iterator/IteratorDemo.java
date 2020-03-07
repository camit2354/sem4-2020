import java.util.*;
	class IteratorDemo 
	{
		public static void main(String args[]) 
		{
			ArrayList<String> al = new ArrayList<String>();

			al.add("C");
			al.add("A");
			al.add("E");
			al.add("B");
			al.add("D");
			al.add("F");

			System.out.print("Original contents of al: ");
			Iterator<String> itr = al.iterator();
			while(itr.hasNext()) 
			{
				Object element = itr.next();
				System.out.print(element + " ");
			}
			System.out.println();

			// modify objects being iterated
			ListIterator<String> litr = al.listIterator();
				while(litr.hasNext()) 
				{
				Object element = litr.next();
				litr.set(element + "+");
				}
				System.out.print("Modified contents of al: ");
			itr = al.iterator();
			while(itr.hasNext()) 
			{
			Object element = itr.next();
			System.out.print(element + " ");
			}
			System.out.println();

			// now, display the list backwards
			System.out.print("Modified list backwards: ");
			while(litr.hasPrevious()) 
			{
			Object element = litr.previous();
			System.out.print(element + " ");
			}
			System.out.println();
		}
	}