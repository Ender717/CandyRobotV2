#include "hal/V5RotationSensor.hpp"

namespace hal
{
V5RotationSensor::V5RotationSensor(const std::shared_ptr<pros::Rotation>& sensor) : m_sensor{sensor}
{

}

void V5RotationSensor::setRotation(double rotation)
{
    m_sensor->set_position(rotation * TICKS_PER_RADIAN);
}

double V5RotationSensor::getRotation()
{
    return m_sensor->get_position() / TICKS_PER_RADIAN;
}
} // namespace hal