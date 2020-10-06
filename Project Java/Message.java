import java.lang.*;
import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat; 
public class Message extends User
{
//String u1,u2;
String message=null;  
int likes; 
SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");  
Date date = new Date();   
String date1 =formatter.format(date);

protected void getMsg(User user ,User user2){
message=user.post2(user2);
//u1=user.getName();
//u2=user2.getName();
}

protected void getLikes(){
System.out.println("Number of likes is : " + likes);
}

public String toString()
{
return message;    
}    

}
