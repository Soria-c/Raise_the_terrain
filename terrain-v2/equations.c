#include "main.h"

float xcoor(double lenght, double x0, double slope)
{
    return (x0 + sqrt(pow(lenght, 2) / (1 + pow(slope, 2))));
}

float ycoor(double slope, double y0, double x_x0)
{
    return ((slope * x_x0) + y0);
}