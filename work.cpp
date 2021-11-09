#include <iostream>
#include <cstdlib>
#include <cmath>

class Ellipse
{
    protected:
        int x, y;
        int a, b;

    public:
        Ellipse()
        {
            printf("\nEllipse()\n");

            x = 0, y = 0;
            a = 0, b = 0;
        }

        Ellipse(int x, int y, int a, int b)
        {
            printf("\nEllipse(int x, int y, int a, int b)\n");

            this->x = x;
            this->y = y;
            this->a = a;
            this->b = b;
        }

        Ellipse(const Ellipse &object)
        {
            printf("\nEllipse(Ellipse &object)\n");

            x = object.x;
            y = object.y;
            a = object.a;
            b = object.b;
        }

        ~Ellipse()
        {
            printf("\nx = %d, y = %d, a = %d, b = %d\n", x, y, a, b);
            printf("\n~Ellipse()\n");
        }

        double eccentricity()
        {
            return sqrt(1 - (b*b/a/a));
        }

        void drow();
};

void Ellipse::drow()
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
            printf(" ");
        printf("#\n");
    }

    for (int i = 0; i < 2*a + 1; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
            printf(" ");
        printf("#\n");
    }
}

class ColoredEllipse: public Ellipse
{
    protected:
        int color;

    public:
        ColoredEllipse() : Ellipse()
        {
            printf("\nColoredEllipse()\n");
            
            color = 0;
        }

        ColoredEllipse(int x, int y, int a, int b, int color) : Ellipse(x, y, a, b)
        {
            printf("\nColoredEllipse(int x, int y, int a, int b, int color)\n");

            this->color = color;
        }

        ColoredEllipse(const ColoredEllipse &object)
        {
            printf("\nColoredEllipse(ColoredEllipse &object)\n");

            x = object.x;
            y = object.y;
            a = object.a;
            b = object.b;
            color = object.color;
        }

        ~ColoredEllipse()
        {
            printf("\nx = %d, y = %d, a = %d, b = %d, color = %d\n", x, y, a, b, color);
            printf("\n~ColoredEllipse()\n");
        }

        void change_color(int new_color)
        {
            color = new_color;
        }
};

class Cylinder
{
    protected:
        Ellipse* e1;
        Ellipse* e2;
    
    public:
        Cylinder()
        {
            printf("\nCylinder()\n");

            e1 = new Ellipse();
            e2 = new Ellipse();
        }

        Cylinder(int x, int y, int a, int b)
        {
            printf("\nCylinder(int x, int y, int a, int b)\n");

            e1 = new Ellipse(x, y, a, b);
            e2 = new Ellipse(x, y, a, b);
        }

        Cylinder(const Cylinder &c)
        {
            printf("\nCylinder(const Cylinder &c)\n");

            e1 = new Ellipse(*(c.e1));
            e2 = new Ellipse(*(c.e2));
        }

        ~Cylinder()
        {
            printf("\n~Cylinder()\n");

            delete e1;
            delete e2;
        }
};

int main()
{
    printf("\nStatically:\n");

    {
    Ellipse ellipse1;
    Ellipse ellipse2(5, 5, 20, 10);
    Ellipse ellipse3(ellipse2);
    }
    
    printf("================================================\n");

    printf("\nDynamically:\n");

    Ellipse* ellipse1 = new Ellipse();
    Ellipse* ellipse2 = new Ellipse(2, 2, 10, 5);
    Ellipse* ellipse3 = new Ellipse(*ellipse2);
    
    delete ellipse1;
    delete ellipse2;
    delete ellipse3;

    printf("================================================\n");

    Ellipse ellipse(0, 0, 5, 5);
    printf("\nEccentricity = %f\n", ellipse.eccentricity());

    ellipse.drow();

    printf("================================================\n");

    ColoredEllipse* e = new ColoredEllipse(0, 0, 4, 5, 66);
    e->change_color(99);

    delete e;

    printf("================================================\n");

    Cylinder* c1 = new Cylinder();
    Cylinder* c2 = new Cylinder(9, 9, 6, 7);
    Cylinder* c3 = new Cylinder(*c2);
    
    delete c1;
    delete c2;
    delete c3;

    system("pause");
    return 0;
}