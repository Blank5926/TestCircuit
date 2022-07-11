#pragma once
#include <vector>
#include <optional>
#include <queue>


template <typename T>
class PriorityQueue
{
public:
    std::optional<T> min()
    {
        if (len() == 0)
            return std::nullopt;
        return m_queue.top();
    }
    void pop()
    {
        m_queue.pop();
    }

    size_t len() const noexcept
    {
        return m_queue.size();
    }

    void append(const T& item)
    {
        m_queue.push(item);
    }

private:
    std::priority_queue<T, std::vector<T>, std::greater<T>> m_queue{};
};

