#include "hal/V5Motor.hpp"

namespace hal
{
V5Motor::V5Motor(const std::shared_ptr<pros::Motor>& motor) : m_motor{motor}
{

}

void V5Motor::setVoltage(double voltage)
{
    m_motor->move_voltage(voltage * MV_PER_V);
}
} // namespace hal