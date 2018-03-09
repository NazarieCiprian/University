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
      (not (isMember (cdr l) (car l)))
      (cons (car l) (toSet (cdr l)))
    )
    (
      t
      (toSet (cdr l))
    )
  )
)

(print (toSet '(1 1 1 1 1 2 3)))