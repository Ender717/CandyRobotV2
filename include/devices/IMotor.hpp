#ifndef DEVICES_I_MOTOR_HPP
#define DEVICES_I_MOTOR_HPP

namespace devices
{
/**
 * @brief Interface for voltage-controlled motors
 *
 * @author Nathan Sandvig
 */
class IMotor
{
public:
    /**
     * @brief Destroy the IMotor object
     *
     */
    virtual ~IMotor() = default;

    /**
     * @brief Set the voltage output for the motor
     *
     * @param voltage The voltage output in V
     */
    virtual void setVoltage(double voltage) = 0;
};
} // namespace devices

#endif