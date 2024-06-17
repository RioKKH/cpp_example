auto any_of = [](auto first, auto last, auto pred)
{
    for (auto iter = first; first != last; ++iter)
    {
        if (pred(*iter))
        {
            return true;
            // つまり1つでもtrueになればtrueを返す
        }
    }
    return false;
    // つまり全てがfalseの場合にのみfalseを返す
};
