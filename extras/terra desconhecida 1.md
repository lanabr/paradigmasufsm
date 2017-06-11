#### Nome da Região:
std::tuple  
  
#### Explicação da Região:  
É uma generalização de std::pair, um conjunto ordenado de elementos heterogêneos.  
É vista a partir do C++ 11.  
Alguns exemplos de funções: make_tuple, tuple_cat, std::swap.  

#### Exemplo:
``` c++
#include <vector>
#include <tuple>
#include <iostream>

typedef std::tuple<int,int,int> i3tuple;

int main()
{
  std::vector <i3tuple> v;
  for (int i=0; i<10; i++)
  {
    v.push_back(i3tuple(i,i*2, i*2+1) );
  }

  for(i3tuple t: v)
  {
    std::cout << std::get<0>(t) << ' ';
    std::cout << std::get<1>(t) << ' ';
    std::cout << std::get<2>(t) << '\n';
  };
}
```

#### Referências:  
<http://pt.cppreference.com/w/cpp/utility/tuple>  
<http://www.oracle.com/technetwork/articles/servers-storage-dev/c-array-containers-2252536.html>  
