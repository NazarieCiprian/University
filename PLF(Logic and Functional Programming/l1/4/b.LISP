(defun linear(l)
  (cond
    (
      (null l)
      nil
    )
    (
      (listp (car l))
      (append (linear (car l)) (linear (cdr l)))
    )
    (
      t
      (append (list (car l)) (linear (cdr l)))
    )
  )
)

(print (linear '(((A B) C) (D E))))