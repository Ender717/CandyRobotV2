#ifndef DEVICES_I_ROTATION_SENSOR_HPP
#define DEVICES_I_ROTATION_SENSOR_HPP

namespace devices
{
/**
 * @brief Interface for rotation sensors
 *
 * @author Nathan Sandvig
 */
class IRotationSensor
{
public:
    /**
     * @brief Destroy the IRotationSensor object
     *
     */
    virtual ~IRotationSensor() = default;

    /**
     * @brief Set the rotation of the sensor
     *
     * @param rotation The rotation of the sensor in radians
     */
    virtual void setRotation(double rotation) = 0;

    /**
     * @brief Get the rotation of the sensor
     *
     * @return double The current rotation of the sensor in radians
     */
    virtual double getRotation() = 0;
};
} // namespace devices

#endif