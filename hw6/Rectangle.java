import hw6.Shape;

public class Rectangle extends Shape{
    private int height;
    private int width;
    public Rectangle(String color, int h, int w){
        super(color);
        height = h;
        width = w;
    }
    public void print(){
        double area = 0;
        String color;
        area = get_area();
        color = get_color();
        System.out.println(color + " rectangle, height " + height + ", width " + width + ", area " + area);
    }
    public double get_area(){
        double area = 0;
        area = height * width;
        return area;
    }
}