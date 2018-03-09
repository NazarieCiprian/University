(defun nthe(l n p)
  (cond
    (
      (null l)
      nil
    )
    (
      (eq n p)
      (car l)
    )
    
    (
      t
      (nthe (cdr l) n (+ p 1))
    )
  )
)

(print (nthe '(1 2 a 4 5 6) 3 1)) 