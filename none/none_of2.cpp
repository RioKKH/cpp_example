auto none_of = [](auto first, auto last, auto pred)
{
    for (auto iter = first; first != last; ++iter)
    {
        if (pred(*iter))
        {
            return false;
            // 1つでも成り立ったらfalseが返る
        }
    }
    return true;
    // 全てが成り立たないときにtrueが返る。つまりnone_ofである
};
