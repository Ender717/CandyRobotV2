#include "hal/ProsTask.hpp"

namespace hal
{
ProsTask::ProsTask(const std::shared_ptr<pros::Task>& task) : m_task{task}
{

}

void ProsTask::remove()
{
    m_task->remove();
}

void ProsTask::suspend()
{
    m_task->suspend();
}

void ProsTask::resume()
{
    m_task->resume();
}

void ProsTask::join()
{
    m_task->join();
}
} // namespace hal