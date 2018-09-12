# return_if macro
### Macro
```C++
#if !defined(return_if) || !defined(RETURN_IF)
#define return_if1(expression) \
  do {                         \
    if ((expression)) {        \
      return;                  \
    }                          \
  } while (false)

#define return_if2(expression, value) \
  do {                                \
    if ((expression)) {               \
      return value;                   \
    }                                 \
  } while (false)

#define _ARG2(_0, _1, _2, ...) _2
#define NARG2(...) _ARG2(__VA_ARGS__, 2, 1, 0)

#define _ONE_OR_TWO_ARGS_1(a) return_if1(a)
#define _ONE_OR_TWO_ARGS_2(a, b) return_if2((a), (b))

#define __ONE_OR_TWO_ARGS(N, ...) _ONE_OR_TWO_ARGS_##N(__VA_ARGS__)
#define _ONE_OR_TWO_ARGS(N, ...) __ONE_OR_TWO_ARGS(N, __VA_ARGS__)

#define return_if(...) _ONE_OR_TWO_ARGS(NARG2(__VA_ARGS__), __VA_ARGS__)

#define return_false_if(expression) return_if((expression), false)

#define RETURN_FALSE_IF(expression) return_false_if((expression))

#define RETURN_IF(...) return_if(__VA_ARGS__)
#endif

```
### Usage
```C++

void foo(int a, int b) {
    return_if(a < b);
    // 
    // lot of code
    //
}

std::string bar(bool cond) {
  RETURN_IF(cond, "early return");
  //
  // lot of code
  // 
  return "regular return";
}

bool baz(int n) {
  RETURN_FALSE_IF(n < 2 || n * n > 25);
  //
  //lot of code
  //
  return true;
}

int main() {
  foo(10, 20);
  std::string s = bar(0 == 0);
  bool b = baz(1);
  
  return 0;
}
```
