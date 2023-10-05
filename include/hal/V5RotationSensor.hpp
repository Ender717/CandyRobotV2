#ifndef HAL_V5_ROTATION_SENSOR_HPP
#define HAL_V5_ROTATION_SENSOR_HPP

#include <cmath>
#include <memory>

#include "pros/rotation.hpp"

#include "devices/IRotationSensor.hpp"

namespace hal
{
/**
 * @brief Adapter for V5RotationSensor to the IRotationSensor interface
 *
 * @author Nathan Sandvig
 */
class V5RotationSensor : public devices::IRotationSensor
{
private:
    /**
     * @brief Conversion constant from sensor ticks to radians
     *
     */
    static constexpr double TICKS_PER_RADIAN{18000 / M_PI};

    /**
     * @brief The v5 rotation sensor being adapted to the interface
     *
     */
    std::shared_ptr<pros::Rotation> m_sensor{nullptr};

public:
    /**
     * @brief Construct a new V5RotationSensor adapter
     *
     * @param sensor The sensor to adapt to the IRotationSensor interface
     */
    V5RotationSensor(const std::shared_ptr<pros::Rotation>& sensor);

    /**
     * @brief Set the rotation of the sensor
     *
     * @param rotation The rotation of the sensor in radians
     */
    void setRotation(double rotation) final;

    /**
     * @brief Get the rotation of the sensor
     *
     * @return double The current rotation of the sensor in radians
     */
    double getRotation() final;
};
} // namespace hal

#endif