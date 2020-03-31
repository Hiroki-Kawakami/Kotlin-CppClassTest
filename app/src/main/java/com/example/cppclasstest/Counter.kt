package com.example.cppclasstest

class Counter {

    private var pointer: Long = 0 // C++インスタンスのポインタを保持するフィールド

    var count: Int
    get() = getCountCpp()
    set(value) = setCountCpp(value)
    private external fun getCountCpp(): Int
    private external fun setCountCpp(value: Int)

    external fun description(): String
    external fun increment()

    external fun delete()
    protected fun finalize() = delete()
}