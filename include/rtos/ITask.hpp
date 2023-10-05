#ifndef RTOS_I_TASK_HPP
#define RTOS_I_TASK_HPP

namespace rtos
{
/**
 * @brief Interface for tasks
 *
 * @author Nathan Sandvig
 */
class ITask
{
public:
    /**
     * @brief Destroy the ITask object
     *
     */
    virtual ~ITask() = default;

    /**
     * @brief Removes the ITask from the scheduler
     *
     */
    virtual void remove() = 0;

    /**
     * @brief Suspends the execution of the ITask
     *
     */
    virtual void suspend() = 0;

    /**
     * @brief Resumes the execution of the ITask
     *
     */
    virtual void resume() = 0;

    /**
     * @brief Waits for the ITask to finish execution
     *
     */
    virtual void join() = 0;
};
} // namespace rtos

#endif