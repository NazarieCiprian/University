(defun dotprod(l1 l2)
  (cond
    (
      (or (null l1) (null l2))
      0
    )
    (
      t
      (+ (* (car l1) (car l2)) (dotprod (cdr l1) (cdr l2)))
    )
  )
)

(print (dotprod '(1 2 3) '(1 2 3)))
      