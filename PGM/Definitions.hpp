#ifndef DEF_HPP
#define DEF_HPP

#ifdef _DEBUG_
#define ERR(fmt, ...) fprintf(stderr, "\033[31m[%-15.15s:%4u] " fmt "\033[0m\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define DBG(fmt, ...) fprintf(stderr, "\033[33m[%-15.15s:%4u] " fmt "\033[0m\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG(fmt, ...) fprintf(stderr, "[%-15.15s:%4u] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define PRT(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#else
#define ERR(fmt, ...)
#define DBG(fmt, ...)
#define LOG(fmt, ...)
#define PRT(fmt, ...)
#endif

#define TRUE 1
#define FALSE 0

enum class result_t
{
    SUCCESS = 0,
    FAILURE = -1,
};

#endif // DEF_HPP
