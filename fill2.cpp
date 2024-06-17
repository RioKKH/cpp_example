auto fill_n = [](auto first, auto n, auto value)
{
    for (auto i = 0; i != n; ++i, ++first)
    {
        *first = value;
    }
};
