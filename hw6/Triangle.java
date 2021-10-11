import hw6.Shape;

public class Triangle extends Shape{
    private int height;
    private int base;
    public Triangle(String color, int h, int b){
        super(color);
        height = h;
        base = b;
    }
    public void print(){
        double area = 0;
        String color;
        area = get_area();
        color = get_color();
        System.out.println(color + " triangle, height " + height + ", base " + base + ", area " + area);
    }
    public double get_area(){
        double area = 0;
        area = height * base / 2;
        return area;
    }
}