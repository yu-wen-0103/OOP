import java.io.*;
import java.util.*;

abstract class Shape{
    protected String color;
    public Shape(String inp){
        color = inp;
    }
    public abstract double get_area();
    public void print(){
        //
    }
    public String get_color(){
        return color;
    }
}

class Circle extends Shape{
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

class Rectangle extends Shape{
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

class Triangle extends Shape{
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

public class hw6{
    public static void main(String[] args)throws IOException{
        //Shape s;
        //s = new Triangle("green", 3, 4);
        //s.print();

        //Circle b = new Circle("green", 5);
        //b.print();

        //Rectangle c = new Rectangle("pink", 2, 4);
        //c.print();

        Vector<Shape> shape = new Vector<Shape>();
        Vector<String> type = new Vector<String>();
        String ss = "yellow";
        int x = 10, y = 20;
        Shape circle = new Circle(ss, x);
        Shape a = new Triangle(ss, x, y);
        Shape b = new Rectangle(ss, x, y);
        Shape c = new Triangle("red", 3, 5);

        Shape d = new Circle("green", 5);
        Shape e = new Rectangle("white", 3, 8);

        shape.addElement(circle);
        type.addElement("circle");
        shape.addElement(a);
        type.addElement("triangle");
        shape.addElement(b);
        type.addElement("rectangle");
        shape.addElement(c);
        type.addElement("triangle");
        shape.addElement(d);
        type.addElement("circle");
        shape.addElement(e);
        type.addElement("rectangle");

        System.out.println("Printing all shapes:");
        for(Shape p:shape){
            p.print();
        }

    }
}