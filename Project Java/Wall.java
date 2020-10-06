import java.lang.*;
import java.io.*;
import java.util.*;

public class Wall extends User
{
ArrayList<Message> Messages = new ArrayList<Message>();  

protected void showPosts(){
    int temp; 
    temp=Messages.size();
if(temp==0){System.out.println("No posts yet");}
else {
for(int i=0; i<Messages.size(); i++){ System.out.println("Posts:\n" + Messages.get(i).toString()); Messages.get(i).getLikes();}
}    
}

}
