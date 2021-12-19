/*********************************************************
* Author :   xpin-ray
* Date   :   2021/12/19
* License:   Apache License 2.0
*********************************************************/
#pragma once

// choose class type
template<bool Condition, typename TrueClass, typename FalseClass>
class TChooseClass;

template<typename TrueClass, typename FalseClass>
class TChooseClass<true, TrueClass, FalseClass>
{
public:
    using Result = TrueClass;
};

template<typename TrueClass, typename FalseClass>
class TChooseClass<false, TrueClass, FalseClass>
{
public:
    using Result = FalseClass;
};