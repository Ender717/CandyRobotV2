#ifndef HAL_PROS_MOTOR_HPP
#define HAL_PROS_MOTOR_HPP

#include <memory>

#include "pros/motors.hpp"

#include "devices/IMotor.hpp"

namespace hal
{
/**
 * @brief Adapter for Pros Motor to the IMotor interface
 *
 * @author Nathan Sandvig
 */
class ProsMotor : public devices::IMotor
{
private:
    /**
     * @brief Conversion rate from millivolts to volts
     *
     */
    static constexpr uint16_t MV_PER_V{1000};

    /**
     * @brief The Pros motor being adapted to the interface
     *
     */
    std::shared_ptr<pros::Motor> m_motor{nullptr};

public:
    /**
     * @brief Construct a new ProsMotor adapter
     *
     * @param motor The motor to adapt to the IMotor interface
     */
    ProsMotor(const std::shared_ptr<pros::Motor>& motor);

    /**
     * @brief Set the output voltage of the motor
     *
     * @param voltage The output voltage of the motor in V
     */
    void setVoltage(double voltage) final;
};
} // namespace hal

#endif