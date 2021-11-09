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

        Ellipse(Ellipse &object)
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
};

int main()
{
    {
    Ellipse ellipse1;
    Ellipse ellipse2(5, 5, 20, 10);
    Ellipse ellipse3(ellipse2);
    }
    
    printf("\nDynamically:\n");

    Ellipse* ellipse1 = new Ellipse();
    Ellipse* ellipse2 = new Ellipse(2, 2, 10, 5);
    Ellipse* ellipse3 = new Ellipse(*ellipse2);
    
    delete ellipse1;
    delete ellipse2;
    delete ellipse3;

    Ellipse ellipse(0, 0, 5, 5);
    printf("\nEccentricity = %f\n", ellipse.eccentricity());

    system("pause");
    return 0;
}