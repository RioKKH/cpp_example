#include <iostream>
#include <complex>
#include <memory>

int main(int argc, char const* argv[])
{
    using cplx = std::complex<double>;

    std::shared_ptr<cplx> p = std::make_shared<cplx>();
    // auto p = std::make_shared<cplx>(); // OK
    std::cout << *p << std::endl; // 出力値(0.0)

    std::shared_ptr<cplx> q = std::make_shared<cplx>(3., 4.);
    // auto p = std::make_shared<cplx>(3., 4.); // OK
    std::cout << *q << std::endl;

    std::shared_ptr<cplx> r = std::make_shared<cplx>(*q);
    // auto r = make_shared<cplx>(3., 4.); // OK
    std::cout << *r << std::endl;
} // *p, *q, *rはここで自動的に解体される
