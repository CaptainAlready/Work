import java.text.SimpleDateFormat;  
import java.util.Date;  
import java.util.*;
public class FriendRequest extends User
{
ArrayList<FriendRequest> REQ= new ArrayList<FriendRequest>();
boolean req=false;
User user;
User user2;

protected void showState(){
SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");  
Date date = new Date();       
System.out.println("As of " + formatter.format(date)); 
if(user.request==0) System.out.println("Denied Request ");
else if(user.request==1)  {System.out.println("Accepted Request "); }
else System.out.println("Request Pending");
}


protected void showUser(){
System.out.println("Request from " + user.getName()+ " to " + user2.getName());    
}    
}
