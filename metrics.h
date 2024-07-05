#ifndef METRICS_H
#define METRICS_H

namespace Metrics
{
    class MeanSquaredError
    {
    public:
        static float calculate();
    };

    class MeanAbsoluteError
    {
    public:
        static float calculate();
    };
}

#endif // METRICS_H