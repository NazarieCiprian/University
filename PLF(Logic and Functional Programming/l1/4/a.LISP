(defun sumv(l1 l2)
  (cond
    (
      (null l1)
      l2
    )
    (
      (null l2)
      l1
    )
    (
      (and (null l1) (null l2))
      nil
    )
    (
      t
      (cons (+ (car l1) (car l2)) (sumv (cdr l1) (cdr l2)))
    )
  )
)

(print (sumv '(1 2 3) '(1 2 3)))