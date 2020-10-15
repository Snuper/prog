(mapcar (lambda(x)
(cond
((numberp x)'*)
(t x)
)) '(A B 6 C 7 8 D ))