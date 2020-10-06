import java.lang.*;
import java.io.*;
import java.util.*;

public class Network extends User
{
  private static Network INSTANCE = null; 
  private Network() {} 
  public static Network getInstance() 
  { 
    if (INSTANCE == null) 
       INSTANCE = new Network(); 
    return INSTANCE; 
  } 
   
  
  ArrayList<User> Users = new ArrayList<User>();
  ArrayList<User> mutualFriends = new ArrayList<User>();
  
  
  
  
  
  
  protected void addU(User user){
  Users.add(user);   
  }  
  
  protected void remU(User user){    
  Users.remove(user);    
  }   
  
  protected boolean areFriends(User user,User user2){ 
  if(user.existF(user2)) return true; else return false;
  }
   
  protected  void friendList(User user){
  System.out.println("The friendlist of user : " + user.getName() + " is : ");
  user.returnFriends();
  }   
  
  protected void mutualFriends(User user,User user2){
  for(int i=0;i<user.Friends.size(); i++)
   for(int j=0; j<user2.Friends.size(); j++) 
    if(user.Friends.get(i)==user2.Friends.get(j)) mutualFriends.add(user.Friends.get(i)); 
  }
  
  protected void connectFriends(User user,User user2,FriendRequest f1){
  request(user,user2,f1);
  }
  
  
}
