#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
using namespace std;

/**
 * @namespace custom
 * @brief Contains custom implementations of standard library-like components
 */
namespace custom
{

/**
     * @class vector
     * @brief Custom implementation of a dynamic array similar to std::vector
     *
     * Provides a resizable array implementation using unique pointers for automatic
     * memory management. Supports common vector operations like push_back, insert,
     * and erase.
     *
     * @tparam T The type of elements stored in the vector
     * @author Omar Farag, Cem Yildiz
     * @date November 2024
     */
template <typename T>
class vector
{
private:
    int size_v;           ///< Number of elements currently in the vector
    int space;            ///< Total allocated capacity
    unique_ptr<T[]> elem; ///< Smart pointer to the array of elements

public:
    /**
         * @brief Default constructor
         *
         * Creates an empty vector with no allocated space
         */
    vector();

    /**
         * @brief Constructor with initial size
         * @param size Initial capacity to allocate
         */
    explicit vector(int size);

    /**
         * @brief Copy constructor
         * @param v Vector to copy from
         */
    vector(const vector &v);

    /**
         * @brief Copy assignment operator
         * @param v Vector to copy from
         * @return Reference to this vector
         */
    vector &operator=(const vector &v);

    /**
         * @brief Move constructor
         * @param v Vector to move from
         */
    vector(vector &&v) noexcept;

    /**
         * @brief Move assignment operator
         * @param v Vector to move from
         * @return Reference to this vector
         */
    vector &operator=(vector &&v) noexcept;

    /**
         * @brief Destructor
         */
    ~vector();

    /**
         * @brief Array subscript operator
         * @param n Index of element to access
         * @return Reference to the element at position n
         */
    T &operator[](int n);

    /**
         * @brief Const array subscript operator
         * @param n Index of element to access
         * @return Const reference to the element at position n
         */
    const T &operator[](int n) const;

    /**
         * @brief Get the current number of elements
         * @return Current size of the vector
         */
    int size() const;

    /**
         * @brief Get the current capacity
         * @return Total allocated space
         */
    int capacity() const;

    /**
         * @brief Resize the vector
         * @param new_size New size for the vector
         */
    void resize(int new_size);

    /**
         * @brief Add an element to the end
         * @param value Element to add
         */
    void push_back(const T &value);

    /**
    * @brief Remove an element from the end
    */
    void pop_back();



    /**
         * @brief Reserve space for future elements
         * @param new_alloc New capacity to allocate
         */
    void reserve(int new_alloc);

    // Iterator type definitions
    using iterator = T *;             ///< Mutable iterator type
    using const_iterator = const T *; ///< Const iterator type

    /**
         * @brief Get iterator to the first element
         * @return Iterator pointing to first element
         */
    iterator begin();

    /**
         * @brief Get const iterator to the first element
         * @return Const iterator pointing to first element
         */
    const_iterator begin() const;

    /**
         * @brief Get iterator to one past the last element
         * @return Iterator pointing past the last element
         */
    iterator end();

    /**
         * @brief Get const iterator to one past the last element
         * @return Const iterator pointing past the last element
         */
    const_iterator end() const;

    /**
         * @brief Insert element at iterator position
         * @param pos Iterator to insertion position
         * @param elem Element to insert
         * @return Iterator to the inserted element
         */
    iterator insert(iterator pos, const T &elem);

    /**
         * @brief Remove element at iterator position
         * @param p Iterator to element to remove
         * @return Iterator to element after the removed one
         */
    iterator erase(iterator p);

