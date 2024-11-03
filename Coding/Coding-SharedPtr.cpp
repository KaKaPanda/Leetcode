template <typename T>
class MySharedPtr {
public:
    // 构造函数 explicit
    explicit MySharedPtr(T* ptr) {
        ptr_ = ptr;
        count_ = (ptr)? new size_t(1) : nullptr;
    }

    void release() {
        if (count_ && --(*count_) == 0) {
            delete ptr_;
            delete count_;
        }
    }

    // 析构函数
    ~MySharedPtr() {
        release();
    }

    // 拷贝构造函数
    MySharedPtr(const MySharedPtr& other) {
        ptr_ = other.ptr_;
        count_ = other.count_;
        if (count_) {
            ++(*count_);
        }
    }

    // 赋值运算符
    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();
            ptr_ = other.ptr_;
            count_ = other.count_;
            if (count_) {
                ++(*count_);
            }
        }
        return *this;
    }

private:
    T* ptr_;
    size_t* count_;
};