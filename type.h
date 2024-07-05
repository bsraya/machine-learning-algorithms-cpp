#ifndef TYPE_H
#define TYPE_H

namespace Type
{
    struct Iris
    {
        float sepal_length;
        float sepal_width;
        float petal_length;
        float petal_width;
    };

    struct CalifornianHousing
    {
        float median_income;
        float house_age;
        float average_rooms;
        float population;
        float average_occupancy;
        float latitude;
        float longitude;
    };
}

#endif // TYPE_H