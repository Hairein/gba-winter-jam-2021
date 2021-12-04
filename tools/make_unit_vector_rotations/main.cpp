//{bn::fixed(0.0), bn::fixed(0.0)}, // 0

#include <iostream>
#include <cmath>

int main();

int main()
{
    for(int angle = 0; angle <= 359; angle++)
    {
        double angleRadians = (angle * M_PI) / 360.0;

        double unitVectorX = 0.0;
        double unitVectorY = -1.0;

        double angleDoubleX = unitVectorX * cos(angleRadians) - unitVectorY * sin(angleRadians);
        double angleDoubleY = unitVectorX * sin(angleRadians) + unitVectorY * cos(angleRadians);

        if(angleDoubleX > -0.000001 && angleDoubleX < 0.000001)
        {
            angleDoubleX = 0.0;
        }
        if(angleDoubleY > -0.000001 && angleDoubleY < 0.000001)
        {
            angleDoubleY = 0.0;
        }
        
        std::cout << "{bn::fixed(" << angleDoubleX << "), bn::fixed(" << angleDoubleY << ")}, //" <<  angle << std::endl; 
    }

    return 0;
}