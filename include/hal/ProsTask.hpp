#ifndef HAL_PROS_TASK_HPP
#define HAL_PROS_TASK_HPP

#include <memory>

#include "pros/rtos.hpp"

#include "rtos/ITask.hpp"

namespace hal
{
class ProsTask : public rtos::ITask
{
private:
    /**
     * @brief The pros task being adapted to the interface
     *
     */
    std::shared_ptr<pros::Task> m_task{nullptr};

public:
    /**
     * @brief Construct a new Pros Task adapter
     *
     * @param task The task to adapt to the ITask interface
     */
    ProsTask(const std::shared_ptr<pros::Task>& task);

    /**
     * @brief Removes the task from the scheduler
     *
     */
    void remove() final;

    /**
     * @brief Suspends the execution of the task
     *
     */
    void suspend() final;

    /**
     * @brief Resumes the execution of the task
     *
     */
    void resume() final;

    /**
     * @brief Waits for the task to finish execution
     *
     */
    void join() final;
};
} // namespace hal

#endif