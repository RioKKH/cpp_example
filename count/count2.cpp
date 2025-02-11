auto count = [](auto first, auto last, auto value)
{
    auto counter = 0u;
    for (auto i = first; i != last; ++i)
    {
        if (*i == value) {
            ++counter;
        }
        return counter;
    }
};
