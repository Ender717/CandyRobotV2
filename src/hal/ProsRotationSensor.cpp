#include "hal/ProsRotationSensor.hpp"

namespace hal
{
ProsRotationSensor::ProsRotationSensor(const std::shared_ptr<pros::Rotation>& sensor) : m_sensor{sensor}
{

}

void ProsRotationSensor::setRotation(double rotation)
{
    m_sensor->set_position(rotation * TICKS_PER_RADIAN);
}

double ProsRotationSensor::getRotation()
{
    return m_sensor->get_position() / TICKS_PER_RADIAN;
}
} // namespace hal