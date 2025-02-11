auto all_of = [](auto first, auto last, auto pred)
{
    for (auto iter = first; iter != last; ++iter) {
        if (pred(*iter) == false) {
            return false;
            // つまり1つでもfalseであればfalseを返すことになる
        }
    }
    return true;
    // 全てがtrueの場合だけtrueを返す
};
