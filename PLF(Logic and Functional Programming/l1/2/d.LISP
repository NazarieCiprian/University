(defun intersectie(l1 l2)
  (cond
    (
      (or (null l1) (null l2))
      nil
    )
    (
      (member (car l1) l2)
      (cons (car l1) (intersectie (cdr l1) l2))
    )
    (
      t
      (intersectie (cdr l1) l2)
    )
  )
)

(print (intersectie '(1 2 3 4 5) '(1 2 6)))