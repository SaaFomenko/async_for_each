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

  template <class It = std::vector<int>::iterator, class T = int, size_t size = 25>
  void async_for_each(It begin, It end, void (*f)(T el))
  {
    size_t cur_size = std::distance(begin, end);
  }
}

int main()
{
  std::vector<double> V{2.5, 3.1, 0.4, 5.0, 10.11};

  my::for_each<std::vector<double>::iterator, double>(V.begin(), V.end(), my::print);
  std::cout << '\n';

  return 0;
}
