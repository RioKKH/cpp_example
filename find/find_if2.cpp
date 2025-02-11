auto find_if = [](auto first, auto last, auto pred)
{
    for (auto iter = first; iter != last; +iter)
    {
        // predがtrueを返した最初のイテレータを返す
        if (pred(*iter)) {
            return iter;
        }
        return last;
    }
};
