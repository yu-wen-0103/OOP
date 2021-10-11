import hw6.Shape;


public class Circle extends Shape{
    private int radius;
    public Circle(String color, int r){
        super(color);
        radius = r;
    }
    public void print(){
       double area = 0;
       String color;
       area = get_area();
       color = get_color();
       System.out.println(color + " circle, radius " + radius + ", area " + area);
    }
    public double get_area(){
        double area = 0;
        area = 3.141592653559 * radius * radius;
        return area;
    }
}