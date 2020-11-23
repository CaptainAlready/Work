public class RunMe{
 public static void main(String[] args)   
  {   
   Box b1 = new Box(2.5,3.0,4.0); 
   MyBox b2 = new MyBox(3.0);
   PaperBox b3 = new PaperBox(2.0,4.0,3.0,10.0);
   b3.color="Blue";
   System.out.println("Calculation " + b1.calculate() + " , Volume " + b1.newMethod() +  "\n" + "Cube Calculation "+ b2.calculate() + " , Volume " + b2.newMethod());
   System.out.println("Paperbox Calculation " + b3.calculate() + " , Volume" + b3.newMethod() + " , Weight "+ b3.weight + " , Color " + b3.color);
    
    }   
}