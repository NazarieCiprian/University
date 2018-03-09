(defun getSub(l)
  (cond
    (
      (null l)
      nil
    )
    (
      (listp (car l))
      (cons (car l) (append (getSub (car l)) (getSub (cdr l))))
    )
    (
      t
      (getSub (cdr l))
    )
  )
)

(print (getSub '(1 2 (3 (4 5) (6 7)) 8 (9 10))))