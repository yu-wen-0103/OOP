import hw6.Shape;

import java.io.*;
import java.util.*;

public class hw6_main{
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