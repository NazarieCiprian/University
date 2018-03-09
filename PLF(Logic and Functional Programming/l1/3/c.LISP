(defun cmmdc(a b)
  (cond
    (
      (eq b 0)
      a
    )
    (
      t
      (cmmdc b (mod a b))
    )
  )
)

(defun cmmdcl(l)
  (cond
    (
      (null (cdr l))
      (cond
        (
          (listp (car l))
          (cmmdcl (car l))
        )
        (
          t
          (car l)
        )
      )
    )
    (
      (listp (car l))
      (cmmdc (cmmdcl (car l)) (cmmdcl (cdr l)))
    )
    (
      t
      (cmmdc (car l) (cmmdcl (cdr l)))
    )
 )
)

(print (cmmdcl '(42 24 (3 (12 3) (6 3)) 24 (9 30))))
