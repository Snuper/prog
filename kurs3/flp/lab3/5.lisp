(defun pls(x y)
	(if (null x)
      y
      (cons (car x) (pls (cdr x) y))
	)
)

(defun main()
	(defvar x `(l c q p j))
	(defvar y `(a b c))
	(pls x y)
)
(main)