#include "hal/V5Motor.hpp"

namespace hal
{
V5Motor::V5Motor(const std::shared_ptr<pros::Motor>& motor) : m_motor{motor}
{

}

void V5Motor::setVoltage(double voltage)
{
    int32_t millivolts{static_cast<int32_t>(voltage * 1000)};
    m_motor->move_voltage(millivolts);
}
} // namespace hal