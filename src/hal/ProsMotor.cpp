#include "hal/ProsMotor.hpp"

namespace hal
{
ProsMotor::ProsMotor(const std::shared_ptr<pros::Motor>& motor) : m_motor{motor}
{

}

void ProsMotor::setVoltage(double voltage)
{
    m_motor->move_voltage(voltage * MV_PER_V);
}
} // namespace hal