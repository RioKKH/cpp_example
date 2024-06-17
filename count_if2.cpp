auto count = [](auto first, auto last, auto pred)
{
    auto counter = 0u;
    for (auto i = first; i != last; ++i)
    {
        if (pred(*i) != false)
        {
            ++counter;
        }
        return counter;
    }
};
