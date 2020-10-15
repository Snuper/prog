(defun double(x)
	(if (null x)
		nil
		(cons (car x) (cons (car x) (double (cdr x))))
	)
)

(defun main()
	(defvar x `(1 2 3 4 5))
	
	(write (double x))
)
(main)
