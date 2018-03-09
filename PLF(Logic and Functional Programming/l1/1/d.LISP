(defun isMember(l e)
  (cond
    (
      (null l)
      nil
    )
    (
      (eq (car l) e)
      t
    )
    (
      t
      (isMember (cdr l) e)
    )
  )
)

(defun toSet(l)
  (cond
    (
      (null l)
      nil
    )
    (
       (eq (isMember (cdr l) (car l)) nil)
       (cons (car l) (toSet (cdr l)))
    )
    (
      t
      (toSet (cdr l))
    )
 )
)

(print (toSet '(1 2 2 3 4 5 6 6 4 3 )))