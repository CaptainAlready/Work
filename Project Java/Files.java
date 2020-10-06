import java.io.*;

public class Files extends Main 
{
    public int test(){return 1;}
   public static void storeObject(User emp){
         
        OutputStream ops = null;
        ObjectOutputStream objOps = null;
        try {
            ops = new FileOutputStream("User.txt");
            objOps = new ObjectOutputStream(ops);
            objOps.writeObject(emp);
            objOps.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally{
            try{
                if(objOps != null) objOps.close();
            } catch (Exception ex){
                 
            }
        }
    }
    
    
     public static void displayObjects(){
         
        InputStream fileIs = null;
        ObjectInputStream objIs = null;
        try {
            fileIs = new FileInputStream("User.txt");
            objIs = new ObjectInputStream(fileIs);
            User emp = (User) objIs.readObject();
            System.out.println(emp);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                if(objIs != null) objIs.close();
            } catch (Exception ex){
                 
            }
        }
    }
}