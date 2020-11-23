class Box {
       // Instance Variables
       double length ;
       double width ;
       double height ;
       // Constructor
       Box ( double side )
       {
             width = side ;
             height = side ;
             length = side ;
       }
       Box (double length, double width,double height)
       {
           this.length=length;
           this.width=width;
           this.height=height;
       }
       
       // Methods
       double calculate()
             {
             return 2 * ( width * height +
             width * length +
             height * length ) ;
             }
       double newMethod()
       {
         return length*width*height;
        }

        public String toString()
        {
        String y = String.valueOf(calculate())   + " " +String.valueOf(newMethod());
        return y;
       
        }
    }
    

    
