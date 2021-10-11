package hw6;

import java.io.*;
import java.util.*;

public abstract class Shape{
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
