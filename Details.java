import java.io.*;

interface SetGet
{

public void setName(String n);

public String getName();
}

class Student implements SetGet
{
private String stuNum;
private String name;
private String msg;
public void setName(String n)
{
name = n;
}

public void setStuNum(String sn)
{
stuNum = sn;
}
public String getName()
{
return name;
}

public String getStuNum()
{
return stuNum;
}

public void setMsg(String msg)
{
this.msg=msg;
  
}

public String getMsg()
{
  return msg;
}

}
public class Details
{
public static void printMSG()
{
    System.out.println("\nDetails are displayed here\n\n");
}

public static void main(String[] args)
{
Student st;

Student stu = new Student();
st = stu;

BufferedReader  stdin = new BufferedReader (new InputStreamReader (System.in));

stu.setName("John Smith");
st.setStuNum("12345");

System.out.print("Enter Message: ");
System.out.flush();
try
{
String msg = stdin.readLine();
st.setMsg(msg);
}
catch(Exception e)
{
    System.err.println("Not able to read input");
}

printMSG();

stu.setName("John Smith");
System.out.println(st.getMsg());
System.out.println("Student Name: " + st.getName());
System.out.println("Student Number: " + stu.getStuNum());
}
}
