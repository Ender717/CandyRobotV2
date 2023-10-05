#ifndef HAL_PROS_ROTATION_SENSOR_HPP
#define HAL_PROS_ROTATION_SENSOR_HPP

#include <cmath>
#include <memory>

#include "pros/rotation.hpp"

#include "devices/IRotationSensor.hpp"

namespace hal
{
/**
 * @brief Adapter for Pros Rotation Sensors to the IRotationSensor interface
 *
 * @author Nathan Sandvig
 */
class ProsRotationSensor : public devices::IRotationSensor
{
private:
    /**
     * @brief Conversion constant from sensor ticks to radians
     *
     */
    static constexpr double TICKS_PER_RADIAN{18000 / M_PI};

    /**
     * @brief The pros rotation sensor being adapted to the interface
     *
     */
    std::shared_ptr<pros::Rotation> m_sensor{nullptr};

public:
    /**
     * @brief Construct a new PROSRotationSensor adapter
     *
     * @param sensor The sensor to adapt to the IRotationSensor interface
     */
    ProsRotationSensor(const std::shared_ptr<pros::Rotation>& sensor);

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