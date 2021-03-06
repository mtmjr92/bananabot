#include "madmath.h"

float MadMath::get3DDistance(float own_x, float own_y, float own_z, float entity_x, float entity_y, float entity_z)
{
    return std::sqrt(std::pow(entity_x - own_x, 2) + std::pow(entity_y - own_y, 2) + std::pow(entity_z - own_z, 2));
}

// Standard CalcAngle, modified for different coordinate memory layout
std::vector<float> MadMath::calcAngle(std::vector<float> src, std::vector<float> dst)
{
    std::vector<float> angles;
    std::vector<double> delta = {src[0] - dst[0], src[1] - dst[1], src[2] - dst[2]};
    double hyp = std::sqrt(delta[0] * delta[0] + delta[2] * delta[2]);

    angles.push_back((float)(asinf(delta[1] / hyp) * RADIANT));
    angles.push_back((float)(atanf(delta[2] / delta[0]) * RADIANT));
    angles.push_back(0);

    if (delta[0] >= 0)
    {
        angles[1] += 180.0f;
    }

    return angles;
}
