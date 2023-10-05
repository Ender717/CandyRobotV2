#ifndef HAL_V5_MOTOR_HPP
#define HAL_V5_MOTOR_HPP

#include <memory>

#include "pros/motors.hpp"

#include "devices/IMotor.hpp"

namespace hal
{
/**
 * @brief Adapter for V5Motor to the IMotor interface
 *
 * @author Nathan Sandvig
 */
class V5Motor : public devices::IMotor
{
private:
    /**
     * @brief The v5 motor being adapted to the interface
     *
     */
    std::shared_ptr<pros::Motor> m_motor{nullptr};

public:
    /**
     * @brief Construct a new V5Motor adapter
     *
     * @param motor The motor to adapt to the IMotor interface
     */
    V5Motor(const std::shared_ptr<pros::Motor>& motor);

    /**
     * @brief Set the output voltage of the motor
     *
     * @param voltage The output voltage of the motor in V
     */
    void setVoltage(double voltage) final;
};
} // namespace hal

#endif