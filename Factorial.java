import java.io.*;
import java.util.*;
import java.lang.String;

class Factorial
{
	public Factorial()
	{
		System.out.println("Constructor");
	}

   	public static void main(String[] args)
	{
		System.out.println("Factorial Program");

		if(args.length !=0)
		{
			int num = Integer.parseInt(args[0]);
			System.out.println("Number is : " + num);
			System.out.println("Factorial is : " + fact(num));
		}
		else
		{
			System.out.println("No arguments passed");
		}

display();	
	}


	private static int fact(int num)
	{
		if( (num == 0) || (num == 1))
			return num;
		else
		{
			return(num* fact(num-1));
		}

	}

public static void display()
{
	Scanner input = new Scanner( System.in );

	String n = "There is a string";
	String[] g = new String[10];

	for(int i=0;i<5;i++)
	{
		System.out.println("Enter a string: ");
	 	//int c  = input.nextInt();
//String j = Integer.toString(i);  
		g[i] = input.next();
	}	
	for(int i=0;i<5;i++)
	{
		System.out.println(g[i]);
	}	

}

}