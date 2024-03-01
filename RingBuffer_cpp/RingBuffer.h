#ifndef DABB69E6_0D87_49E6_90BB_BA84922AEABA
#define DABB69E6_0D87_49E6_90BB_BA84922AEABA
#include <array>

/**
 * @brief A generic ring buffer implementation.
 * @tparam T Type of elements stored in the buffer.
 * @tparam N Capacity of the buffer.
 */
template <typename T, std::size_t N> class RingBuffer {
public:
  /**
   * @brief Resets the ring buffer, clearing all elements.
   */
  void reset() {
    m_head = 0;
    m_tail = 0;
    m_full = false;
  }

  /**
   * @brief Returns the current size of the buffer.
   * @return Size of the buffer.
   */
  size_t size() const {
    size_t size = m_data.size();
    if (!m_full) {
      if (m_head >= m_tail) {
        size = m_head - m_tail;
      } else {
        size = (m_data.size() + m_head - m_tail);
      }
    }
    return size;
  }

  /**
   * @brief Returns the capacity of the buffer.
   * @return Capacity of the buffer.
   */
  size_t capacity() const { return m_data.size(); }

  /**
   * @brief Checks if the buffer is empty.
   * @return True if the buffer is empty, false otherwise.
   */
  bool isEmpty() const { return (!m_full && (m_head == m_tail)); }

  /**
   * @brief Checks if the buffer is full.
   * @return True if the buffer is full, false otherwise.
   */
  bool isFull() const { return m_full; }

  /**
   * @brief Provides a non-const reference to the internal data array.
   * @return Reference to the internal data array.
   */
  std::array<T, N> &data() { return m_data; }

  /**
   * @brief Provides a const reference to the internal data array.
   * @return Const reference to the internal data array.
   */
  const std::array<T, N> &data() const { return m_data; }

  /**
   * @brief Retrieves the element at the tail of the buffer.
   * @return Value at the tail.
   * @details Make sure the buffer is not empty before calling get().
   */
  T get() {
    if (isEmpty()) {
      return T();
    }
    auto element = m_data[m_tail];
    retreadPointer();
    return element;
  }

  /**
   * @brief Pushes a new element to the head of the buffer.
   * @tparam U Type of the new element.
   * @param newValue The new element to be added.
   */
  template <class U> void push(U &&newValue) {
    m_data[m_head] = std::forward<U>(newValue);
    advancePointer();
  }

  /**
   * @brief Attempts to push a new element to the buffer only if it's not full.
   * @tparam U Type of the new element.
   * @param newValue The new element to be added.
   * @return True if the push was successful, false if the buffer is full.
   */
  template <class U> bool savePush(U &&newValue) {
    if (!m_full) {
      push(std::forward<U>(newValue));
      return true;
    }
    return false;
  }

  /**
   * @brief Applies a given function to each element in the buffer.
   * @tparam Func Type of the function to apply.
   * @param func The function to apply to each element.
   */
  template <class Func> void forEach(Func func) const {
    uint32_t currentIdx{m_tail};
    if (m_full) {
      func(m_data[currentIdx]);
      currentIdx = getNextIdx(currentIdx);
    }
    for (; currentIdx != m_head; currentIdx = getNextIdx(currentIdx)) {
      func(m_data[currentIdx]);
    }
  }

private:
  /**
   * @brief Advances the head pointer, handling the buffer full scenario.
   */
  void advancePointer() {
    if (m_full) {
      m_tail = getNextIdx(m_tail);
    }
    m_head = getNextIdx(m_head);
    m_full = (m_head == m_tail);
  }

  /**
   * @brief Moves the tail pointer, marking the buffer as not full.
   */
  void retreadPointer() {
    m_full = false;
    m_tail = getNextIdx(m_tail);
  }

  /**
   * @brief Calculates the next index in a circular manner.
   * @param idx Current index.
   * @return Next index in a circular manner.
   */
  uint32_t getNextIdx(uint32_t idx) const { return (idx + 1) % m_data.size(); }

  std::array<T, N> m_data; ///< Internal array storing the elements.
  uint32_t m_head{0};      ///< Index of the head (newest element).
  uint32_t m_tail{0};      ///< Index of the tail (oldest element).
  bool m_full{false};      ///< Flag indicating whether the buffer is full.
};

#endif /* DABB69E6_0D87_49E6_90BB_BA84922AEABA */
