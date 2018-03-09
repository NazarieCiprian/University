(defun inserte(l e p n)
  (cond
    (
      (null l)
      nil
    )
    (
      (eq p n)
      (cons (car l) (cons e (inserte (cdr l) e (+ p 1) (+ n 2))))
    )
    (
      t
      (cons (car l) (inserte (cdr l) e (+ p 1) n))
    )
  )
)

(print (inserte '(1 2 3 4 5 6 7 8) '10 1 2))