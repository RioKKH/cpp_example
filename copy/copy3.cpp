auto copy = [](auto first, auto last, auto result)
{
    for (auto iter = first; iter != last; ++iter, ++result)
    {
        *result = *iter;
    }
    return result;
};
