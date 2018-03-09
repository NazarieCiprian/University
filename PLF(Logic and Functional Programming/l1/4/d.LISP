(defun maxi(l m)
  (cond
    (
      (null l)
      m
    )
    (
      (and (numberp (car l)) (>= (car l) m))
      (maxi (cdr l) (car l))
    )
    (
      (and (numberp (car l)) (< (car l) m))
      (maxi (cdr l) m)
    )
    (
      t
      (maxi (cdr l) m)
    )
 )
)

(print (maxi '(1 2 (3 (4 5) (6 7)) 8 (9 10)) 0))