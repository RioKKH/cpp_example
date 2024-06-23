#include <iostream>
#include <cstddef>

template <typename To, typename From>
To bit_cast(From const &from)
{
    To to;
    memcpy(&to, &from, sizeof(To));
    return to;
}

// void *はアドレスだけを意味するポインター型
// memcpyはvoid *を使うことで、どんなポインターの値でも取れるようにしている

/*
   template <typename Dest, typename Src>
   Dest *memcpy(Dest *dest, Src const *src, std::size_t n);
   としても良かったのだが、C言語からあるものなので、下のようになっている
*/

void *memcpy(void *dest, void *src, std::size_t n)
{
    // destをstd:;byte *型に変換
    auto d = static_cast<std::byte *>(dest);
    // srcをstd:byte const *型に変換する
    auto s = static_cast<std::byte const *>(src);
    // srcからnバイトをコピーするので、nバイト先のアドレスを得る
    auto last = s + n;

    // srcの先頭バイトからnバイトを
    while (s != last)
    {
        *d = *s;
        ++d;
        ++s;
    }

    // destを返す
    return dest;
}
