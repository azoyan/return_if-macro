#if !defined(return_if)
#define return_if1(expression) \
  do {                         \
    if ((expression)) {        \
      return;                  \
    }                          \
  } while (false)

#define return_if2(expression, value) \
  do {                                \
    if ((expression)) {               \
      return (value);                 \
    }                                 \
  } while (false)

#define _ARG2(_0, _1, _2, ...) _2
#define NARG2(...) _ARG2(__VA_ARGS__, 2, 1, 0)

#define _ONE_OR_TWO_ARGS_1(a) return_if1((a))
#define _ONE_OR_TWO_ARGS_2(a, b) return_if2((a), (b))

#define _ONE_OR_TWO_ARGS_HELP(N, ...) _ONE_OR_TWO_ARGS_##N(__VA_ARGS__)
#define _ONE_OR_TWO_ARGS(N, ...) _ONE_OR_TWO_ARGS_HELP(N, __VA_ARGS__)

#define return_if(...) _ONE_OR_TWO_ARGS(NARG2(__VA_ARGS__), __VA_ARGS__)

#define return_false_if(expression) return_if((expression), false)
#define return_true_if(expression) return_if((expression), true)

#endif
