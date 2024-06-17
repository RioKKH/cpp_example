auto generate = [](auto first, auto last, auto gen)
{
    for (auto iter = first; iter != last; ++iter)
    {
        *iter = gen();
    }
};

auto generate_n = [](auto first, auto n, auto gen)
{
    for (auto iter = first; iter != n; ++iter)
    {
        *iter = gen();
    }
};
