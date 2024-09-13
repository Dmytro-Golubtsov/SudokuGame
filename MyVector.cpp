#include <stdexcept>  // Для обработки исключений

template <typename T>
class MyVector {
private:
    T* data;        // Указатель на динамический массив
    size_t size_;   // Текущий размер вектора (количество элементов)
    size_t capacity_; // Вместимость вектора (сколько элементов он может вместить)

    // Метод для увеличения вместимости вектора
    void resizeCapacity(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data[i];  // Копируем элементы в новый массив
        }
        delete[] data;             // Удаляем старый массив
        data = newData;            // Переназначаем указатель на новый массив
        capacity_ = newCapacity;   // Обновляем вместимость
    }

public:
    // Конструктор по умолчанию
    MyVector() : data(nullptr), size_(0), capacity_(0) {}

    // Конструктор с начальной вместимостью
    MyVector(size_t initialCapacity) : size_(0), capacity_(initialCapacity) {
        data = new T[capacity_];
    }

    // Деструктор
    ~MyVector() {
        delete[] data;
    }

    // Конструктор копирования
    MyVector(const MyVector& other) : size_(other.size_), capacity_(other.capacity_) {
        data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    // Оператор присваивания
    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this; // Проверка на самоприсваивание

        delete[] data;  // Очищаем старую память

        size_ = other.size_;
        capacity_ = other.capacity_;
        data = new T[capacity_];

        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // Метод для добавления элемента в конец вектора
    void push_back(const T& value) {
        if (size_ == capacity_) {
            resizeCapacity(capacity_ == 0 ? 1 : capacity_ * 2); // Увеличиваем вместимость в 2 раза
        }
        data[size_++] = value;  // Добавляем элемент и увеличиваем размер
    }

    // Метод для получения элемента по индексу
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Константная версия метода для получения элемента по индексу
    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Метод для удаления последнего элемента
    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    // Возвращает текущий размер вектора
    size_t size() const {
        return size_;
    }

    // Возвращает текущую вместимость вектора
    size_t capacity() const {
        return capacity_;
    }

    // Проверяет, пустой ли вектор
    bool empty() const {
        return size_ == 0;
    }

    // Очищает вектор
    void clear() {
        size_ = 0;
    }
};