    /**
         * @brief Print vector contents (for testing)
         */
    void print() const
    {
        cout << "vector contents:\n";
        for (int i = 0; i < size_v; i++)
        {
            cout << elem[i] << " ";
        }
        cout << endl;
    }
};

template <typename T>
vector<T>::vector()
    : size_v(0), space(0), elem(nullptr)
{
}

template <typename T>
inline vector<T>::vector(int size)
    : size_v(0), elem(make_unique<T[]>(size)), space(size)
{
}

template <typename T>
vector<T>::~vector()
{
}

template <typename T>
vector<T>::vector(const vector &v)
{
    // copy over attributes
    size_v = v.size_v;
    space = v.space;
    // iterate over object v
    elem = make_unique<T[]>(v.size_v);
    for (int i = 0; i < v.size_v; i++)
    {
        elem[i] = v.elem[i];
    }
}

template <typename T>
vector<T>::vector(vector &&v) noexcept
    : size_v(v.size_v), space(v.space), elem(move(v.elem))
{
    // set object v into an empty put valid state
    v.size_v = 0;
    v.space = 0;
    v.elem = nullptr;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) noexcept
{
    // check for self assignment
    if (this == &v)
        return *this;

    // move over attributes
    size_v = v.size_v;
    space = v.space;

    // move over unique pointer
    elem = move(v.elem);
    v.elem = nullptr;

    // leave obj v in an empty but valid state
    v.size_v = 0;
    v.space = 0;

    return *this;
}

template <typename T>
inline T &vector<T>::operator[](int n)
{
    return elem[n];
}

template <typename T>
inline const T &vector<T>::operator[](int n) const
{
    return elem[n];
}

template <typename T>
int vector<T>::size() const
{
    // returns # of elements
    return size_v;
}

template <typename T>
int vector<T>::capacity() const
{
    return space;
}

template <typename T>
void vector<T>::resize(int new_size)
{
    if (new_size > space)
    {
        reserve(new_size);
    }

    // when new_size is larger than size_v then
    // all elements after size_v will be initialized
    if (new_size > size_v)
    {
        for (int i = size_v; i < new_size; i++)
        {
            // initializes new space
            elem[i] = T();
        }
    }

    // update new size
    size_v = new_size;
}

template <typename T>
inline void vector<T>::reserve(int new_alloc)
{
    if (new_alloc > space)
    {
        // make news array of size new_alloc
        unique_ptr<T[]> temp = make_unique<T[]>(new_alloc);

        // iterate over old array to move over data
        for (int i = 0; i < size_v; i++)
        {
            temp[i] = move(elem[i]);
        }
        // then move over
        elem = move(temp);
        space = new_alloc;
    }
    // if the new_alloc size is smaller than the space than nothing
    // needs to be changed
}

template <typename T>
inline void vector<T>::push_back(const T &value)
{
    if (space == size_v)
    {
        // checks if size is 0, if so it will just reserve
        // 1 block of memory
        if (size_v == 0)
        {
            reserve(1);
        }
        // otherwise it will reserve two times the size of size_v
        else
        {
            reserve(size_v * 2);
        }
    }

    // now we assign the value and increase the number of elements
    elem[size_v] = value;
    size_v++;
}

template <typename T>
inline void vector<T>::pop_back()
{
    if (space != 0)
    {
        // decrease the size
        size_v--;
        // make a new array
        auto temp = make_unique<T[]>(size_v);

        // copy over all the elements
        for (int i = 0; i < size_v; i++)
        {
            temp[i] = elem[i];
        }
        // move them back to elem
        elem = move(temp);
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
    return elem.get();
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const
{
    return elem.get();
}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
    return elem.get() + size_v;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const
{
    return elem.get() + size_v;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator p, const T &v)
{
    // Calculate the position index
    int position = p - begin();

    // If we need more space
    if (size_v == space)
    {
        // Double the space (or assign 1 if empty)
        int new_size = (space == 0) ? 1 : space * 2;
        reserve(new_size);
    }

    // Shift elements right to make space
    for (int i = size_v; i > position; i--)
    {
        elem[i] = std::move(elem[i - 1]);
    }

    // Insert new element
    elem[position] = v;
    size_v++;

    // Return iterator to inserted element
    return begin() + position;
}

template <typename T>
typename vector<T>::iterator vector<T>::erase(iterator p)
{
    // Calculate position index
    int position = p - begin();

    // Shift elements left to fill the gap
    for (int i = position; i < size_v - 1; i++)
    {
        elem[i] = std::move(elem[i + 1]);
    }

    // Decrease size
    size_v--;

    // Return iterator to element after erased one
    return begin() + position;
}

} // namespace custom

#endif // VECTOR_H
