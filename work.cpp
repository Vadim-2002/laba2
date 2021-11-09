#include <iostream>
#include <cstdlib>

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
};

int main()
{
    {
    Ellipse ellipse;
    Ellipse ellipse2(5, 5, 20, 10);
    Ellipse ellipse3(ellipse2);
    }
    
    printf("\nDynamically:\n");

    Ellipse* ellipse = new Ellipse();
    Ellipse* ellipse2 = new Ellipse(2, 2, 10, 5);
    Ellipse* ellipse3 = new Ellipse(*ellipse2);
    
    delete ellipse;
    delete ellipse2;
    delete ellipse3;

    system("pause");
    return 0;
}