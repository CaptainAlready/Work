class MyBox extends Box {
  double side;
    
   MyBox(double side) {
    super(side,side,side); 
    this.side=side;
    if(side == 0){ System.out.println("Wrong");}
  }
 
       double calculate()
       {
       return 6*side*side;
       }

       double newMethod()
       {
         return side*side*side;
        }


 public String toString()
 {
  String y = String.valueOf(calculate())   + " " +String.valueOf(newMethod());
   return y;   
  }

}
