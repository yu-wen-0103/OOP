class Shape:
    def __init__(self, color):
        self.__color = color
    def get_color(self):
        return self.__color

class Circle(Shape):
    def __init__(self, color, radius):
        super().__init__(color)
        self.__radius = radius
    def get_radius(self):
        return self.__radius
    def get_area(self):
        r = self.get_radius()
        area = 3.14159265359 * r* r
        return area
    def print(self):
        c_r = self.get_radius()
        c_c = self.get_color()
        c_a = self.get_area()
        print(c_c, ' circle, radius ', c_r,', area ', c_a)

class Rectangle(Shape):
    def __init__(self, color, heigth, width):
        super().__init__(color)
        self.__height = heigth
        self.__width = width
    def get_height(self):
        return self.__height
    def get_width(self):
        return self.__width
    def get_area(self):
        h = self.get_height()
        w = self.get_width()
        area = h * w
        return area
    def print(self):
        r_c = self.get_color()
        r_h = self.get_height()
        r_w = self.get_width()
        r_a = self.get_area()
        print(r_c, ' rectangle, height ', r_h,', width ', r_w, ', area ', r_a)

class Triangle(Shape):
    def __init__(self, color, height, base):
        super().__init__(color)
        self.__height = height
        self.__base = base
    def get_height(self):
        return self.__height
    def get_base(self):
        return self.__base
    def get_area(self):
        h = self.get_height()
        b = self.get_base()
        area = h * b / 2
        return area
    def print(self):
        t_c = self.get_color()
        t_h = self.get_height()
        t_b = self.get_base()
        t_a = self.get_area()
        print(t_c, ' triangle, height ', t_h,', base ', t_b, ', area ', t_a)

test1 = Circle('green', 10)
test1.print()

test2 = Rectangle('red', 3, 4)
test2.print()

test3 = Triangle('pink', 5, 7)
test3.print()
