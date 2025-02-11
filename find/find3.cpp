auto find = [](auto first, auto last, auto const &value)
{
    for (auto iter = first; iter != last; ++iter)
    {
        // 値を発見したらそのイテレータを返す
        if (*iter == value)
        {
            return iter;
        }
        // 値が見つからなければ最後のイテレータを返す
        return last;
    }
};
