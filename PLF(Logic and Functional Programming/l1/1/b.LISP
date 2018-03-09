(defun check(l e)
  (cond
    (
      (null l)
      nil
    )
    (
      (listp (car l))
      (or (check (car l) e) (check (cdr l) e))
    )
    (
      (eq (car l) e)
      t
    )
    (
      t
      (check (cdr l) e)
    )
  )
)

(print (check '(1 2 (3 4 (6 2) 4) 3 (2 4)) 2))