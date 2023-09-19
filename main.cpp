#include <iostream>
#include <future>
#include <vector>


namespace my
{
  template <class It, class T>
  void for_each(It begin, It end, void (*f)(T el))
  {
    for (It i = begin; i != end; ++i)
      f(*i);
  }

  template <typename T>
  void print(T val)
  {
    std::cout << val << ' ';
  }

  template <class It = std::vector<int>::iterator, class T = int, size_t size = 5>
  void async_for_each(It begin, It end, void (*f)(T el))
  {
    size_t cur_size = std::distance(begin, end);
    if (cur_size <= size)
    {
      for_each(begin, end, f);
      return;
    }

    It mid = begin;
    std::advance(mid, cur_size / 2);
    std::future<void> ft = std::async(async_for_each<It, T>, mid, end, f);
    async_for_each(begin, mid, f);
  }
}

int main()
{
  // std::vector<double> V{2.5, 3.1, 0.4, 5.0, 10.11};

  // my::for_each<std::vector<double>::iterator, double>(V.begin(), V.end(), my::print);
  // std::cout << '\n';

  // my::async_for_each<std::vector<double>::iterator, double>(V.begin(), V.end(), my::print);
  // std::cout << '\n';

  const int v_size = 20;

  std::vector<int> v(v_size, 0);

  for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
  {
    *i = std::rand() % v_size;
    std::cout << *i << ' ';
  }
  std::cout << "\n\n";

  my::async_for_each(v.begin(), v.end(), my::print);
  std::cout << '\n'  ;

  return 0;
}
