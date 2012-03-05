package linked;

import java.io.*;
import java.util.*;
import java.lang.String;
import java.util.Scanner;



class List
{
	private Node head;

	public List()
	{
		head = null;
	}	

	public void addnode(int d)
	{
		Node n = new Node(d);
		if(head != null)
		{
			Node end = head;
			while(end.next != null)
			{
				end = end.next;
			}
			end.next = n;
		}
		else
		{
			head=n;
		}
	}

	public void reverse()
	{
		Node start = head;
		Node temp = null;
		Node fwd = head;
		
		while(start != null)
		{
			fwd=start.next;
			start.next = temp;
			temp=start;
			start=fwd;
		}
		head = temp;
	}


	public void display()
	{
		Node start = head;
		while(start != null)
		{
			System.out.println(start.data);
			start=start.next;
		}
	}
	


	public static void main(String[] args)
	{
		System.out.println("List Starts");

		List l = new List();
		l.addnode(10);
		l.addnode(20);
		l.addnode(30);
		l.addnode(40);

		l.reverse();

		l.display();

	}

	class Node
	{
		private int data;
		private Node next;

		public Node()
		{
			data=0;
			next=null;
		}
		public Node(int d)
		{
			data = d;
		}
	}
}