import java.lang.*;
import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat; 
public class ReplyMessage extends User
{
String u1,u2;
String rmessage;  
static int likes; 
SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");  
Date date = new Date();   
String date1 =formatter.format(date);

protected void rMessage(User user, User user2,Message msg){
System.out.println("Write a reply : "); 
rmessage=user.post2(user2);
msg.message= msg.message + "\n" + "Reply : " +"\n" + rmessage;
rmessage=msg.message;
}

protected void getLikes(){
System.out.println("Number of likes is : " + likes);
}

public String toString()
{
return rmessage;    
}    
    
    
}
