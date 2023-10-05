#ifndef RTOS_I_MUTEX_HPP
#define RTOS_I_MUTEX_HPP

#include <cstdint>

namespace rtos
{
/**
 * @brief Interface for mutexes
 *
 * @author Nathan Sandvig
 */
class IMutex
{
public:
    /**
     * @brief Destroy the IMutex object
     *
     */
    virtual ~IMutex() = default;

    /**
     * @brief
     *
     * @param timeout
     * @return true
     * @return false
     */
    virtual bool take(uint32_t timeout = UINT32_MAX) = 0;

    /**
     * @brief 
     *
     */
    virtual void give() = 0;
};
} // namespace rtos

#endif