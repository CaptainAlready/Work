import java.lang.*;
import java.io.*;
import java.util.*;

public class Main extends User
{
public static void main(String args[]){
boolean exit=false;
boolean logout=false;
boolean flag=false;
boolean flag2=false;

String username;
int j=0,k=0;
String friend;
 
Files f1= new Files();
Network x=Network.getInstance();
Scanner input = new Scanner(System.in);
 //try {   for(int metrhsh=0; metrhsh<1; metrhsh++){
         //FileInputStream fileIn = new FileInputStream("User.txt");
        // ObjectInputStream in = new ObjectInputStream(fileIn);
       //  f1.storeObject((User) in.readObject());
       //  in.close();
      //   fileIn.close();}
     // } catch (IOException i) {
    //     i.printStackTrace();
   //      return;
  //    } catch (ClassNotFoundException c) {
  //       System.out.println("Deserialization error.");
   //      c.printStackTrace();
   //      return;}
User Panos = new User();
User Basilhs = new User();
User Rhnio = new User();
User Photis = new User();
x.Users.add(Panos);
x.Users.add(Basilhs);
x.Users.add(Rhnio);


Panos.setName("Panos");
Basilhs.setName("Basilhs");
Rhnio.setName("Rhnio");


f1.storeObject(Panos);
f1.displayObjects();

for(int i=0; i<3; i++) {
Wall w = new Wall();
Message m = new Message();
ReplyMessage r = new ReplyMessage();
FriendRequest fr = new FriendRequest();
//x.Users.get(i).setName();
x.Users.get(i).wall=w;
x.Users.get(i).message=m;
x.Users.get(i).replymessage=r;
x.Users.get(i).friendrequest=fr;
}





System.out.println("\f");
String encoding = "Cp1250";
File file = new File("example.rtf");
if (file.exists()) {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file), encoding))) {
        String line = null;
        while ((line = br.readLine()) != null) {
            System.out.println(line);
        }
    } catch (IOException e) {
        e.printStackTrace();
    }
}


try {
	Thread.sleep(3000); // 10000ms = 10s
} catch(InterruptedException ex){
 
	System.exit(0);
}
System.out.println("\f");

