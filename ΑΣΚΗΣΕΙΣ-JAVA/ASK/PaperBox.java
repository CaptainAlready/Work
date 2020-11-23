class PaperBox extends Box
{
double weight;
String color; 
    
    
PaperBox(double length,double width,double height,double weight)
{
super(length,width,height);  
this.weight=weight;
color="No Color";    
    
}   
    
public String toString()
 {
  String y = String.valueOf(calculate())   + " " +String.valueOf(newMethod() + String.valueOf(weight))+ "Color = " +color;
   return y;   
  }

    
}    