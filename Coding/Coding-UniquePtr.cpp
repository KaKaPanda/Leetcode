template <typename T>
class MyUniquePtr {
public:
    // 构造函数 explicit
    explicit MyUniquePtr(T* ptr) {
        ptr_ = ptr;
    }

    // 析构函数
    ~MyUniquePtr() {
        delete ptr_;
    }

    // 移动构造函数
    MyUniquePtr(MyUniquePtr&& other) noexcept {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    // 移动赋值运算符
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete _ptr;        // release the old resource
            ptr_ = other.ptr_;  // acquire the new resource
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // 移动赋值运算符 move and swap idiom
    MyUniquePtr& operator=(MyUniquePtr other) noexcept { // 这里不用引用，会调用移动构造函数
        std::swap(ptr_, other.ptr_);
        // std::swap(*this, other) // is also ok
        return *this;
    }
    // 在这里如果要按照常规办法写移动赋值函数，函数体内需要写一堆检查自赋值等冗长的代码。
    // 使用 move-and-swap语义，只用简短的两行就可以写出来。 
    // 在移动赋值函数中 other 是个局部对象，这样在形参传递过来的时候必须要调用拷贝构造函数（这里没有实现则不可调用）或者移动构造函数，
    //（事实上仅限右值可以传进来了）。然后 std::swap 负责把原先的资源和source 进行交换，完成了移动赋值。这样写节省了很多代码，很优雅。
    
    // https://stackoverflow.com/questions/3106110/what-is-move-semantics/11540204#11540204
    // Now that source is a variable of type unique_ptr, it will be initialized by the move constructor; 
    // that is, the argument will be moved into the parameter. The argument is still required to be an rvalue, 
    // because the move constructor itself has an rvalue reference parameter. 
    // When control flow reaches the closing brace of operator=, source goes out of scope, releasing the old resource automatically.

    T* operator->() const {
        return ptr_;
    }

    T& operator*() const {
        return &ptr_;
    }

private:
    T* ptr_;
};