System.out.println("***********************Welcome***********************");
do{
System.out.println("Type yes if you want to exit or no to login");
flag2=true;
String ans =input.next();
if(ans.equals("no")){
logout=false; 
while(flag==false){
System.out.println("Enter username to login");
username = input.next();
//System.out.println(x.Users.size());
if(exist(username,x.Users)){ flag=true; j=findIndex(username,x.Users); System.out.println("Welcome " + username);}
else if(exist(username,x.Users)==false) System.out.println("There is no such user ");}
flag=false; 

while(logout==false){ 
//System.out.println("Index is " + j); TEST
System.out.println("What would you like to do?");
System.out.println("1)See your Wall  2) See friends wall  3)Wall actions 4)Send friend request 5)Accept/Reject friend request 6)See my friends 7)Logout");
int i = input.nextInt();
System.out.println("\f");
switch(i)  {  
 
 case 1:   
 x.Users.get(j).wall.showPosts();
 break;   
    
 case 2:  
 System.out.println("Select Friend ");

 x.friendList(x.Users.get(j));
 friend=input.next();
 k=findIndex(friend,x.Users);
 if(x.areFriends(x.Users.get(j),x.Users.get(k))) 
 {
 if(x.Users.get(k).wall.Messages.isEmpty()==false)
 x.Users.get(k).wall.showPosts(); 
 else if(x.Users.get(k).wall.Messages.isEmpty()) System.out.println("No posts");
 else break;}
 break;  
 
 

 
 
 case 3:
 System.out.println("1) Post a message 2)Reply to a message 3)Like message ");
 int o = input.nextInt();
 switch(o){
 case 1:
 System.out.println("Select Friend ");
 x.friendList(x.Users.get(j));  
 friend=input.next(); 
 k=findIndex(friend,x.Users);
 if(x.areFriends(x.Users.get(j),x.Users.get(k))) {
 String message=input.nextLine();
 x.Users.get(k).message.message=message;
 x.Users.get(k).wall.Messages.add(x.Users.get(k).message);
 x.Users.get(k).message.getMsg(x.Users.get(k),x.Users.get(j));
 System.out.println("Message posted ");}
 else break;
 break;
 case 2:

 System.out.println("Select Friend to show wall and reply ");
 x.friendList(x.Users.get(j));  
 friend=input.next(); 
 k=findIndex(friend,x.Users);
 if(x.areFriends(x.Users.get(j),x.Users.get(k))) {
 String reply=input.nextLine();
 x.Users.get(k).replymessage.rMessage(x.Users.get(j),x.Users.get(k),x.Users.get(k).message);
 x.Users.get(k).message.message=null;
 x.Users.get(k).message.message=x.Users.get(k).replymessage.rmessage;}
 break;
 
 case 3:

 System.out.println("Select Friend to show wall and reply ");
 x.friendList(x.Users.get(j));  
 friend=input.next(); 
 k=findIndex(friend,x.Users);
 if(x.areFriends(x.Users.get(j),x.Users.get(k))){
 System.out.println("Message :");
 x.Users.get(k).message.toString();
 x.Users.get(k).like(x.Users.get(k).message);
 x.Users.get(k).message.getLikes();}
 break;
 }
 break;
 
 case 4:
 boolean flag1=false;
 for(User user : x.Users)
 if(x.areFriends(x.Users.get(j),user)==false && x.Users.get(j)!=user) flag1=true;
 
 
 if(flag1){ 
 System.out.println("Select person to send friendrequest to");
 for(User user : x.Users){
 if(x.areFriends(x.Users.get(j),user)==false && x.Users.get(j)!=user) {System.out.println(user.getName()); flag1=true;}
 }
 
 friend=input.next(); 
 k=findIndex(friend,x.Users);
 sendFriend(x.Users.get(j),x.Users.get(k),x.Users.get(k).friendrequest);
 x.Users.get(k).friendrequest.user=x.Users.get(j);
 x.Users.get(k).friendrequest.user2=x.Users.get(k);
 x.Users.get(k).friendrequest.REQ.add(x.Users.get(k).friendrequest);}else System.out.println("No person to send request to");
 break;
 
case 5:
if(x.Users.get(j).friendrequest.REQ.size()!=0){
System.out.println("Requests :");
for(int a=0; a<x.Users.get(j).friendrequest.REQ.size(); a++) {
 System.out.println(a);
 x.Users.get(j).friendrequest.REQ.get(a).showUser();  
 x.Users.get(j).friendrequest.REQ.get(a).showState();
} 
System.out.println("Pick request to answer to :");
int d =input.nextInt();
int y=0;
for(int a=0; a<x.Users.size(); a++) if(x.Users.get(j).friendrequest.REQ.get(d).user.equals(x.Users.get(a))) y=a;
request(x.Users.get(j),x.Users.get(y), x.Users.get(j).friendrequest.REQ.get(d));
x.Users.get(j).friendrequest.REQ.remove(d);}
else System.out.println("No requests ");
break;
         
case 6:
if(x.Users.get(j).Friends.isEmpty()) System.out.println("You have no friends :( ");
else{
System.out.println("Your friends are : ");
x.Users.get(j).returnFriends();}
break;
   
        
case 7:
System.out.println("Do you want to logout?");
String reply = input.next(); 
if(reply.equalsIgnoreCase("yes")) logout=true;
//try {
        /// FileOutputStream fileOut =
        // new FileOutputStream("TESTGTXM.txt");
         //ObjectOutputStream out = new ObjectOutputStream(fileOut);
         //out.writeObject(x);
         //out.close();
         //fileOut.close();
         //System.out.printf("Serialized data is saved.");
     /// } catch (IOException lol) {
      //   lol.printStackTrace();
     // }
//for(int metrhsh=0; metrhsh<1; metrhsh++) {
//f1.storeObject(x.Users.get(metrhsh));
//}
break;   
      }
     }
   }else exit=true;
}while(exit==false);
 
}
}
